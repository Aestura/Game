#include <stdio.h>
#include <windows.h>
void gotoxy(int x, int y);
int main(void){
	int n, i;
	for(i=1; i<=9; i++){
		
		for(n=1; n<=9; n++){
			
			gotoxy(10*i,n*3);
			printf("%d * %d =%2d ",i, n, i*n);
		}
	}
	printf("\n");
	return 0;
}
	void gotoxy(int x, int y)
	{
	COORD Pos = {x - 1, y - 1};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	}
	

