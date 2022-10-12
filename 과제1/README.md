오목 프로그램
=================================================================================

```
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
```
```
void intro(); // 추가  
void move_arrow_key(char chr, int *x, int *y, int x_b, int y_b);
void gotoxy(int x, int y);
void draw_check01(int c, int r);
void game_control(void);
void display_stone(int matrix[][20][20]); // 추가  
int game_end(int matrix[][20][20]); // 추가  
```
```
void textcolor(int color_number)// 콘솔창 색상 조절  
{
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color_number);
}
```
```
int main(void)
{
	system("mode con cols=40 lines=30"); //cols =가로lines =세로
	//콘솔 크기 조절 
    intro();
    system("cls"); //화면 초기화  
    game_control();
    return 0;
}
```
//인트로 화면
```
void intro()
{
	
    printf("┌──────────┐");
    printf("\n");
    printf("│ 오목 게임│");
    printf("\n");
    printf("└──────────┘");
    printf("\n");
    printf("아무키나 누르세요.");
    textcolor(20); //파랑배경 빨강 글자  
    getch();
}
```

// 커서위치 제어  
```
void gotoxy(int x, int y)
{
    COORD Pos = { x - 1, y - 1 };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
```

//키보드 방향키로 이동  
```
void move_arrow_key(char key, int* x1, int* y1, int x_b, int y_b)
{
    switch (key)
    {
    case 72:  //위쪽(상) 방향의 화살표 키 입력
        *y1 = *y1 - 1;
        if (*y1 < 1)	*y1 = 1; //y좌표의 최소값
        break;
    case 75:  //왼쪽(좌) 방향의 화살표 키 입력
        *x1 = *x1 - 2;             //좌측방향으로 2씩 감소
        if (*x1 < 1)	*x1 = 1; //x좌표의 최소값
        break;
    case 77:  //오른쪽(우) 방향의 화살표 키 입력
        *x1 = *x1 + 2;               //우측방향으로 2씩 증가
        if (*x1 > x_b)  *x1 = x_b; //x좌표의 최대값(경계)
        break;
    case 80:  //아래쪽(하) 방향의 화살표 키 입력
        *y1 = *y1 + 1;
        if (*y1 > y_b)  *y1 = y_b; //y좌표의 최대값(경계)
        break;
    default:
        return;
    }
}
```

//바둑판 그리기  
```
void draw_check01(int c, int r)
{
    int i, j;
    unsigned char a = 0xa6;
    unsigned char b[12];

    for (i = 1; i < 12; i++) //0xa1 0xa11까지 순서대로 저장 
        b[i] = 0xa0 + i;

    //첫번째줄 출력 	
    printf("%c%c", a, b[3]); // ┌ 좌상단 모서리 

    for (i = 0; i < c - 1; i++)
        printf("%c%c", a, b[8]); //┬
    printf("%c%c", a, b[4]);// ┐ 우상단 모서리 
    printf("\n");

    //두번째줄부터 마지막전줄 출력 
    for (i = 0; i < r - 1; i++)
    {
        printf("%c%c", a, b[7]); //├
        for (j = 0; j < c - 1; j++)
            printf("%c%c", a, b[11]); //┼
        printf("%c%c", a, b[9]);// ┤
        printf("\n");
    }
    //마지막열 출력  
    printf("%c%c", a, b[6]); // ┘우하단 모서리  
    for (i = 0; i < c - 1; i++)
        printf("%c%c", a, b[10]); //┴
    printf("%c%c", a, b[5]); // └ 좌하단 모서리  
    printf("\n");
}
```
/*
─   -  0xa1(161) 1

 │  -  0xa2(162) 2

┌   -  0xa3(163) 3

 ┐  -  0xa4(164) 4

└   -  0xa5(165) 5

 ┘  -  0xa6(166) 6

 ├  -  0xa4(167) 7

┬   -  0xa5(168) 8

 ┤  -  0xa6(169) 9

 ┴  -  0xa4(170) 10

┼   -  0xa5(171) 11
*/

