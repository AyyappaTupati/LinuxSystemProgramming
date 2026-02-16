#include<stdio.h>
#include<unistd.h>
int main()
{
	while(1)
	{
	printf("p2: %d \n",getpid());
	sleep(3);//delay for 3 seconds
	}

}
