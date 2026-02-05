#include<stdio.h>

int sum(int ,int );  // sum globel declaration
int (*fptr)(int ,int); // function pointer declaration
int callBack(int,int,int(*)(int,int)); // callback function declaration it takes 2 ints and a function pointer


int main(){
	int var1=10, var2=20,var3=0;// variable declaration
				    //
	var3 = callBack(var1, var2, sum); // calling the callback here i pass the sum as an argument 
					  // based on this the sum is not calling directly by the main but it called by
					  //  the callback to the main

	printf("var3 = %d\n",var3);// printg the sum return value
	return 0;
}

int sum(int a, int b){
	return a+b;
}


int callBack(int m, int n, int(*p)(int,int)){
	return (*p)(m,n); // here i call and return the sum function indirectly
}

