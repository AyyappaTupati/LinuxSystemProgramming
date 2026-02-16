#include"headers.h"
char str[20];
int main()
{
	int fd[2];
	if(pipe(fd)==-1){perror("pipe");exit(0);}
	//A pipe is opened in kernel, to be used. 
	//two file-descriptors are available to use the pipe.
	//fd[0] read end.       fd[1] write end.
	if(fork())
	{
		strcpy(str,"vector");
		sleep(4);
		write(fd[1],str,strlen(str)+1);
		exit(0);
	}
	else
	{
		printf("in child, str:%s\n",str);
		//the str in child, should be the modified copy of the parent.
		read(fd[0],str,20);//when called, the pipe is empty.
				   //reading-from emptypipe, blocks the reader.
		printf("in child, str:%s\n",str);
		exit(0);	
	}

}
