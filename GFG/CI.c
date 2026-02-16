#include<stdio.h>
#include<math.h>
int main()
{
	double principle,rate,time,amount;

	printf("Enter principle, interest rate, tenure\n");
	scanf("%lf%lf%lf",&principle,&rate,&time);

	amount = principle * ((pow((1+rate/1000),time)));

	double ci = amount - principle;
	printf("%lf",ci);
	return 0;
}

