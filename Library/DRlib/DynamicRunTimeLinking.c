#include "header.h"
#include "../DLlib/Airthmatic.h"
int main()
{
	int n1=10, n2=20, Res = 0, op  = 0;
	int *Handler = NULL;
       	int (*fp)(int,int) ;
	printf("Enter an option to performa operation using dynamic runtime linking\n");
	printf("1. sum\n2. sub\n3. mul\n");
	scanf("%d",&op);

	if(op == 1)
	{
		Handler = dlopen("../DLlib/libAirth.so",RTLD_LAZY);
		if(Handler == 0)
		{
			printf("%s\n",dlerror());
			return 0;
		}
		fp = dlsym(Handler,"sum");
		if(fp == 0)
		{
			printf("%s\n",dlerror());
			return 0;
		}
		Res = (*fp)(n1,n2);
		printf("Sum of Two Numbers 10+20 = %d\n",Res);
		dlclose(Handler);
	}
	if(op == 2)
	{
		Handler = dlopen("../DLlib/libAirth.so",RTLD_LAZY);
		if(Handler == 0)
		{
			printf("%s\n",dlerror());
			return 0;
		}
		fp = dlsym(Handler,"sub");
		if(fp == 0)
		{
			printf("%s\n",dlerror());
			return 0;
		}
		Res = (*fp)(n1,n2);
		printf("Sub of Two Numbers 10-20 = %d\n",Res);
		dlclose(Handler);
	}

	if(op == 3)
	{
		Handler = dlopen("../DLlib/libAirth.so",RTLD_LAZY);
		if(Handler == 0)
		{
			printf("%s\n",dlerror());
			return 0;
		}
		fp = dlsym(Handler,"mul");
		if(fp == 0)
		{
			printf("%s\n",dlerror());
			return 0;
		}
		Res = (*fp)(n1,n2);
		printf("mul of Two Numbers 10*20 = %d\n",Res);
		dlclose(Handler);
	}
	return 0;
}
