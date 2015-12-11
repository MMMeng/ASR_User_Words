#include "ros/ros.h"
#include "speechrecog/Command.h"
#include "std_msgs/String.h"

#include <stdio.h>
#include <signal.h>
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
#include <linux/input.h>
#include <termios.h>
#include <pthread.h>

#include "wav_parser.h" 
#include "sndwav_common.h"
#include "wav_parser.c"
#include "sndwav_common.c" 

#include "speechrecog/qtts.h"
#include "speechrecog/msp_cmn.h"
#include "speechrecog/msp_errors.h"

typedef int SR_DWORD;
typedef short int SR_WORD ;

const char*  filename = "/home/turtlebot2/ros_ws/bin/wav/text_to_speech.wav";
const char*  shengdange = "/home/turtlebot2/ros_ws/bin/wav/铃儿响叮当.wav";
const char*   xiaopingguo= "/home/turtlebot2/ros_ws/bin/wav/小苹果.wav";

int stop_record = 0;
//音频头部格式
struct wave_pcm_hdr
{
	char            riff[4];                        // = "RIFF"
	SR_DWORD        size_8;                         // = FileSize - 8
	char            wave[4];                        // = "WAVE"
	char            fmt[4];                         // = "fmt "
	SR_DWORD        dwFmtSize;                      // = 下一个结构体的大小 : 16

	SR_WORD         format_tag;              // = PCM : 1
	SR_WORD         channels;                       // = 通道数 : 1
	SR_DWORD        samples_per_sec;        // = 采样率 : 8000 | 6000 | 11025 | 16000
	SR_DWORD        avg_bytes_per_sec;      // = 每秒字节数 : dwSamplesPerSec * wBitsPerSample / 8
	SR_WORD         block_align;            // = 每采样点字节数 : wBitsPerSample / 8
	SR_WORD         bits_per_sample;         // = 量化比特数: 8 | 16

	char            data[4];                        // = "data";
	SR_DWORD        data_size;                // = 纯数据长度 : FileSize - 44 
} ;

//默认音频头部数据
struct wave_pcm_hdr default_pcmwavhdr = 
{
	{ 'R', 'I', 'F', 'F' },
	0,
	{'W', 'A', 'V', 'E'},
	{'f', 'm', 't', ' '},
	16,
	1,
	1,
	16000,
	32000,
	2,
	16,
	{'d', 'a', 't', 'a'},
	0  
};

int text_to_speech(const char* src_text ,const char* des_path ,const char* params)
{
	struct wave_pcm_hdr pcmwavhdr = default_pcmwavhdr;
	const char* sess_id = NULL;
	int ret = -1;
	unsigned int text_len = 0;
	char* audio_data = NULL;
	unsigned int audio_len = 0;
	int synth_status = MSP_TTS_FLAG_STILL_HAVE_DATA;
	FILE* fp = NULL;

	printf("begin to synth...\n");
	if (NULL == src_text || NULL == des_path)
	{
		printf("params is null!\n");
		return ret;
	}
	text_len = (unsigned int)strlen(src_text);
	fp = fopen(des_path,"wb");
	if (NULL == fp)
	{
		printf("open file %s error\n",des_path);
		return ret;
	}
	sess_id = QTTSSessionBegin(params, &ret);
	if ( ret != MSP_SUCCESS )
	{
		printf("QTTSSessionBegin: qtts begin session failed Error code %d.\n",ret);
		return ret;
	}

	ret = QTTSTextPut(sess_id, src_text, text_len, NULL );
	if ( ret != MSP_SUCCESS )
	{
		printf("QTTSTextPut: qtts put text failed Error code %d.\n",ret);
		QTTSSessionEnd(sess_id, "TextPutError");
		return ret;
	}
	fwrite(&pcmwavhdr, sizeof(pcmwavhdr) ,1, fp);
	while (1) 
	{
		const void *data = QTTSAudioGet(sess_id, &audio_len, &synth_status, &ret);
		if (NULL != data)
		{
			fwrite(data, audio_len, 1, fp);
            printf("AudioGet Data: %d\n",audio_len);
		    pcmwavhdr.data_size += audio_len;//修正pcm数据的大小
		}
		if (synth_status == MSP_TTS_FLAG_DATA_END || ret != 0) 
			break;
         usleep(15000);
	}//合成状态synth_status取值可参考开发文档

	//修正pcm文件头数据的大小
	pcmwavhdr.size_8 += pcmwavhdr.data_size + 36;

	//将修正过的数据写回文件头部
	fseek(fp, 4, 0);
	fwrite(&pcmwavhdr.size_8,sizeof(pcmwavhdr.size_8), 1, fp);
	fseek(fp, 40, 0);
	fwrite(&pcmwavhdr.data_size,sizeof(pcmwavhdr.data_size), 1, fp);
	fclose(fp);

	ret = QTTSSessionEnd(sess_id, NULL);
	if ( ret != MSP_SUCCESS )
	{
		printf("QTTSSessionEnd: qtts end failed Error code %d.\n",ret);
	}
	return ret;
}

