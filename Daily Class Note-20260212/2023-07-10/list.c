#include"headers.h"
int main(int argc,char **argv)
{
	DIR *dp;
	//FILE *fp;//fp is 8bytes, sizeof(fp)=
	struct dirent *ptr;
	dp=opendir(argv[1]);
	while(ptr=readdir(dp))
	{
		printf("%d %s\n",(int)ptr->d_ino, ptr->d_name);
	}
	closedir(dp);

}
