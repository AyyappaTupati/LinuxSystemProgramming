#include"headers.h"
int main()
{
	struct termios buf;
	char str[20];
	tcgetattr(0,&buf);
	buf.c_lflag&=~ECHO;
	tcsetattr(0,TCSANOW,&buf);
	printf("enter a string:");
	gets(str);
	if(strcmp(str,"HELLO")==0)
		printf("matched...\n");
	else
		printf("not matched..\n");

	buf.c_lflag|=ECHO;
	tcsetattr(0,TCSANOW,&buf);
	exit(0);

}
