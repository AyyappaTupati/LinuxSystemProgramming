#include"headers.h"
//compile the code using gcc -O3 prog.c.
//
volatile  int flag=0;//optimisation is not applicable on this variable...
//whenever the variable used...  it is used from its actual location,  not taking advantage of CPU-register.
// int flag=0;
void isr(int n)
{
	flag=1;
	printf("in isr\n");
}

int main()
{
	struct sigaction v;
	printf("flag=%d\n",flag);
	v.sa_handler=isr;
	v.sa_flags=0;
	sigemptyset(&v.sa_mask);
	sigaction(2,&v,NULL);//arrangement to catch ctrl+c
	while(flag!=1);

	printf("program after lock...\n");
	printf("flag=%d\n",flag);

}
