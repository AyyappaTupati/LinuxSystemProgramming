#include "header.h"

int main()
{
    if(fork()==0)
    {
	    printf("Child PID = %d PPID = %d\n",getpid(),getppid());
	    sleep(20);
	    printf("Child PID = %d PPID = %d\n",getpid(),getpid());
    }
    else
    {
	    printf("Parent PID = %d PPID = %d\n",getpid(),getppid());
	    sleep(10);
    }
    //return 0;
}
