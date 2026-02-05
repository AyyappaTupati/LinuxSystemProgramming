#include"header.h"
int delay,result,status,pid;
int main(){
    if(fork()==0){
	printf("This is the child 1 process\n");
	srand(pid = getpid());
	delay = rand()%10+1;
	printf("The Child 1 pid=%d and sleep=%d\n",pid,delay);
	sleep(delay);
       	exit(1);

    }
    else{
	    if(fork()==0){
		printf("This is the child 2 process\n");
		srand(pid = getpid());
		delay = rand()%10+1;
		printf("The Child 2 pid=%d and sleep=%d\n",pid,delay);
		sleep(delay);
		exit(1);
	    }
	    else{
		    if(fork()==0){
			printf("This is the child 3 process\n");
			srand(pid = getpid());
			delay = rand()%10+1;
			printf("The Child 3 pid=%d and sleep=%d\n",pid,delay);
			sleep(delay);
			 exit(1);
		    }
		    else{
			    while(result = (wait(&status) != -1) ){
			    	if(WIFEXITED(status))
					printf("Child %d is terminated normally status=%d\n",result,WEXITSTATUS(status));
				else if(WIFSIGNALED(status))
					printf("Child %d is terminated of signal %d\n",result,WTERMSIG(status));
			    }
			    printf("Parent is terminated\n");
		    }
	    }
    }
    return 0;
}


	    


