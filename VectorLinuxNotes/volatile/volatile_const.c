#include<stdio.h>
//verify using nm command , where the variable s  is getting stored
//const int s=0;//not allowed to modify directly(syntax error)  or indirectly(segmentation fault)...
volatile const int s=0;///Actually in projects if this variable to-be modifiable by outside the app., then we should make it volatile.
int main()
{
//const int static s=0;//read-only data segment
//volatile const int static s=0;//s is in data-segment, not R.O. data segment.
	//const int s=0;// auto storage class, present in stack area
	int *p=&s;
	printf("%d\n",s);
	//++s;//syntax error, as s is a R.O variable.
	++*p;
	printf("%d\n",s);
}
