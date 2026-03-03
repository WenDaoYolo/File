#include<stdio.h>

void test1(){
	int a,b,c,d;
	char temp[]="3-4-5-6";
	char temp2[20];
	char test='A';
	FILE* fstream_1=fopen("text.txt","w");

	scanf("%d+-%d",&c,&d);                        //从键盘上按指定格式读取数据(分隔符为+-或默认符)
	fscanf(fstream_1,"%d%d",&a,&b);               //从文件流通道按指定格式读取数据到ab(分隔符为默认符)
	sscanf(temp,"%d-%d-%d-%d",&a,&b,&c,&d);       //从文件流通道按指定格式读取数据到abcd(分隔符为-或默认符)
	
	printf("value:%d,%c\n",test,test);            //按照指定格式输出字符A以及对应的十进制ASCLL码到屏幕
	fprintf(stdout,"%d %d %d %d\n",a,b,c,d);      //按照指定格式输出abcd到屏幕
	fprintf(fstream_1,"%d %d %d %d",a,b,c,d);     //按照指定格式输出abcd到文件流通道
	sprintf(temp2,"%d%d==%d%d??\n",a,b,c,d);      //按照指定格式将数据输出到temp2中
	printf("temp2:%s\n",temp2);                   //按照指定格式将temp2输出到屏幕
}

void CheckAndClearInputError(int check){
	if(check==0)
	{
		printf("输入数据无效！\n");
		int ch;
		while((ch=getchar()!='\n'&&ch!=EOF));      //清除缓冲区直到遇到换行符或者EOF(缓冲区的结尾)
	}
}

void test2(){
	while(1){
		int a,check;
		check=scanf("%d",&a);
		CheckAndClearInputError(check);
	}
}

void test3(){
	int a;
	char temp[10];
	
	a=getchar();              //从键盘上获取单个字符
	putchar(a);               //输出单个字符a到屏幕
	putchar('\n');	          //输出单个字符换行到屏幕
	gets(temp);               //从键盘上获取字符串
	puts(temp);               //输出字符串到屏幕
}

int main(){
    //test1();
	//test2();
	//test3();
	float t=3.14;
	printf("%10.3f",t);       //将数据以左对齐3个字节的宽度、保留两位精度的浮点型格式输出到屏幕

    return 0;
}