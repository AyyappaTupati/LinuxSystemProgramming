#include"header.h"
int delay,result,status,pid;
pid_t child1, child2,child3;
int main(){
    child1 = fork();
    if(child1==0)
    {
	printf("This is the child 1 process\n");
	srand(pid = getpid());
	delay = rand()%10+1;
	printf("The Child 1 pid=%d and sleep=%d\n",pid,delay);
	sleep(delay);
       	exit(1);

    }
    else
    {
	//result = wait(&status);
	result = waitpid(child1,&status,0);
	if(WIFEXITED(status))
	printf("Child %d is terminated normally status=%d\n",result,WEXITSTATUS(status));
	else if(WIFSIGNALED(status))
	printf("Child %d is terminated of signal %d\n",result,WTERMSIG(status));
	child2 = fork();
	if(child2==0)
	{
		printf("This is the child 2 process\n");
		srand(pid = getpid());
		delay = rand()%10+1;
		printf("The Child 2 pid=%d and sleep=%d\n",pid,delay);
		sleep(delay);
		exit(1);
	}
	else
	{
		//result = wait(&status);
		result = waitpid(child2,&status,0);
	   	if(WIFEXITED(status))
		printf("Child %d is terminated normally status=%d\n",result,WEXITSTATUS(status));
		else if(WIFSIGNALED(status))
		printf("Child %d is terminated of signal %d\n",result,WTERMSIG(status));
		child3 = fork();
	        if(child3==0)
		{
			printf("This is the child 3 process\n");
			srand(pid = getpid());
			delay = rand()%10+1;
			printf("The Child 3 pid=%d and sleep=%d\n",pid,delay);
			sleep(delay);
			 exit(1);
		 }
		 else
		 {
			//result = wait(&status); 
			result = waitpid(child3,&status,0);
			if(WIFEXITED(status))
			printf("Child %d is terminated normally status=%d\n",result,WEXITSTATUS(status));
			else if(WIFSIGNALED(status))
			printf("Child %d is terminated of signal %d\n",result,WTERMSIG(status));
			sleep(delay);
			printf("Parent is terminated\n");
		 }
	    }
    }
    return 0;
}


	    


