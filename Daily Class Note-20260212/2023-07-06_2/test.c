#include"headers.h"
void isr(int n)
{
	printf("ctrl+c disabled\n");

}
int main()
{
	signal(1,SIG_IGN);
	//signal(2,SIG_IGN);
	signal(2,isr);
	//the signal() system call, makes the changes in signal-table, of this process.   in Signal-no-1, the action is changed from SIG_DFL  to SIG_IGN.
	printf("job %d\n",getpid());
	while(1);
}
