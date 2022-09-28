#include <stdio.h>
#include <conio.h>
#include <math.h>
void serial_number(long number);
void reverse_number(long number);

int main(void)
{
   long number=12345698;
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
   int num;
   int i, length=0;
   length=(int)(log10(number)+1);  // log10 해서 8자리 +1  length=9 
   for(i=length;i>=1;i--)
   {
     num=number/(long) pow(10, i-1); // 12345698 / 10000000  num = 1
     printf("%ld\n", num);
     number=number-num*(long) pow(10,i-1); // 12345698 - 1*10000000 = 2345698
    }
    printf("\n");
}

void reverse_number(long number)
{
   while(number>0)
   {
	   printf("%ld\n", number%10); // 12345698 % 10 = 8
	   number/=10;
   }
}
