#include<stdio.h>
typedef int(*fptr)(int ,int );
int sum(int,int);
int sub(int,int);
int mul(int,int);
int div(int,int);
int mod(int,int);

int main(){
	int var1 , var2 , input = 0 ; 
	fptr FpArr[5]= {sum,sub,mul,div,mod};

 	printf("Enter the Option to Performance Airthmatic operations\n1)Addtion\n2)Substraction\n3)Multiplication\n4)Division\n5)ModDiv\n");
	scanf("%d",&input);
	if(input>5 || input<1) 
	{
		printf("Invalid Input\n");
		return 0;
	}
	printf("Enter 2 values to perform operation %d\n", input);
	scanf("%d%d",&var1,&var2);
	printf("result = %d\n", (*FpArr[input-1])(var1,var2) );
	return 0;
}

int sum(int a,int b){
	return a+b;
}

int sub(int a, int b){
	return a-b;
}

int mul(int a,int b){
	return a*b;
}

int div(int a,int b){
	return a/b;
}

int mod(int a , int b){
	return a%b;
}
