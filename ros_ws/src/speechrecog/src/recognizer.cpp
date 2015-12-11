#include "ros/ros.h"
#include "std_msgs/String.h"
#include "speechrecog/Command.h"

#include "speechrecog/qisr.h"
#include "speechrecog/msp_cmn.h"
#include "speechrecog/msp_errors.h"
#include "speechrecog/msp_types.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

#include <stdio.h> 
#include <malloc.h> 
#include <unistd.h> 
#include <stdlib.h> 
#include <string.h> 
#include <getopt.h> 
#include <fcntl.h> 
#include <ctype.h> 
#include <errno.h> 
#include <limits.h> 
#include <time.h> 
#include <locale.h> 
#include <sys/unistd.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <alsa/asoundlib.h> 
#include <assert.h> 
#include "wav_parser.h" 
#include "wav_parser.c"
#include "sndwav_common.h"
#include "sndwav_common.c" 

#define DEFAULT_CHANNELS         (1) 
#define DEFAULT_SAMPLE_RATE      (8000) 
#define DEFAULT_SAMPLE_LENGTH    (16) 
#define DEFAULT_DURATION_TIME    (5) //默认时长5s 

#define SAMPLE_RATE_16K     (16000)
#define SAMPLE_RATE_8K      (8000)
#define MAX_GRAMMARID_LEN   (32)
#define MAX_PARAMS_LEN      (1024)

const char * ASR_RES_PATH        = "fo|res/asr/common.jet"; //离线语法识别资源路径
const char * GRM_BUILD_PATH      = "res/asr/GrmBuilld"; //构建离线语法识别网络生成数据保存路径
const char * GRM_FILE            = "/home/turtlebot2/ros_ws/bin/command.bnf"; //构建离线识别语法网络所用的语法文件

char * filename="/home/turtlebot2/ros_ws/bin/wav/recordfile.wav";
const char *rec_rslt = NULL;
bool flag1=false;
bool flag2=false;
const char* tmpt1="圣诞歌";
const char* tmpt2="小苹果";
      
         
typedef struct _UserData {
	int     build_fini; //标识语法构建是否完成
	int     update_fini; //标识更新词典是否完成
	int     errcode; //记录语法构建或更新词典回调错误码
	char    grammar_id[MAX_GRAMMARID_LEN]; //保存语法构建返回的语法ID
}UserData;

const char *get_audio_file(void); //选择进行离线语法识别的语音文件
int build_grammar(UserData *udata); //构建离线识别语法网络
int run_asr(UserData *udata); //进行离线语法识别
int SNDWAV_PrepareWAVParams(WAVContainer_t *wav) ;
void SNDWAV_Record(SNDPCMContainer_t *sndpcm, WAVContainer_t *wav, int fd);
int record();//录音
/////////////////////////////录音代码///////////////////////////
 int SNDWAV_PrepareWAVParams(WAVContainer_t *wav) 
    { 
        assert(wav); 
     	//硬件参数赋值
        uint16_t channels = DEFAULT_CHANNELS; 
        uint16_t sample_rate = DEFAULT_SAMPLE_RATE; 
        uint16_t sample_length = DEFAULT_SAMPLE_LENGTH; 
        uint32_t duration_time = DEFAULT_DURATION_TIME; 
     
        wav->header.magic = WAV_RIFF; 
        wav->header.type = WAV_WAVE; 
        wav->format.magic = WAV_FMT; 
        wav->format.fmt_size = LE_INT(16); 
        wav->format.format = LE_SHORT(WAV_FMT_PCM); 
        wav->chunk.type = WAV_DATA; 
     
        //自定义 
        wav->format.channels = LE_SHORT(channels); 
        wav->format.sample_rate = LE_INT(sample_rate); 
        wav->format.sample_length = LE_SHORT(sample_length); 
     
    wav->format.blocks_align = LE_SHORT(channels * sample_length / 8); 
    wav->format.bytes_p_second = LE_INT((uint16_t)(wav->format.blocks_align) * sample_rate); 
         
    wav->chunk.length = LE_INT(duration_time * (uint32_t)(wav->format.bytes_p_second)); 
    wav->header.length = LE_INT((uint32_t)(wav->chunk.length) + sizeof(wav->chunk) + sizeof(wav->format) + sizeof(wav->header) - 8); 
     
        return 0; 
    } 

