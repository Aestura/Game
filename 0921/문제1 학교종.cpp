#include <stdio.h>
#include <math.h>
#include <windows.h>
int calc_frequency(int octave, int inx);
int main(void)
{
	int index[]={0, 2, 4, 5, 7, 9, 11, 12};
	int freq[8];
	int i;
	
	freq[7]=calc_frequency(4, index[7]);
	Beep(freq[7],300);
	printf("��");
	
	freq[7]=calc_frequency(4, index[7]);
	Beep(freq[7],300);
	printf("��");
	
	freq[9]=calc_frequency(4, index[9]);
	Beep(freq[9],300);
	printf("��");
	
	freq[9]=calc_frequency(4, index[9]);
	Beep(freq[9],300);
	printf("��"); 
	
	freq[7]=calc_frequency(4, index[7]);
	Beep(freq[7],300);
	printf("��");
	
	freq[7]=calc_frequency(4, index[7]);
	Beep(freq[7],300);
	printf("��");
	
	freq[4]=calc_frequency(4, index[4]);
	Beep(freq[4],300);
	printf("��\n");
	
	//�ֶּ�� �ֹּ�  
	 
	freq[7]=calc_frequency(4, index[7]);
	Beep(freq[7],300);
	printf("��");
	
	freq[7]=calc_frequency(4, index[7]);
	Beep(freq[7],300);
	printf("��");
	
	freq[4]=calc_frequency(4, index[4]);
	Beep(freq[4],300);
	printf("��");
	
	freq[4]=calc_frequency(4, index[4]);
	Beep(freq[4],300);
	printf("��");
	
	freq[2]=calc_frequency(4, index[2]);
	Beep(freq[2],300);
	printf("��\n");
	
	//�̷ֹּ̹� 
	
	freq[7]=calc_frequency(4, index[7]);
	Beep(freq[7],300);
	printf("��");
	
	freq[7]=calc_frequency(4, index[7]);
	Beep(freq[7],300);
	printf("��");
	
	freq[9]=calc_frequency(4, index[9]);
	Beep(freq[9],300);
	printf("��");
	
	freq[9]=calc_frequency(4, index[9]);
	Beep(freq[9],300);
	printf("��"); 
	
	freq[7]=calc_frequency(4, index[7]);
	Beep(freq[7],300);
	printf("��");
	
	freq[7]=calc_frequency(4, index[7]);
	Beep(freq[7],300);
	printf("��");
	
	freq[4]=calc_frequency(4, index[4]);
	Beep(freq[4],300);
	printf("��\n");
	
	//�ֶּ�� �ֹּ�
	
	freq[7]=calc_frequency(4, index[7]);
	Beep(freq[7],300);
	printf("��");
	
	freq[4]=calc_frequency(4, index[4]);
	Beep(freq[4],300);
	printf("��");
	
	freq[2]=calc_frequency(4, index[2]);
	Beep(freq[2],300);
	printf("��");
	
	freq[4]=calc_frequency(4, index[4]);
	Beep(freq[4],300);
	printf("��");
	
	freq[0]=calc_frequency(4, index[0]);
	Beep(freq[0],300);
	printf("��");
	
	//�̷ֹ��̵� 
		
	return 0;
}


int calc_frequency(int octave, int inx)
{
	double do_scale=32.7032;
	double ratio=pow(2., 1/12.), temp;
	int i;
	temp=do_scale*pow(2, octave-1);
	for(i=0;i<inx;i++)
	{
		temp=(int)(temp+0.5);
		temp*=ratio;
	}
	return (int) temp;
}

