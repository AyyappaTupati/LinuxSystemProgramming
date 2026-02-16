#include"headers.h"
int main()
{
	char dateString[20],timeString[20];
	struct tm *tmptr;
	time_t t;
while(1){
	t=time(NULL);	
//	printf("%u\n",(unsigned int)t);
        tmptr=localtime(&t);
	strftime(dateString,20,"%F",tmptr);
	strftime(timeString,20,"%T",tmptr);
	printf("%s %s\n",dateString,timeString);
	sleep(1);
	system("clear");
	}

}
