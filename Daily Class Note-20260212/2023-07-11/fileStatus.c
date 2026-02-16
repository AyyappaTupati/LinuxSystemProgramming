#include"headers.h"
int main(int argc,char **argv)
{
	struct stat  buf;
	if(argc<2){printf("error:file not supplied\n");exit(0);}
			
	if(stat(argv[1],&buf)==-1){perror("stat");exit(0);}

//if success, buf contains, the informations retrieved from Inode.

	printf("size:%u\n",(unsigned int)buf.st_size);
	printf("linkCnt=%u\n",(unsigned int)buf.st_nlink);
	printf("permission:%o\n",(unsigned int)buf.st_mode);
	printf("modification time:%u\n",(unsigned int)buf.st_mtime);

}
