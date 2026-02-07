#include "header.h"

int main()
{
	//FILE *fp = fopen("sample","r"); this will give you no such file or directory error
	FILE *fp = fopen("a.out","r"); //read succeefully
	if(fp == 0)
	{
		perror("Faild");
		return 0;
	}
	perror("Success");

}
