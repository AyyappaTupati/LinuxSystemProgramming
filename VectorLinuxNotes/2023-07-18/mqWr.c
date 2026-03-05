#include"headers.h"
struct msgbuf{
		long mtype;
		char mtext[40];
};
int main(int argc,char **argv)
{
	int mqId;
	struct msgbuf buf;
	if(argc<3)
	{
		printf("error: use: ./mqRd <key>\n");
		exit(0);
	}
	mqId=msgget(atoi(argv[1]),IPC_CREAT|0600);
	printf("mqId=%d in process:%d\n",mqId,getpid());

	buf.mtype=atoi(argv[2]);
	printf("enter a message:\n");
	gets(buf.mtext);
	msgsnd(mqId,&buf,strlen(buf.mtext)+1,0);
	printf("%d:%s\n",getpid(),buf.mtext);

}
