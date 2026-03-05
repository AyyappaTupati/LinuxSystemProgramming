#include"headers.h"
struct msgbuf{
		long mtype;
		char mtext[20];
};
int main(int argc,char **argv)
{
	int mqId;
	struct msgbuf buf;
	if(argc<3)
	{
		printf("error: use: ./mqRd <key>  <type>\n");
		exit(0);
	}
	mqId=msgget(atoi(argv[1]),IPC_CREAT|0600);
	printf("mqId=%d in process:%d\n",mqId,getpid());

	buf.mtype=atoi(argv[2]);
	while(1)
	{
	printf("waiting for message:\n");
	
	memset(buf.mtext,0,20);
	if(msgrcv(mqId,&buf,20,buf.mtype,MSG_NOERROR)==-1) 
	{perror("msgrcv:");return 0;}
	printf("%d:%s\n",getpid(),buf.mtext);
	if(strcmp(buf.mtext,"QUIT")==0)  break;
	}//

}
