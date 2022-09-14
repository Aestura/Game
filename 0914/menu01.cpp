#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int menu_display(void);
void hamburger(void);
void spaghetti(void);
void press_any_key(void);
int main(void)
{
	int c;
	while((c=menu_display()) != 3)
	{
	switch(c)
	{
	case 1 : hamburger();
		break;
	case 2 : spaghetti();
		break;
	default : break;
	}
	}
	return 0;
}

int menu_display(void)
{
	int select;
	system("cls");
		printf("간식 만들기\n\n");
		printf("1. 햄버거 \n");
		printf("2. 스파게티\n");
		printf("3. 프로그램 종료\n\n");
		printf("메뉴번호 입력>");
	select=getch()-48; // 문자를 숫자로 바꿔줌 연산하려고 
	return select;
}

void hamburger(void)
{
	system("cls");
	printf("햄버거 만드는 방법\n");
	printf("중략\n");
	press_any_key();
}
void spaghetti(void)
{
	system("cls");
	printf("스파게티 만드는 방법\n");
	printf("중략\n");
	press_any_key();
}
void press_any_key(void)
{
	printf("\n\n");
	printf("아무키나 누르면 메인 메뉴로...");
	getch();
}


