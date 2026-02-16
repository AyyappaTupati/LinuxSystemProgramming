#include"headers.h"
void isr(int n)
{
	printf("ctrl+c disabled\n");
	for(int i=1;i<=1000000;i++)
		for(int j=1;j<=2000;j++);
	printf("isr exiting\n");

}
int main()
{
	struct sigaction var;

	var.sa_handler=isr;
	var.sa_flags=0;
	//sigemptyset(&var.sa_mask);
	sigfillset(&var.sa_mask);
	sigaction(2,&var,NULL);

	//signal(2,isr);
	//the signal() system call, makes the changes in signal-table, of this process.   in Signal-no-1, the action is changed from SIG_DFL  to SIG_IGN.
	printf("job %d\n",getpid());
	while(1);
}
