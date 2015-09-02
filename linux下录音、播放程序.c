#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <stdio.h>
#include <linux/soundcard.h>
#include <termios.h>


#define LENGTH    10   //录音时间,秒
#define RATE    88200 //采样频率
#define SIZE    16   //量化位数
#define CHANNELS 2   //声道数目
#define RSIZE    8    //buf的大小，


/********以下是wave格式文件的文件头格式说明******/
/*------------------------------------------------
|             RIFF WAVE Chunk                  |
|             ID = 'RIFF'                     |
|             RiffType = 'WAVE'                |
------------------------------------------------
|             Format Chunk                     |
|             ID = 'fmt '                      |
------------------------------------------------
|             Fact Chunk(optional)             |
|             ID = 'fact'                      |
------------------------------------------------
|             Data Chunk                       |
|             ID = 'data'                      |
------------------------------------------------*/
/**********以上是wave文件格式头格式说明***********/
/*wave 文件一共有四个Chunk组成，其中第三个Chunk可以省略，每个Chunk有标示（ID）,
大小（size,就是本Chunk的内容部分长度）,内容三部分组成*/
struct fhead
{
 /****RIFF WAVE CHUNK*/
 unsigned char a[4];//四个字节存放'R','I','F','F'
 long int b;        //整个文件的长度-8;每个Chunk的size字段，都是表示除了本Chunk的ID和SIZE字段外的长度;
 unsigned char c[4];//四个字节存放'W','A','V','E'
 /****RIFF WAVE CHUNK*/
 /****Format CHUNK*/
 unsigned char d[4];//四个字节存放'f','m','t',''
 long int e;       //16后没有附加消息，18后有附加消息；一般为16，其他格式转来的话为18
 short int f;       //编码方式，一般为0x0001;
 short int g;       //声道数目，1单声道，2双声道;
 long int h;        //采样频率;
 long int i;        //每秒所需字节数;
 short int j;       //每个采样需要多少字节，若声道是双，则两个一起考虑;
 short int k;       //即量化位数
 /****Format CHUNK*/
 /***Data Chunk**/
    unsigned char p[4];//四个字节存放'd','a','t','a' 
 long int q;        //语音数据部分长度，不包括文件头的任何部分
}wavehead;//定义WAVE文件的文件头结构体

int main(void)
{
 /*以下wave 文件头赋值*/
 wavehead.a[0]='R';
 wavehead.a[1]='I';
 wavehead.a[2]='F';
 wavehead.a[3]='F';
 wavehead.b=LENGTH*RATE*CHANNELS*SIZE/8-8;
 wavehead.c[0]='W';
 wavehead.c[1]='A';
 wavehead.c[2]='V';
 wavehead.c[3]='E';
 wavehead.d[0]='f';
 wavehead.d[1]='m';
 wavehead.d[2]='t';
 wavehead.d[3]=' ';
 wavehead.e=16;
 wavehead.f=1;
 wavehead.g=CHANNELS;
 wavehead.h=RATE;
 wavehead.i=RATE*CHANNELS*SIZE/8;
 wavehead.j=CHANNELS*SIZE/8;
 wavehead.k=SIZE;
 wavehead.p[0]='d';
 wavehead.p[1]='a';
 wavehead.p[2]='t';
 wavehead.p[3]='a';
 wavehead.q=LENGTH*RATE*CHANNELS*SIZE/8;
 /*以上wave 文件头赋值*/
  
 int i;
 unsigned char buf[RSIZE]; //每次循环取得RSIZE大小的容量，放入buf，然后写入文件；放音是相反。
  
 //打开声卡设备，只读方式；并对声卡进行设置
 int fd_dev_r= open("/dev/dsp", O_RDONLY,0777);
 if (fd_dev_r < 0) 
 {
    perror("Cannot open /dev/dsp device");
    return 1;
 }
 
 int arg = SIZE;
 if (ioctl(fd_dev_r, SOUND_PCM_WRITE_BITS, &arg) == -1)    //设置量化位数   
 {
        perror("Cannot set SOUND_PCM_WRITE_BITS ");
        return 1;
 }
 
 arg = CHANNELS;
 if (ioctl(fd_dev_r, SOUND_PCM_WRITE_CHANNELS, &arg) == -1)   //设置声道数
 {
        perror("Cannot set SOUND_PCM_WRITE_CHANNELS");
        return 1;
 }
 arg = RATE;
 if (ioctl(fd_dev_r, SOUND_PCM_WRITE_RATE, &arg) == -1)      //设置采样率
 {
        perror("Cannot set SOUND_PCM_WRITE_WRITE");
        return 1;
 }
 
 //打开声卡设备，只写方式；并对声卡进行设置 
 int fd_dev_w = open("/dev/dsp", O_WRONLY,0777);
 if (fd_dev_w < 0)
 {
        perror("Cannot open /dev/dsp device");
        return 1;
 }
 arg = SIZE;
 if (ioctl(fd_dev_w, SOUND_PCM_WRITE_BITS, &arg) == -1)      //设置量化位数
 {
       perror("Cannot set SOUND_PCM_WRITE_BITS ");
       return 1;
 }
 arg = CHANNELS;       
 if (ioctl(fd_dev_w, SOUND_PCM_WRITE_CHANNELS, &arg) == -1)   //设置声道数 
 {
        perror("Cannot set SOUND_PCM_WRITE_CHANNELS");
        return 1;
 }
 arg = RATE;        
 if (ioctl(fd_dev_w, SOUND_PCM_WRITE_RATE, &arg) == -1)       //设置采样率
 {
        perror("Cannot set SOUND_PCM_WRITE_WRITE");
        return 1;
 }
 
 /**以下开始录音**/
 system("rm -f sound.wav");//清除已有的wav录音文件
 int fd_f;
    if(( fd_f = open("./sound.wav", O_CREAT|O_RDWR,0777))==-1)//创建一个wave格式语音文件
    {
        perror("cannot creat the sound file");
    }
    if(write(fd_f, &wavehead, sizeof(wavehead))==-1)//写入wave文件的文件头
    {
       perror("write to sound'head wrong!!");
    }
 for(i=0;i<(LENGTH*RATE*SIZE*CHANNELS/8)/RSIZE;i++)//每次从声卡获得RSIZE大小的数据，共循环了语音长度/RSIZE次
 {
 
    
    if (read(fd_dev_r, buf, sizeof(buf)) != sizeof(buf))
    {
      perror("read wrong number of bytes");
    }
    if(write(fd_f, buf, sizeof(buf))==-1)
    {
          perror("write to sound wrong!!");
    }    
 }
 close(fd_dev_r);//关闭只读方式的声卡
 close(fd_f);//关闭wave文件
 printf("play your sound now??\n y OR n\n");
 /***以下是播放wav语音文件**/
 if(getchar()=='y')
 {
    printf("Play...:\n");
    if(( fd_f = open("./sound.wav", O_RDONLY,0777))==-1)
    {
       perror("cannot creat the sound file");
    }
    lseek(fd_f,44,SEEK_SET);
    for(i=0;i<(LENGTH*RATE*SIZE*CHANNELS/8)/RSIZE;i++)
    { 
      
        if (read(fd_f, buf, sizeof(buf)) != sizeof(buf))   //读语音文件
        perror("write wrong number of bytes"); 
             
        if (write(fd_dev_w, buf, sizeof(buf)) != sizeof(buf)) //送声卡播放
        perror("wrote2 wrong number of bytes");
    }
    close(fd_f);
    close(fd_dev_w);
    return 0;
 }
 else
 {
    printf("bye!\n");
    return 0;
 }


}