void SNDWAV_Record(SNDPCMContainer_t *sndpcm, WAVContainer_t *wav, int fd) 
    { 
        off64_t rest; 
        size_t c, frame_size; 
         
        if (WAV_WriteHeader(fd, wav) < 0) { 
            exit(-1); 
        } 
     
        rest = wav->chunk.length; 
        while (rest > 0) { 
            c = (rest <= (off64_t)sndpcm->chunk_bytes) ? (size_t)rest : sndpcm->chunk_bytes; 
            frame_size = c * 8 / sndpcm->bits_per_frame; 
            if (SNDWAV_ReadPcm(sndpcm, frame_size) != frame_size) 
                break; 
             
            if (write(fd, sndpcm->data_buf, c) != c) { 
                fprintf(stderr, "Error SNDWAV_Record[write]/n"); 
                exit(-1); 
            } 
     
            rest -= c; 
        } 
    }
 int record()
{
      char *devicename = "default"; 
        int fd; 
        WAVContainer_t wav; 
        SNDPCMContainer_t record; 
         
        memset(&record, 0x0, sizeof(record)); 
     
        remove(filename); 
        if ((fd = open(filename, O_WRONLY | O_CREAT, 0644)) == -1) { 
            fprintf(stderr, "Error open: [%s]/n", filename); 
            return false; 
        } 
     
        if (snd_output_stdio_attach(&record.log, stderr, 0) < 0) { 
            fprintf(stderr, "Error snd_output_stdio_attach/n"); 
            goto Err; 
        } 
     
        if (snd_pcm_open(&record.handle, devicename, SND_PCM_STREAM_CAPTURE, 0) < 0) { 
            fprintf(stderr, "Error snd_pcm_open [ %s]/n", devicename); 
            goto Err; 
        } 
     
        if (SNDWAV_PrepareWAVParams(&wav) < 0) { 
            fprintf(stderr, "Error SNDWAV_PrepareWAVParams/n"); 
            goto Err; 
        } 
     
        if (SNDWAV_SetParams(&record, &wav) < 0) { 
            fprintf(stderr, "Error set_snd_pcm_params/n"); 
            goto Err; 
        } 
        snd_pcm_dump(record.handle, record.log); 
     
        SNDWAV_Record(&record, &wav, fd); 
     
        snd_pcm_drain(record.handle); 
     
        close(fd); 
        free(record.data_buf); 
        snd_output_close(record.log); 
        snd_pcm_close(record.handle); 
        return true; 
     
    Err: 
        close(fd); 
        remove(filename); 
        if (record.data_buf) free(record.data_buf); 
        if (record.log) snd_output_close(record.log); 
        if (record.handle) snd_pcm_close(record.handle); 
        return false; 
} 


