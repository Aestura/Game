#include <stdio.h>
void draw_square(int size);
int main(void)
{
	int n;
	printf("정사각형 그리기\n\n");
	printf("정사각형의 길이(최대 37)를\n");
	printf("입력하고 Enter>");
	scanf("%d", &n);
	draw_square(n);
	return 0;
}
void draw_square(int size)
{
	int i, j;
	unsigned char a=0xa6; // 원래는 -128~ 127인데 unsigned 0~255 라는뜻 
	unsigned char b[7]; 
	for(i=1;i<7;i++)
		b[i]=0xa0+i;
		printf("%c%c",a, b[3]);
	for(i=0;i<size;i++)
		printf("%c%c", a, b[1]);
		printf("%c%c", a, b[4]);
		printf("\n");
	for(i=0;i<size;i++)
	{
	printf("%c%c", a, b[2]);
	for(j=0;j<size;j++)
		printf(" ");
		printf("%c%c",a, b[2]);
		printf("\n");
	}
	printf("%c%c", a, b[6]);
	for(i=0;i<size;i++)
		printf("%c%c", a, b[1]);
		printf("%c%c", a, b[5]);
		printf("\n");
}

