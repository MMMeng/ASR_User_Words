//备份：ros下iat成功运行代码
#include "ros/ros.h"
#include "asr_usercommand/UserCommand.h"
#include "std_msgs/String.h"
#include "asr_usercommand/Command.h"

#include "asr_usercommand/qisr.h"
#include "asr_usercommand/msp_cmn.h"
#include "asr_usercommand/msp_errors.h"
#include "asr_usercommand/msp_types.h"

#include <dlfcn.h>
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
#include "sndwav_common.h"

#include "wav_parser.c"
#include "sndwav_common.c"
     
#define DEFAULT_CHANNELS         (1) 
#define DEFAULT_SAMPLE_RATE      (8000) 
#define DEFAULT_SAMPLE_LENGTH    (16) 
#define DEFAULT_DURATION_TIME    (10) 

char rec_result[1024*4] = {0};
char * filename="/home/turtlebot2/ros_ws/src/asr_usercommand/wav/recordfile.wav";
char * filename1="/home/turtlebot2/ros_ws/src/asr_usercommand/wav/过来.wav";
const char*  get_audio_file(int num)
{
	int key = num;
	while(true)//按Esc则退出
	{           
		switch(key)
		{
		case 1:
                         return "/home/turtlebot2/asr_ws/src/asr_usercommand/wav/过来.wav"; 
		case 2:
                         return "/home/turtlebot2/asr_ws/src/asr_usercommand/wav/黄山旅游.wav"; 
		case 3:
                         return "/home/turtlebot2/asr_ws/src/asr_usercommand/wav/南京高科.wav";
		case 4:
                         return "/home/turtlebot2/asr_ws/src/asr_usercommand/wav/机器人.wav";
                case 5:
                         return "/home/turtlebot2/asr_ws/src/asr_usercommand/wav/前进.wav";
                case 6:
                         return "/home/turtlebot2/asr_ws/src/asr_usercommand/wav/向左转.wav";
		default:
			continue;
		}
	}
	exit(0);
	return NULL;
}