int run_tts(const char* text)
{
	//APPID请勿随意改动
	const char* login_configs = " appid = 55b1aeb0, work_dir =   .  ";//登录参数
        printf("printing text:%s \n ",text);
	//const char* text  = "科大讯飞是亚太地区最大的语音上市公司，股票代码：002230";//待合成的文本
	//const char*  filename = "/home/turtlebot2/ros_ws/bin/wav/text_to_speech.wav"; //合成的语音文件
	const char* param = "engine_type = local, text_encoding = UTF8, tts_res_path = fo|res/tts/xiaoyan.jet;fo|res/tts/common.jet, sample_rate = 16000";//参数可参考开发文档
	int ret = 0;
	char key = 0;
              
              ret = MSPLogin(NULL, NULL, login_configs);//第一个参数为用户名，第二个参数为密码，第三个参数是登录参数，用户名和密码需要在http://open.voicecloud.cn注册并获取appid
              if ( ret != MSP_SUCCESS )
	{
		printf("MSPLogin failed , Error code %d.\n",ret);
		goto exit ;//登录失败，退出登录
	}
	//音频合成
	ret = text_to_speech(text,filename,param);//音频合成
	if ( ret != MSP_SUCCESS )
	{
		printf("text_to_speech: failed , Error code %d.\n",ret);
		goto exit ;//合成失败，退出登录
	}
exit:
      MSPLogout();//退出登录
	//key = getchar();//退出
	return 0;
}

//////////////////////////////////播放音频/////////////////////////////////////////
    ssize_t SNDWAV_P_SaveRead(int fd, void *buf, size_t count) 
    { 
        ssize_t result = 0, res; 
     
        while (count > 0) { 
            if ((res = read(fd, buf, count)) == 0) 
                break; 
            if (res < 0) 
                return result > 0 ? result : res; 
            count -= res; 
            result += res; 
            buf = (char *)buf + res; 
        } 
        return result; 
    } 
    int readkey()
    {
	fd_set rfds, rs;
	struct timeval tv;

	int i, r, q, j;
	struct termios saveterm, nt;
	int fd = 0;
	unsigned char c, buf[32], str[8];

	tcgetattr(fd, &saveterm);
	nt = saveterm;

	nt.c_lflag &= ~ECHO;
	nt.c_lflag &= ~ISIG;
	nt.c_lflag &= ~ICANON;

	tcsetattr(fd, TCSANOW, &nt);

	FD_ZERO(&rs);
	FD_SET(fd, &rs);
	tv.tv_sec = 0;
	tv.tv_usec = 0;

	i = 0;
	q = 0;
	while (1) {
		read(fd, buf + i, 1);
		//sprintf(str, "<X>", *(buf + i));
                sprintf((char *)str, "<X>",(char *)*(buf + i));
		i++;
		if (i > 31) {
			write(1, "Too many data\n", 14);
			break;
		}
		write(1, str, 4);
		r = select(fd + 1, &rfds, NULL, NULL, &tv);
		if (r < 0) {
			write(1, "select() error.\n", 16);
			break;
		}
		if (r == 1)
			continue;
		//write(1, "\t", 1);
		rfds = rs;
		for (j = 0; j < i; j++) {
			c = buf[j];
			/*
			switch (c) {
			case 27:
				write(1, "ESC ", 4);
				break;
			case 9:
				write(1, "TAB ", 4);
				break;
			case 32:
				write(1, "SPACE ", 6);
				break;
			default:
				if (c >= 32 && c < 127)
					write(1, buf + j, 1);
				else
					write(1, "CTRL ", 5);
				break;
			}*/
		}
		//write(1, "\n", 1);
		if (buf[0] == 3 ) {
			stop_record = 1;
			break;
			/*
			if (q == 0)
				q = 1;
			else
				break;
				*/
		} else
			q = 0;
		i = 0;
	}

	tcsetattr(fd, TCSANOW, &saveterm);
	printf("\n");
	return 0;

}
    void * print_message( void *ptr )
    {
			pthread_detach(pthread_self());//pthread_detach(pthread_self())，将状态改为unjoinable状态，确保资源的释放
			static int g;
			printf("%d\n", g++);
			readkey();
			pthread_exit(0) ;//pthread_exit时自动会被释放

    }
        void SNDWAV_Play(SNDPCMContainer_t *sndpcm, WAVContainer_t *wav, int fd) 
    { 
        int load, ret; 
        off64_t written = 0; 
        off64_t c; 
        off64_t count = LE_INT(wav->chunk.length); 
     
        load = 0; 
        while ((written < count)&&(!stop_record)) { 
            /* Must read [chunk_bytes] bytes data enough. */ 
            do { 
                c = count - written; 
                if (c > sndpcm->chunk_bytes) 
                    c = sndpcm->chunk_bytes; 
                c -= load; 
     
                if (c == 0) 
                    break; 
                ret = SNDWAV_P_SaveRead(fd, sndpcm->data_buf + load, c); 
                if (ret < 0) { 
                    fprintf(stderr, "Error safe_read/n"); 
                    exit(-1); 
                } 
                if (ret == 0) 
                    break; 
                load += ret; 
            } while ((size_t)load < sndpcm->chunk_bytes); 
     
            /* Transfer to size frame */ 
            load = load * 8 / sndpcm->bits_per_frame; 
            ret = SNDWAV_WritePcm(sndpcm, load); 
            if (ret != load) 
                break; 
             
            ret = ret * sndpcm->bits_per_frame / 8; 
            written += ret; 
            load = 0; 
        } 
    }

