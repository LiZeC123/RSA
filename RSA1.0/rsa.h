#ifndef RSA_H

#define RSA_H
#define MAX_NUMBER 20		//���ж����� ת��ʱ����ʱ������������ 
#define BITWIDTH 2			//һ�μ��ܴ�����ַ��� 

void encrype(int e,int n);

void decode(int d,int n);

int caesar(char c);
char arccaesar(int n);

int total_letter;
#endif 
