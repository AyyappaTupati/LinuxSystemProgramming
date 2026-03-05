#include"headers.h"

//compile  with -O3  to verify the impact of optimisation 
pthread_t tid1,tid2;
//int data=1;
volatile int data=1;//requests compiler not to optimise variable named data.
void *f1(void *p)
{
	int i;
printf("in thread1 : %d\n",data);
	for(i=1;i<2000000000;i++)
		data++;
printf("thread1 : %d\n",data);
pthread_exit(NULL);
}
void *f2(void *p)
{
	int i;
printf("in thread2 : %d\n",data);
	for(i=1;i<2000000000;i++)
			data--;
printf("thread2 : %d\n",data);
pthread_exit(NULL);
}
int main()
{
	printf("in main...data=%d\n",data);
	pthread_create(&tid1,NULL,f1,NULL);//creates a new job(thread)
	pthread_create(&tid2,NULL,f2,NULL);//creates a new job(thread)
	pthread_join(tid1,NULL);//equivalent to waitpid() in process.
	pthread_join(tid2,NULL);
	printf("in main...data=%d\n",data);
}
