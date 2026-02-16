#include"headers.h"
//this program should execute(load) the app,supplied in command line 

int main(int argc,char **argv,char *envp[])
{
	char *cmd="/bin/date";
	char *p[]={"date",NULL};

	//if(argc<2){printf("Error: no app supplied\n"); exit(0);}

	if(execve(cmd,p,envp)==-1)
		perror("execve");
	else
		printf("success");

	return 0;
}