//번갈아가면서 바둑 놓는 함수
```
void game_control(void) {
    int x = 1, y = 1, other = 0;
    int matrix[2][20][20] = { 0 };
    char key;
    const char* stone[2] = { "○", "●" };
    
    do
    {
        gotoxy(1, 1);
        draw_check01(18, 18);
        gotoxy(x, y);
        printf("%s", stone[other]);
        display_stone(matrix);
        gotoxy(1, 20);
        printf("방향키로 움직이고 ");
        printf("스페이스 키를 누르세요.");
        gotoxy(1, 21);
        printf("돌을 놓았으면 상대방 차례입니다. ");
        key = getch();
        
        if (key == 27)
            exit(0);

        else if (key == 32)
        {
            matrix[other][(x + 1) / 2][y] = 1;
            other = 1 - other;
        }

        else if (key >= 72)
            move_arrow_key(key, &x, &y, 37, 19);
            
        if (game_end(matrix) == 1)
        {
            gotoxy(1, 24);
            printf("흑돌이 이겼습니다\n");
            break;
        }

        else if (game_end(matrix) == 2)
        {
            gotoxy(1, 24);
            printf("백돌이 이겼습니다\n");
            break;
        }
    } while (1);
}
```
 
//흑돌 백돌 구분하여 출력 
```
void display_stone(int matrix[][20][20])
{
    int i, x, y;
    const char* stone[2] = { "○", "●" };

    for (i = 0; i < 2; i++)
        for (x = 1; x < 20; x++)
            for (y = 1; y < 20; y++)
            {
                if (matrix[i][x][y] == 1)
                {
                    gotoxy(x * 2 - 1, y);
                    printf("%s", stone[i]);
                }
            }
}
```
 

//오목의 승패 갈림 판별 함수  
```
int game_end(int matrix[][20][20])
{
        int count = 0;

        //가로 5개 확인  
        for (int i = 0; i < 2; i++)
        {
               for (int y = 1; y < 20; y++)
               {
                       count = 0; //새로운 줄일 때는 count=0으로 시작

                       for (int x = 1; x < 20; x++)
                       {
                              if (matrix[i][x][y])
                                      count++;
                                      
                              else
                                      count = 0;

                              if (count == 5)
                                      return (i + 1);
                       }
               }
        }


        //세로 5개 확인  

        for (int i = 0; i < 2; i++)
        {
               for (int x = 1; x < 20; x++)
               {
                       count = 0; //새로운 줄일 때는 count=0으로 시작

                       for (int y = 1; y < 20; y++)
                       {
                              if (matrix[i][x][y])
                                      count++;

                              else
                                      count = 0;

                              if (count == 5)
                                      return (i + 1);
                       }
               }
        }

        //왼쪽위에서 오른쪽 아래 대각선 ↘

        for (int i = 0; i < 2; i++)
        {
               for (int x = 1; x < 16; x++) //대각선이므로 15까지가 마지노선
               {
                       count = 0; //새로운 대각선일 때는 count=0으로 시작

                       for (int y = 1; y < 16; y++) //대각선이기 때문에 15까지가 마지노선
                       {
                              int temp1 = x; //x와 y값을 저장
                              int temp2 = y;

                              for (int j = 0; j < 5; j++)
                              {
                                      if (matrix[i][temp1++][temp2++])
                                              count++;

                                      else
                                              count = 0;
                              }
                              
                              if (count == 5)
                                      return (i + 1);
                       }
               }
        }

        //왼쪽 아래에서 오른쪽 위 대각선 ↗

        for (int i = 0; i < 2; i++)
        {
               for (int x = 1; x < 16; x++) //대각선이므로 15까지가 마지노선
               {
                       count = 0;
                       
                       for (int y = 5; y < 20; y++) //대각선이기 때문에 5부터 시작
                       {
                              int temp1 = x;
                              int temp2 = y;

                              for (int j = 0; j < 5; j++)
                              {
                                      if (matrix[i][temp1++][temp2--])
                                              count++;

                                      else
                                              count = 0;
                              }
                              
                              if (count == 5)
                                      return (i + 1);
                       }
               }
        }
        return 0; //게임이 안 끝났으면 0 반환

}
```