/////////////////////////////录音代码///////////////////////////
const char* get_audio_file(void)
{
	char key = 0;
	while(key != 27) //按Esc则退出
	{
		printf("请选择音频文件：\n");
		printf("1.打电话给丁伟\n");
		printf("2.打电话给黄辣椒\n");
		key = getchar();
		getchar();
		switch(key)
		{
		case '1':
			printf("\n1.打电话给丁伟\n");
			return "/home/turtlebot2/ros_ws/bin/wav/ddhgdw.pcm";
		case '2':
			printf("\n2.打电话给黄辣椒\n");
			return "/home/turtlebot2/ros_ws/bin/wav/ddhghlj.pcm";
		default:
			continue;
		}
	}
	exit(0);
	return NULL;
}
int build_grm_cb(int ecode, const char *info, void *udata)
{
	UserData *grm_data = (UserData *)udata;

	if (NULL != grm_data) {
		grm_data->build_fini = 1;
		grm_data->errcode = ecode;
	}

	if (MSP_SUCCESS == ecode && NULL != info) {
		printf("构建语法成功！ 语法ID:%s\n", info);
		if (NULL != grm_data)
			snprintf(grm_data->grammar_id, MAX_GRAMMARID_LEN - 1, info);
	}
	else
		printf("构建语法失败！%d\n", ecode);

	return 0;
}
int build_grammar(UserData *udata)
{
	FILE *grm_file                           = NULL;
	char *grm_content                        = NULL;
	unsigned int grm_cnt_len                 = 0;
	char grm_build_params[MAX_PARAMS_LEN]    = {NULL};
	int ret                                  = 0;

	grm_file = fopen(GRM_FILE, "rb");	
	if(NULL == grm_file) {
		printf("打开\"%s\"文件失败！[%s]\n", GRM_FILE, strerror(errno));
		return -1; 
	}

	fseek(grm_file, 0, SEEK_END);
	grm_cnt_len = ftell(grm_file);
	fseek(grm_file, 0, SEEK_SET);

	grm_content = (char *)malloc(grm_cnt_len + 1);
	if (NULL == grm_content)
	{
		printf("内存分配失败!\n");
		fclose(grm_file);
		grm_file = NULL;
		return -1;
	}
	fread((void*)grm_content, 1, grm_cnt_len, grm_file);
	grm_content[grm_cnt_len] = '\0';
	fclose(grm_file);
	grm_file = NULL;

	snprintf(grm_build_params, MAX_PARAMS_LEN - 1, 
		"engine_type = local, \
		asr_res_path = %s, sample_rate = %d, \
		grm_build_path = %s, ",
		ASR_RES_PATH,
		SAMPLE_RATE_16K,
		GRM_BUILD_PATH
		);
	ret = QISRBuildGrammar("bnf", grm_content, grm_cnt_len, grm_build_params, build_grm_cb, udata);

	free(grm_content);
	grm_content = NULL;

	return ret;
}

