#include<stdio.h>

int sum(int ,int);// sum function globel declaration
typedef int (*fptr)(int ,int);  // typedef is generated the new fptr data type based on this i can genearte 
				// the new variable this var will be used for return or sotre or pass a fp

fptr ReturnFp(void); // this function will return a function pointer which can take 
		     // 2 ints as args and return a integer
		     // with fptr datatype we can under stand the syntax
int main(){
	int var1 = 10, var2 = 20, var3 = 0; //variable declaration and the initialization
	fptr fp; // here new variable type of function pointer is fptr is created 
	fp = ReturnFp(); // here the return function pointer is asigned to the fp variable/function pointer
	var3 = (*fp)(var1,var2); // the returned function is sum function that is stored in fptr through fptr i get 
				   // the return value of the sum function
	printf("var3 = %d\n",var3);// printing the result value
	return 0;
}

int sum(int a,int b){
	return a+b;
}

fptr ReturnFp(void){
	return sum; // here is the thing i return back the function pinter and i cacth up with a function ponter
}
