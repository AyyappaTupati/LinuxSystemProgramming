#include"headers.h"
int main()
{
	printf("%d\n",getpid());
	if(fork()==0)
	execlp("date","date",NULL);
	else
	execlp("cal","cal",NULL);

exit(0);

}
