#include"headers.h"
int main()
{
	int p[2];
	pipe(p);
	if(fork()==0)
	{////child code
		int i;
		for(i=1;i<=10;i++)
		{
			sleep(1);
			write(p[1],&i,4);
			
		}
	
	}
	else
	{///parent..
		int j;
		do{
			read(p[0],&j,4);
			printf("%d\n",j);
			
		}while(j<10);

	}
}
