#include"header.h"
int main()
{
	int c = fork();
	if(c==0)
	{
		while(1)
		{
		printf("this is the child = %d\n",getpid());
		sleep(3);
		}
	}
	else
	{
		int s, res = waitpid(c,&s,WUNTRACED);
		printf("The child process is untraced %d st = %d\n",res,s);
	}
}
