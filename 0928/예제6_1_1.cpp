#include <stdio.h>
void number_check(int k, int i);
void digit_print(int dim[], int line);

int zero[20] =
	{1,1,1,1,
	 1,0,0,1,
	 1,0,0,1,
	 1,0,0,1,
	 1,1,1,1};

int one[20]=
 {0,0,1,0,
  0,0,1,0,
  0,0,1,0,
  0,0,1,0,
  0,0,1,0};

int two[20]=
 {1,1,1,1,
  0,0,0,1,
  1,1,1,1,
  1,0,0,0,
  1,1,1,1};

int three[20]=
 {1,1,1,1,
  0,0,0,1,
  1,1,1,1,
  0,0,0,1,
  1,1,1,1};

int four[20]=
 {1,0,0,1,
  1,0,0,1,
  1,1,1,1,
  0,0,0,1,
  0,0,0,1};

int five[20]=
 {1,1,1,1,
  1,0,0,0,
  1,1,1,1,
  0,0,0,1,
  1,1,1,1};

int six[20]=
 {1,0,0,0,
  1,0,0,0,
  1,1,1,1,
  1,0,0,1,
  1,1,1,1};

int seven[20]=
 {1,1,1,1,
  0,0,0,1,
  0,0,0,1,
  0,0,0,1,
  0,0,0,1};

int eight[20]=
 {1,1,1,1,
  1,0,0,1,
  1,1,1,1,
  1,0,0,1,
  1,1,1,1};

int nine[20] =
	{1,1,1,1,
	 1,0,0,1,
	 1,1,1,1,
	 0,0,0,1,
	 0,0,0,1};

int main(void)
{
	int num, line;
	printf("디지털 숫자 출력 프로그램\n");
	printf("1 이상의 정수만 입력합니다. \n\n");
	printf("\n정수 숫자입력 후 Enter> ");
	scanf("%d", &num);
	printf("\n\n");
	for(line=0;line<=4;line++)
	{
		number_check(num, line);
		printf("\n");
	}
	return 0;
}

void digit_print(int dim[], int line)
{
 int i;
 for(i=line*4;i<=line*4+3; i++) // line=0 일떄 0 1 2 3
  if (dim[i]==1)
	 printf("■");
  else
	 printf("  ");
 printf("  ");
}

void number_check(int k, int i)
{
 if (k>=1)
  {
     number_check(k/10, i); // 123/10 = 12, i = 0은 1line 나옴 재귀하고 보류? 
     						// line 은 0 1 2 3 4 까지 증가 
     switch(k%10)	// 123%10 = 3 >> 재귀 12%10 = 2 >> 재귀 1%10 = 1 
     {
        case 0 : 
	  digit_print(zero, i);
	  break;
        case 1 : 
	  digit_print(one, i);
	  break;
        case 2 : 
	  digit_print(two, i);
	  break;
        case 3 : 
	  digit_print(three, i);
	  break;
        case 4 : 
	  digit_print(four, i);
	  break;
        case 5 : 
	  digit_print(five, i);
	  break;
        case 6 : 
	  digit_print(six, i);
	  break;
        case 7 : 
	  digit_print(seven, i);
	  break;
        case 8 : 
	  digit_print(eight, i);
	  break;
        case 9 : 
          digit_print(nine, i);
	  break;
     }
  }
}
