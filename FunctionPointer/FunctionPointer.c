#include<stdio.h>
int sum(int, int);// function declaration
int main(){
	int var1 = 10, var2 = 20, var3;//variable declaration
	int(*fp)(int,int); // function pointer decleration 
	// int (*fp)(int , int )=sum; // function pointer initialization
	fp = sum;// asigning sum address to the function pointer 
	var3 = (*fp)(var1,var2);// calling the sum function through fp
	printf("Var3 = %d\n",var3);// printing the var3 value 10+20
	return 0;
}
int sum(int a, int b){
	return a+b;
}
