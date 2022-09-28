#include <stdio.h>
#include <conio.h>
#include <math.h>
void serial_number(long number);
void reverse_number(long number);

int main(void)
{
   long number=123;
   printf("입력 숫자 : %ld\n\n", number);
   printf("높은 단위부터 출력\n");
   serial_number(number);
   printf("\n낮은 단위부터 출력\n");
   reverse_number(number);
printf("press any key to continue.......");
getch();
   return 0;
}


void serial_number(long number)
{
  if (number>0)
  {
     serial_number(number/10);	// number/10 = 12 나옴. 재귀하고 12/10 = 1... 
     printf("%ld\n", number%10); // number%10 = 3 결과값은 보류... 2보류..1출력 
  }
  else
     return;
}

void reverse_number(long number)
{
	printf("%ld\n", number%10); // 3
	if((number/10)>0) //123/10 = 12이고 12>0 
		reverse_number(number/10); // 12 보류  
        else
                return;
}
