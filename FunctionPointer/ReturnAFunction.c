#include<stdio.h>

int sum(int ,int);// sum function globel declaration
int (*fptr)(int ,int); // function pointer globel declaration
int (*ReturnFp(void))(int ,int); // this function will return a function pointer which can take 2 ints as args and return a integer

int main(){
	int var1 = 10, var2 = 20, var3 = 0; //variable declaration and the initialization
	fptr = ReturnFp(); // here the return function pointer is asigned to the fptr variable/function pointer
	var3 = (*fptr)(var1,var2); // the returned function is sum function that is stored in fptr through fptr i get 
				   // the return value of the sum function
	printf("var3 = %d\n",var3);// printing the result value
	return 0;

}

int sum(int a,int b){
	return a+b;
}

int (*ReturnFp(void))(int ,int ){
	return sum; // here is the thing i return back the function pinter and i cacth up with a function ponter
}
