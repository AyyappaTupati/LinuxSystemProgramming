#include"header.h"
int main()
{
	printf("Hai this is the execlp call\n");
	execlp("cal","cal",NULL);
	return 0;
}
