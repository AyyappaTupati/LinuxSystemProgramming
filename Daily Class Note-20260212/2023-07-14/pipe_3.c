#include"headers.h"
int main()
{
	int p[2];
	pipe(p);//total 5 fileDesc available, 0,1,2 for term,  3,4 for pipe
	if(fork()==0)
	{
		//child code
	close(1);
	//0(term),2(term),3(pipe_r),4(pipe_w)
	dup(p[1]);//0(term),1(pipe_wr),2(term),3(pipe_r),4 (pipe_w);
	close(p[0]);
	execlp("ls","ls","-l",NULL);//output redirected.


	}

	else
	{
////////0,1,2,3,4 file descriptors available
	close(0);//
		 //1,2,3,4 available.
	dup(p[0]);//duplicate of 3   is now the least unused number.
		  //0(pipe_rd),1(term),2(term),3(pipe_rd),4(pipe_wr).
	close(p[1]);//
	execlp("wc","wc",NULL);//input redirction
	}

}
