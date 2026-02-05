#include<stdio.h>

int Add(int a, int b){
	return a+b;
}

int main(){
	int a,b,Result;
	printf("Enter 2 integers\n");
	scanf("%d%d",&a,&b);
	Result = Add(a,b);
	printf("Result = %d\n",Result);
	return 0;
}
