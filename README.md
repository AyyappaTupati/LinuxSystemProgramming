# LinuxSystemProgrammin
This Repo is having the Basic understanding of the linux system programming concepts.
D: Feb 5 26
- created a static library and taken a smaple fuctions like sum,sub,mul,mod,div each functio is like a file.make them as a static library objec files using the gcc compilation
- gcc -c sum.c -o sum.o like this all the files are created.
- for generation the static library we have to make them as a archive file or .a files.
- ar -rcsv libAirth.a sum.o sub.o mul.o mod.o div.o
- to get compile we use the **gcc program.c libAirth.a**

coming to dynamic library we have two types 
- Dynamic Load time linking and another one is dynamic runtime linking i love this one.
- to creat dynamic loadt time linking lib file we use below command.
- gcc -c -fpic sum.c this will creat exacutable sum.o not a object file, why because the dynamic load time linikng is not copy the reference it loads the object files into ram during execution.
- Correction: sum.o is still an object file, not an executable. You cannot run ./sum.o.
  Without -fpic: The compiler assumes the code will be loaded at a specific address (absolute addressing).
  With -fpic (Position Independent Code): The compiler generates code that accesses data via "offsets" (relative addressing) using the Global Offset Table (GOT).     This allows the OS to load the library anywhere in the RAM, which is mandatory for shared libraries.
  
- to creat a library use gcc -shared -o libAirth.so sum.o mul.o sub.o mod.o div.o
- this will creat the dynamic load time linkable library file.
- to generat a.out use gcc program.c ./libAirth.so

- And in dynamic run time linking the calling library file is loaded into ram when it is called and unload from the ram when the job is completed.
- Here no wastage of the RAM space and it spped up the execution.
- for this we need a dynamic library and below kernel subroutines.
- dlopen();
- dlclose();
- dlsym();
- dlerror();
- these are used to call the specific function in a dynamic library.These uses function pointers to handle the situation.
gcc main.c -ldl -o dynamic_loader

#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h> // Required for dlopen, dlsym, etc.

int main() {
    void *handle;
    int (*add_func)(int, int); // Function Pointer declaration
    char *error;

    // 1. Load the library into RAM
    handle = dlopen("./libAirth.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        exit(1);
    }

    // 2. Clear any existing errors
    dlerror();

    // 3. Find the address of the "sum" function and assign it to our pointer
    // dlsym returns a void*, so we cast it to our function pointer type
    *(void **) (&add_func) = dlsym(handle, "sum");

    if ((error = dlerror()) != NULL)  {
        fprintf(stderr, "%s\n", error);
        exit(1);
    }

    // 4. Call the function using the pointer
    printf("Sum: %d\n", (*add_func)(10, 20));

    // 5. Unload the library from RAM (freed memory!)
    dlclose(handle);

    return 0;
}

D: 7 FEB 26
- getting the understandid of the system library function how it is used.
- Well the system library function is used to execute the shall comands, when ever we use the system function in our application it is used to execute the passed shall command.
- the sysntax is
- int system(const char *command);

- .............................
- #include "header.h"

int main()
{
        printf("Executing the shall ls command through the c programm\n");
        sleep(10);
        system("ls");
        printf("Here Ls is executed by the sh shall and created by the bash shall to execute ls\n");
        while(1);
}
..................................
- Here the process is like this first our bash is execute the ./a.out and our ./a.out is encounter the system function call this will creat a shell sh to execute the ls command.
- So in between there is a special process is creted that is sh shall.
- Below code is demonistrate the how it is happening.

- This is a P1 process which executes infinitly.
#include "header.h"
int main()
{
        printf("P1 PID =  %d  PPID = %d\n",getpid(), getppid());
        printf("Executing the P1 process\n");
        while(1);
}

.....
- here the P2 process is calling the P1 with system function call

  #include "header.h"

int main()
{
        printf("P2 PID = %d PPID = %d\n",getpid(), getppid());
        printf("Using system execute the P1 Process\n");
        system("./P1");
}