int run_wav_play(const char* filename)
{
	 //char *filename; 
               char *devicename = "default"; 
               int fd; 
               WAVContainer_t wav; 
               SNDPCMContainer_t playback;

          pthread_t thread_id;
          pthread_create( &thread_id, NULL, print_message, (void *)NULL );// 一个线程默认的状态是joinable
               memset(&playback, 0x0, sizeof(playback)); 
               fd = open(filename, O_RDONLY);
               if (fd < 0) { 
               fprintf(stderr, "Error open [%s]/n", filename); 
               return -1; 
               }

              if (WAV_ReadHeader(fd, &wav) < 0) { 
               fprintf(stderr, "Error WAV_Parse [%s]/n", filename); 
                goto Err; 
                } 

               if (snd_output_stdio_attach(&playback.log, stderr, 0) < 0) {
               fprintf(stderr, "Error snd_output_stdio_attach/n"); 
               goto Err; 
                }

               if (snd_pcm_open(&playback.handle, devicename, SND_PCM_STREAM_PLAYBACK, 0) < 0) { 
               fprintf(stderr, "Error snd_pcm_open [ %s]/n", devicename); 
               goto Err; 
               }

               if (SNDWAV_SetParams(&playback, &wav) < 0) { 
               fprintf(stderr, "Error set_snd_pcm_params/n"); 
               goto Err; 
               } 

               snd_pcm_dump(playback.handle, playback.log); 

               SNDWAV_Play(&playback, &wav, fd);
                
               snd_pcm_drain(playback.handle);
               

               close(fd); 
               free(playback.data_buf); 
               snd_output_close(playback.log); 
               snd_pcm_close(playback.handle); 
               return 0; 
  Err:
               close(fd); 
               if (playback.data_buf) free(playback.data_buf); 
               if (playback.log) snd_output_close(playback.log); 
               if (playback.handle) snd_pcm_close(playback.handle); 
               return -1;
 }

//////////////////////////////////播放音频/////////////////////////////////////////

int main(int argc, char **argv)
{
	ros::init(argc, argv, "trigger");
	ros::NodeHandle n;
        ros::ServiceClient client = n.serviceClient<speechrecog::Command>("command_recognize");
        speechrecog::Command srv;
        srv.request.num=0;//默认将其设置为0，以触发server服务；



              if (srv.request.num== 0)
              {
              	if (client.call(srv))
              	{
              		                   ROS_INFO("Success to call service user_command!");
                                           printf("The recognition result is: %s \n",srv.response.command.c_str());
                                           const char* text;
                                           text=srv.response.command.c_str();
                                           printf("%s\n", text);
                                           run_tts(text);
                                           run_wav_play(filename);
                                           const char* flag1;
                                           const char* flag2;
                                           flag1="圣诞歌";
                                           flag2="小苹果";
                                           if (strstr(text,flag1)){
                                               run_wav_play(shengdange);
                                            }
                                           else if(strstr(text,flag2)){
                                               run_wav_play(xiaopingguo);
                                           } 
                                           printf("\n请求服务完毕!\n");
                 }
              	else
              	{
              		ROS_ERROR("Failed to call service user_command");
	                             return 1;
              	}
              }
              else
              {
              	ROS_INFO("Failed to trigger the service, Please set the requeset.num = 0 !");
              }

	return 0;
}
