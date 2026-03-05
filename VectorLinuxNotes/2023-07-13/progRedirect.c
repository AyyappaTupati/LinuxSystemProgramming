#include"headers.h"
int main(int argc,char **argv)
{
	int fd;
	fd=open("datafile.txt",O_CREAT|O_APPEND|O_WRONLY,0660);
	printf("hello\n");//sends the hello msg to terminal.
	close(1);
	dup(fd);//the duplicate of fd will be the lowest unused number.
		//duplicate of fd  will be 1.
		//that means 1 is the file desc for datafile.txt
	printf("BYE\n");
	exit(0);

}
