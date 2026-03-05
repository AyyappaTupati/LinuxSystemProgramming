#include"headers.h"
int main()
{

while(1)
{
	system("ps -e | grep pts");
	sleep(1);
	system("clear");//system(), is combination of fork+exec.
}
}
