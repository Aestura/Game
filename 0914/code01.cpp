#include <stdio.h>
#include <conio.h>
int main(void)
{
	int chr;
	do
	{
	chr=getch();
	if (chr==0 || chr == 0xe0)
		{
			chr=getch();
			printf("Ȯ��Ű code=%d\n", chr);
		}
	else
		printf("�ƽ�Ű code=%d\n", chr);
	}while(1);
	
	return 0;
}

