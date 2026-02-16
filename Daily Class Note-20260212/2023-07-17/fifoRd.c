#include"headers.h"
int main()
{
	int fd;
	char str[20];
//	mkfifo("fifo1",0660);//mknod( , , );
	//mkfifo, creates a splfile(fifo file), if non-existing with the given name.
	//If already existing, then returns -1.
	fd=open("fifo1",O_RDONLY);
	if(fd==-1){perror("open");exit(0);}

	printf("fd=%d\n",fd);

	do
	{
	printf("%d waiting for message\n",getpid());
	read(fd,str,20);//read will block the process, if the fifo is empty.
	printf("%d:%s\n",getpid(),str);

	}while(strcmp(str,"QUIT"));

	close(fd);

}

