#include<stdio.h>
#include<unistd.h>
#include<string.h>

int main()
{
	int fd[2];
	pipe(fd);
	
	if(fork() == 0)
	{

