#include<stdio.h>
#include<windows.h>

void test1(){
	FILE* fstream=fopen("test.txt","w");
	fputs("hello jack",fstream);           //普通文件流通道采用全缓冲，正常情况下只有缓冲区装满后才会刷新缓冲区
	Sleep(4000);                           //程序执行后立马去观察，发现数据并没有立刻写入文件                       
	fflush(fstream);                       //等待4秒后缓冲区强制刷新，此时数据写入文件
    getchar();                             //阻塞程序，防止结束(程序正常结束也会刷新缓冲区)
}

void test2(){
    FILE* fstream=fopen("test222.txt","r");
    if(fstream==NULL)
    {
        perror("fopen:");
    }
}

void test3(){
	FILE* stream_1=fopen("test.txt","r");
	if(stream_1==NULL)                     //如果文件打开失败
	{
        perror("fopen");                   //打印错误信息
        return;                            //中断程序
    }
	
	while(fgetc(stream_1)!=EOF);           //循环读取文件直到读取失败
	
	if(feof(stream_1))                     //判断是正常读取完毕
		printf("正常读取结束");
	else if(ferror(stream_1))              //还是流错误
	{
		printf(strerror(errno));           //打印错误信息
		clearerr(stream_1);                //清除流的错误标识
	}

    fclose(stream_1);
}

int main(){
    //test1();
    //test2();
    test3();

    return 0;
}