#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>

void intro(); // �߰�  
void move_arrow_key(char chr, int *x, int *y, int x_b, int y_b);
void gotoxy(int x, int y);
void draw_check01(int c, int r);
void game_control(void);
void display_stone(int matrix[][20][20]); // �߰�  
int game_end(int matrix[][20][20]); // �߰�  

void textcolor(int color_number)// �ܼ�â ���� ����  
{
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color_number);
}

int main(void)
{
	system("mode con cols=40 lines=30"); //cols =����lines =����
	//�ܼ� ũ�� ���� 
    intro();
    system("cls"); //ȭ�� �ʱ�ȭ  
    game_control();
    return 0;
}

void intro()
{
	
	printf("������������������������");
    printf("\n");
    printf("�� ���� ���Ӧ�");
    printf("\n");
    printf("������������������������");
    printf("\n");
    printf("�ƹ�Ű�� ��������.");
    textcolor(20); //�Ķ���� ���� ����  
    getch();
}

// Ŀ����ġ ����  
void gotoxy(int x, int y)
{
    COORD Pos = { x - 1, y - 1 };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

//Ű���� ����Ű�� �̵�  
void move_arrow_key(char key, int* x1, int* y1, int x_b, int y_b)
{
    switch (key)
    {
    case 72:  //����(��) ������ ȭ��ǥ Ű �Է�
        *y1 = *y1 - 1;
        if (*y1 < 1)	*y1 = 1; //y��ǥ�� �ּҰ�
        break;
    case 75:  //����(��) ������ ȭ��ǥ Ű �Է�
        *x1 = *x1 - 2;             //������������ 2�� ����
        if (*x1 < 1)	*x1 = 1; //x��ǥ�� �ּҰ�
        break;
    case 77:  //������(��) ������ ȭ��ǥ Ű �Է�
        *x1 = *x1 + 2;               //������������ 2�� ����
        if (*x1 > x_b)  *x1 = x_b; //x��ǥ�� �ִ밪(���)
        break;
    case 80:  //�Ʒ���(��) ������ ȭ��ǥ Ű �Է�
        *y1 = *y1 + 1;
        if (*y1 > y_b)  *y1 = y_b; //y��ǥ�� �ִ밪(���)
        break;
    default:
        return;
    }
}


//�ٵ��� �׸���  
void draw_check01(int c, int r)
{
    int i, j;
    unsigned char a = 0xa6;
    unsigned char b[12];

    for (i = 1; i < 12; i++) //0xa1 0xa11���� ������� ���� 
        b[i] = 0xa0 + i;

    //ù��°�� ��� 	
    printf("%c%c", a, b[3]); // �� �»�� �𼭸� 

    for (i = 0; i < c - 1; i++)
        printf("%c%c", a, b[8]); //��
    printf("%c%c", a, b[4]);// �� ���� �𼭸� 
    printf("\n");

    //�ι�°�ٺ��� ���������� ��� 
    for (i = 0; i < r - 1; i++)
    {
        printf("%c%c", a, b[7]); //��
        for (j = 0; j < c - 1; j++)
            printf("%c%c", a, b[11]); //��
        printf("%c%c", a, b[9]);// ��
        printf("\n");
    }
    //�������� ���  
    printf("%c%c", a, b[6]); // �����ϴ� �𼭸�  
    for (i = 0; i < c - 1; i++)
        printf("%c%c", a, b[10]); //��
    printf("%c%c", a, b[5]); // �� ���ϴ� �𼭸�  
    printf("\n");
}

/*
��   -  0xa1(161) 1

 ��  -  0xa2(162) 2

��   -  0xa3(163) 3

 ��  -  0xa4(164) 4

��   -  0xa5(165) 5

 ��  -  0xa6(166) 6

 ��  -  0xa4(167) 7

��   -  0xa5(168) 8

 ��  -  0xa6(169) 9

 ��  -  0xa4(170) 10

��   -  0xa5(171) 11
*/

//�����ư��鼭 �ٵ� ���� �Լ�
void game_control(void) {
    int x = 1, y = 1, other = 0;
    int matrix[2][20][20] = { 0 };
    char key;
    const char* stone[2] = { "��", "��" };
    
    do
    {
        gotoxy(1, 1);
        draw_check01(18, 18);
        gotoxy(x, y);
        printf("%s", stone[other]);
        display_stone(matrix);
        gotoxy(1, 20);
        printf("����Ű�� �����̰� ");
        printf("�����̽� Ű�� ��������.");
        gotoxy(1, 21);
        printf("���� �������� ���� �����Դϴ�. ");
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
            printf("�浹�� �̰���ϴ�\n");
            break;
        }

        else if (game_end(matrix) == 2)
        {
            gotoxy(1, 24);
            printf("�鵹�� �̰���ϴ�\n");
            break;
        }
    } while (1);
}

 
//�浹 �鵹 �����Ͽ� ��� 
void display_stone(int matrix[][20][20])
{
    int i, x, y;
    const char* stone[2] = { "��", "��" };

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

 

//������ ���� ���� �Ǻ� �Լ�  

int game_end(int matrix[][20][20])
{
        int count = 0;

        //���� 5�� Ȯ��  
        for (int i = 0; i < 2; i++)
        {
               for (int y = 1; y < 20; y++)
               {
                       count = 0; //���ο� ���� ���� count=0���� ����

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


        //���� 5�� Ȯ��  

        for (int i = 0; i < 2; i++)
        {
               for (int x = 1; x < 20; x++)
               {
                       count = 0; //���ο� ���� ���� count=0���� ����

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

        //���������� ������ �Ʒ� �밢�� ��

        for (int i = 0; i < 2; i++)
        {
               for (int x = 1; x < 16; x++) //�밢���̹Ƿ� 15������ �����뼱
               {
                       count = 0; //���ο� �밢���� ���� count=0���� ����

                       for (int y = 1; y < 16; y++) //�밢���̱� ������ 15������ �����뼱
                       {
                              int temp1 = x; //x�� y���� ����
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

        //���� �Ʒ����� ������ �� �밢�� ��

        for (int i = 0; i < 2; i++)
        {
               for (int x = 1; x < 16; x++) //�밢���̹Ƿ� 15������ �����뼱
               {
                       count = 0;
                       
                       for (int y = 5; y < 20; y++) //�밢���̱� ������ 5���� ����
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
        return 0; //������ �� �������� 0 ��ȯ

}