void run_iat(const char* src_wav_filename ,  const char* param)
{
	
	const char *sessionID;
	FILE *f_pcm = NULL;
	char *pPCM = NULL;
	int lastAudio = 0 ;
	int audStat = 2 ;
	int epStatus = 0;
	int recStatus = 0 ;
	long pcmCount = 0;
	long pcmSize = 0;
	int errCode = 10 ;
	sessionID = QISRSessionBegin(NULL, param, &errCode);//开始一路会话
    if (errCode !=0)
	{
	    printf("QISRSessionBegin Failed,errCode=%d\n",errCode);
	}
	f_pcm = fopen(src_wav_filename, "rb");
	if (NULL != f_pcm) {
		fseek(f_pcm, 0, SEEK_END);
		pcmSize = ftell(f_pcm);//返回文件的长度
		fseek(f_pcm, 0, SEEK_SET);
		pPCM = (char *)malloc(pcmSize);
		fread((void *)pPCM, pcmSize, 1, f_pcm);
		fclose(f_pcm);
		f_pcm = NULL;
	}//读取音频文件
	while (1) {
		unsigned int len = 6400;
                         int ret = 0;
		if (pcmSize < 12800) {
			len = pcmSize;
			lastAudio = 1;//音频长度小于12800
		}
		audStat = 2;//有后继音频
		if (pcmCount == 0)
			audStat = 1;
		if (len<=0)
		{
			break;
		}
		printf("\ncsid=%s,count=%d,aus=%d,",sessionID,pcmCount/len,audStat);
		ret = QISRAudioWrite(sessionID, (const void *)&pPCM[pcmCount], len, audStat, &epStatus, &recStatus);//写音频
		printf("eps=%d,rss=%d,ret=%d",epStatus,recStatus,ret);
		if (ret != 0)
			break;
		pcmCount += (long)len;
		pcmSize -= (long)len;
		if (recStatus == 0) {
			const char *rslt = QISRGetResult(sessionID, &recStatus, 0, &ret);
			if (ret != MSP_SUCCESS)
			{
				printf("QISRGetResult Failed,ret=%d\n",ret);
				break;
			}
			if (NULL != rslt)
				{
                                 strcat(rec_result,rslt);
                                }
		}
		if (epStatus == MSP_EP_AFTER_SPEECH)//MSP_EP_AFTER_SPEECH=3,表示检测到音频的后端点，后继的音频会被MSC忽略
			break;
		usleep(150000);//模拟人说话时间间隙，把进程挂起一段时间，单位是微秒（百万分之一秒）；_sleep(),单位是毫秒，（千分之一秒）
	}
	errCode=QISRAudioWrite(sessionID, (const void *)NULL, 0, 4, &epStatus, &recStatus);//"4"代表MSP_AUDIO_SAMPLE=4,表示最后一块音频；用来指名当前的音频已经发送完毕；
	if (errCode !=0)
	{
		printf("QISRAudioWrite Failed,ret=%d\n",errCode);
	}
	free(pPCM);
	pPCM = NULL;
	while (recStatus != 5 && errCode == 0) {
		const char *rslt = QISRGetResult(sessionID, &recStatus, 0, &errCode);//获取结果
		if (NULL != rslt)
		{
		       strcat(rec_result,rslt);
		}
		usleep(150000);
	}
        errCode=QISRSessionEnd(sessionID, NULL);
	if(errCode !=MSP_SUCCESS)
	{
		printf("QISRSessionEnd Failed, errCode=%d\n",errCode);
	}

	printf("\n=============================================================\n");
	printf("The result is: %s\n",rec_result);
	printf("=============================================================\n");
	//usleep(100);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
         
        if (WAV_WriteHeader(fd, wav) < 0)
        { 
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
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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

bool asr_command(asr_usercommand::UserCommand::Request  &req,
         asr_usercommand::UserCommand::Response &res)
{
  const char* login_config = "appid = 55b1aeb0, work_dir =   .  ";
  const char* param1 = "sub=iat,ssm=1,auf=audio/L16;rate=16000,aue=speex-wb,ent=sms16k,rst=plain,rse=utf8";//直接转写，默认编码为gb2312，可以通过rse参数指定为utf8或unicode,16k音频aue=speex-wb，8k音频识别aue=speex，
  const char* param2 = "sub=iat,ssm=1,auf=audio/L16;rate=16000,aue=speex-wb,ent=sms16k,rst=json,rse=utf8";//转写为json格式，编码只能为utf8
  int ret = 0 ;
   //用户登录
  ret = MSPLogin(NULL, NULL, login_config);
  if ( ret != MSP_SUCCESS )
  {
	printf("MSPLogin failed , Error code %d.\n",ret);
  }
  ROS_INFO("Your request command number is:%ld",(long int)req.num);

  if(record())
    printf("Finish the record process!!\n");
  else
    {
     printf("Fail to record!\n");
     return false;
    }
        
//////////////////////启动录音结束///////////////////////////////////////////////////////////////////////////////////
  run_iat(filename,param1);//这里调用识别！！！！

  //识别结果给response.command;
  res.command=rec_result;
  ros::NodeHandle n;
  ros::Publisher command_pub = n.advertise<asr_usercommand::Command>("command", 1000);
  ros::Rate loop_rate(5);
  //把response publish出去
  int count=1;
  int jishu=5;
   while(jishu>0)
  {
    if(ros::ok())
      {
	   asr_usercommand::Command msg;
	   msg.command=res.command;
           //printf("%d   ",count);
	   printf("%s\n", msg.command.c_str());
	   command_pub.publish(msg);
           //printf("finish one time publish\n");
	   ros::spinOnce();
	   loop_rate.sleep();
	   ++count; 
      }
   --jishu;
  }
  //退出登录
  MSPLogout();
  memset(rec_result,0,sizeof(rec_result));//清空rec_result[]
  return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "user_command_server");
  ros::NodeHandle n;
  ros::ServiceServer service = n.advertiseService("user_command", asr_command);
  

  ros::spin();
 
  return 0;
}