int run_asr(UserData *udata)
{
	char asr_params[MAX_PARAMS_LEN]    = {NULL};
	//const char *rec_rslt               = NULL;
	const char *session_id             = NULL;
	//const char *asr_audiof             = NULL;
	FILE *f_pcm                        = NULL;
	char *pcm_data                     = NULL;
	long pcm_count                     = 0;
	long pcm_size                      = 0;
	int last_audio                     = 0;
	int aud_stat                       = MSP_AUDIO_SAMPLE_CONTINUE;
	int ep_status                      = MSP_EP_LOOKING_FOR_SPEECH;
	int rec_status                     = MSP_REC_STATUS_INCOMPLETE;
	int rss_status                     = MSP_REC_STATUS_INCOMPLETE;
	int errcode                        = -1;

	
        if (record())
           printf("Finish recording!!\n");
        else
           {
            printf("Fail to record!\n");
            return 1;
           }
         
       // asr_audiof = filename;
	f_pcm = fopen(filename, "rb");
	if (NULL == f_pcm) {
		printf("打开\"%s\"失败！[%s]\n", f_pcm, strerror(errno));
		goto run_error;
	}
	fseek(f_pcm, 0, SEEK_END);
	pcm_size = ftell(f_pcm);
	fseek(f_pcm, 0, SEEK_SET);
	pcm_data = (char *)malloc(pcm_size);
	if (NULL == pcm_data)
		goto run_error;
	fread((void *)pcm_data, pcm_size, 1, f_pcm);
	fclose(f_pcm);
	f_pcm = NULL;

	//离线语法识别参数设置
	snprintf(asr_params, MAX_PARAMS_LEN - 1, 
		"engine_type = local, \
		asr_res_path = %s, sample_rate = %d, \
		grm_build_path = %s, local_grammar = %s, \
		result_type = xml, result_encoding = utf-8, ",
		ASR_RES_PATH,
		SAMPLE_RATE_16K,
		GRM_BUILD_PATH,
		udata->grammar_id
		);
	session_id = QISRSessionBegin(NULL, asr_params, &errcode);
	if (NULL == session_id)
		goto run_error;
	printf("开始识别...\n");

	while (1) {
		unsigned int len = 6400;

		if (pcm_size < 12800) {
			len = pcm_size;
			last_audio = 1;
		}

		aud_stat = MSP_AUDIO_SAMPLE_CONTINUE;

		if (0 == pcm_count)
			aud_stat = MSP_AUDIO_SAMPLE_FIRST;

		if (len <= 0)
			break;

		printf(">");
		fflush(stdout);
		errcode = QISRAudioWrite(session_id, (const void *)&pcm_data[pcm_count], len, aud_stat, &ep_status, &rec_status);
		if (MSP_SUCCESS != errcode)
			goto run_error;

		pcm_count += (long)len;
		pcm_size -= (long)len;

		//检测到音频结束
		if (MSP_EP_AFTER_SPEECH == ep_status)
			break;

		usleep(150 * 1000); //模拟人说话时间间隙
	}
	//主动点击音频结束
	QISRAudioWrite(session_id, (const void *)NULL, 0, MSP_AUDIO_SAMPLE_LAST, &ep_status, &rec_status);

	free(pcm_data);
	pcm_data = NULL;

	//获取识别结果
	while (MSP_REC_STATUS_COMPLETE != rss_status && MSP_SUCCESS == errcode) {
		rec_rslt = QISRGetResult(session_id, &rss_status, 0, &errcode);
		usleep(150 * 1000);
	}
	printf("\n识别结束：\n");
	printf("=============================================================\n");
	if (NULL != rec_rslt)
             {
	 printf("%s\n", rec_rslt);

               if(strstr(rec_rslt,tmpt1))
                    flag1=true;
               else if (strstr(rec_rslt,tmpt2))
                    flag2=true;
             }
	else
	      printf("没有识别结果！\n");
	printf("=============================================================\n");

	goto run_exit;

run_error:
	if (NULL != pcm_data) {
		free(pcm_data);
		pcm_data = NULL;
	}
	if (NULL != f_pcm) {
		fclose(f_pcm);
		f_pcm = NULL;
	}
run_exit:
	QISRSessionEnd(session_id, NULL);
	return errcode;
}

bool asr(speechrecog::Command::Request  &req,
         speechrecog::Command::Response &res)
{
	const char *login_config    = "appid = 55b1aeb0"; //登录参数
	UserData asr_data; 
	int ret                     = 0 ;
	char c;

	ret = MSPLogin(NULL, NULL, login_config); //第一个参数为用户名，第二个参数为密码，传NULL即可，第三个参数是登录参数
	if (MSP_SUCCESS != ret) {
		printf("登录失败：%d\n", ret);
		goto exit;
	}

	memset(&asr_data, 0, sizeof(UserData));
	printf("构建离线识别语法网络...\n");
	ret = build_grammar(&asr_data);  //第一次使用某语法进行识别，需要先构建语法网络，获取语法ID，之后使用此语法进行识别，无需再次构建
	if (MSP_SUCCESS != ret) {
		printf("构建语法调用失败！\n");
		goto exit;
	}
	while (1 != asr_data.build_fini)
		usleep(300 * 1000);
	if (MSP_SUCCESS != asr_data.errcode)
		goto exit;
	printf("离线识别语法网络构建完成，开始识别...\n");	
	ret = run_asr(&asr_data);
	if (MSP_SUCCESS != ret) {
		printf("离线语法识别出错: %d \n", ret);
		goto exit;
	}

/////////////////////////////将识别结果rec_rslt传递给trigger//////////////////////////////////////////

         res.command=rec_rslt;
         if(flag1)
           res.command=tmpt1;
         if(flag2)
           res.command=tmpt2;
  

exit:
	MSPLogout();
	return true;

}
int  main(int argc, char **argv)
{
	ros::init(argc, argv, "recognizer");
	ros::NodeHandle n;
	ros::ServiceServer service = n.advertiseService("command_recognize", asr);

	ros::spin();
	return 0;
}