- so observe here while exacuting the P2 process is prints the its PID and PPID and after call "System" P1 will execute so it is also print its PID and PPID but observe ther the P1 Process PPID it is not P2 process PID it is shall PID to check that use below command "ps -el" this will give you the current running process list so observe here the P1 and P2 and sh processess PPID and PID. 


D: 9 FEB 26
Orphan 
- this process is a process which is still being executed after the it's parent is completed it's execution so when like this happen the child/ orphan process is    adopted by the nearby subreapers like bash or systemd --user of by defult the init.
- In orphan there is nothing to worry about why because the process manager is make it's parent is init or any other processes.
Zombie
 - The zombie process is created when the parent is still running but the child process is completed its execution and no instructions to execute but this zombie     process is still present in the RAM this is reduse the RAM efficience.
 - So to avoid this type of zombie processes the parent is need to collect the exit status of the child using exit(0) / exit(1) in the child to send the exit         status of the chil 1 means normal failure and 0 means normal success exit and wait() in the parent is used to collect the status of the child in status variabl    whih is passed in the wait call
 - int wait(int *status);
 - the wait system call is return the child process ID and the status pointer is used to store the status of the child i.e if the child is terminated by the          signal the first byte of the status variable is filled with signal numnber.
 - if the child is terminated normally then tha status variable 2nd bytes is filled with the 256 value if failure or 0 if success
 - atexit(function name) is used to call a specific function at the end of the function call or before the function being terminated.
   the atexit() function is register all the function parameters in reverse order and those parameters are called executed at the end of the it's calling function.

D: 16 feb 2026
- so today topic is, the waitpid system call the use of the waitpid system call is used to wait for the particular child to finish it task.
- unlike wait it is waiting for the one particular task to complete.
- PID_T waitpid(child PID, &Status, options);
- so here the PID represents, for which child the parent need to wait.
- if we put PID as -1 waitpid() acts like a wait() waiting for any one of the task to complete first. if all childs are need to monitor used while loop.
- so here the status and the return values are same as wait().
- coming to options these are helps to get the signal status.
- for example if the child process is stoped for which reson this will tell us.
- for WUNTRACED the child process is returning the Signal number in heigher byte of status var and 0x7f in lower byte of status var.
- So for the termination and suspension or resumed these macros are used to check the child process state like for which signal wht child is terminated. we can give the suggestion to you will terminate for this situation.
- we have lot of macors here but we use the WUNTRACED, WCONTINUED, WNOHANG.
- here the WUNTRACED, WCONTINUED are the waiting for the process to terminate but in WNOHANG this wait is not blocking after hiting the waitpid the parent will no longer wait to complete the child.

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
....................................................................................
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
			    while( ( result = wait(&status) ) != -1){
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
..................................................................................................
#include"header.h"
int main()
{
	int c1,c2, res, st;
	c1 = fork();
	if(c1 == 0)
	{
		while(1)
		{
		   printf("This is the child one process PID = %d | PPID = %d\n",getpid(),getppid());
		   sleep(5);
		}

	}
	else
	{
		c2 = fork();
		if(c2 == 0)
		{
			while(1){
			printf("This is the child two process PID = %d | PPID = %d\n",getpid(),getppid());
			sleep(3);
			}
		}
		else
		{
			res = waitpid(c1,&st,WUNTRACED|WCONTINUED|WNOHANG);
			if(WIFEXITED(st))
			{
				printf(" The process %d is exited normally the status is %d\n",res,WEXITSTATUS(st));
			}
			if(WIFSIGNALED(st))
			{
				printf(" The process %d is terminated by the signal is %d\n",res,WTERMSIG(st));
			}
		}
	}
}

Next topic:
EXEC family 
- this family is used to creat a new image of a passed executable on top of existing executable image.
- in simple it replaces the ./a.out image with the command passed image in it.
- so we have multipe system calls in this family primarily those are.
- int execl(const char *pathname, const char * arg,...);
- int execlp(const char *filename, const char * arg,...);
- int execv(const char *pathname, const *char arg[]);
- int execvp(const char *filename, const *char arg[]); 

					


 
