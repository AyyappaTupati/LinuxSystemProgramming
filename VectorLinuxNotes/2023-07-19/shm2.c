#include"headers.h"
int main()
{
	int id;
	char *ptr;
	srand(getpid());
	id=shmget(1,5,IPC_CREAT|0666);
	printf("shmId=%d in %d\n",id,getpid());
	ptr=shmat(id,NULL,0);
	while(1)
	{
		ptr[rand()%5]=rand()%26+65;
	usleep(100000);//delay of 0.1 sec
	}
	shmdt(ptr);

}
