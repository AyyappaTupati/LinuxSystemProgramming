#include<stdio.h>
typedef int(*fptr)(int ,int );
int sum(int,int);
int sub(int,int);

int main(){
	int var1 = 10, var2 = 20, var3 =0; 
	fptr FpArr[2]= {sum,sub};
	var3 = (*FpArr[0])(var1,var2);
	printf("Calls the sum fuction and var3 = %d\n",var3);
	var3 = (*FpArr[1])(var1,var2);
	printf("Calls the sub fuction and var3 = %d\n",var3);
	return 0;
}

int sum(int a,int b){
	return a+b;
}
int sub(int a, int b){
	return a-b;
}

