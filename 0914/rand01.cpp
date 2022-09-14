#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void)
{
	int i;
	srand(time(NULL)); //값 바꾸려고 밀리초 갱신 
	for(i=1;i<=6;i++)
	printf("%2d:%d\n",i, rand()%45+1); // 
	return 0;
} 
