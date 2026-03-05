#include"headers.h"
int main()
{
	int id;
	char *ptr;
	id=shmget(1,5,IPC_CREAT|0666);//system call to -
	//create a shared-memory-segment.
	//1st is arg is key(for uniqueness of shared memory)
	//2nd arg is the number of byte in shared-memory
	printf("shmId=%d in %d\n",id,getpid());
	ptr=shmat(id,NULL,0);//attaches the shared memory area -
	//to the process area., now using ptr we can send/recv data to/from shm
	//
	while(1)
	{
	printf("%d:%c %c %c %c %c\n",getpid(),ptr[0],ptr[1],ptr[2],ptr[3],ptr[4]);
	usleep(100000);//delay of 0.1 sec
	system("clear");
	}
	shmdt(ptr);

}
