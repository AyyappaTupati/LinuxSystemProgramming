#include"header.h"

int main(){
	if(fork()==0)
	{
		printf("This is child process PID = %d | PPID = %d\n",getpid(),getppid());
	}
	else
	{
		printf("This is parent process PID = %d | PPID = %d\n",getpid(),getppid());
	}
	while(1);
}
