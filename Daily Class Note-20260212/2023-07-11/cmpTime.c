#include"headers.h"
int main(int argc,char **argv)
{
	struct stat buf1,buf2;
	stat(argv[1],&buf1);
	stat(argv[2],&buf2);
	
	if(buf1.st_mtime > buf2.st_mtime)
		printf("%s is recent than %s\n", argv[1],argv[2]);
	else if(buf1.st_mtime< buf2.st_mtime)
		printf("%s is recent file than %s\n",argv[2],argv[1]);
	else
		printf("same time stamp\n");



}
