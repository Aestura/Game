#include <stdio.h>
#include <conio.h>
#include <windows.h>
#define X_MAX 79 //����(��)������ �ִ밪
#define Y_MAX 24 //����(��)������ �ִ밪
void move_arrow_key(char chr, int *x, int *y, int x_b, int y_b);
void gotoxy(int x, int y);
int main(void)
	{
		char key;
		int x=10, y=5;
		do
		{
			gotoxy(x, y);
			printf("A");
			key=getch();
			move_arrow_key(key, &x, &y, X_MAX, Y_MAX);
		}while(key!=27);
	return 0;
	}
void move_arrow_key(char key, int *x1, int *y1, int x_b, int y_b)
{
switch(key)
{
case 72: //����(��) ������ ȭ��ǥ Ű �Է�
*y1=*y1-1;
if (*y1<1) *y1=1; //y��ǥ�� �ּҰ�
break;
case 75: //����(��) ������ ȭ��ǥ Ű �Է�
*x1=*x1-1;
if (*x1<1) *x1=1; //x��ǥ�� �ּҰ�
break;
case 77: //������(��) ������ ȭ��ǥ Ű �Է�
*x1=*x1+1;
if (*x1>x_b) *x1=x_b; //x��ǥ�� �ִ밪
break;
case 80: //�Ʒ���(��) ������ ȭ��ǥ Ű �Է�
*y1=*y1+1;
if (*y1>y_b) *y1=y_b; //y��ǥ�� �ִ밪
break;
default:
return;
}
}

