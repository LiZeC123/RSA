#ifndef _RSA_H_

#define _RSA_H_
//���ж����� ת��ʱ����ʱ������������ 
#define MAX_NUMBER 20
		
//һ�μ��ܴ�����ַ��� 
#define BITWIDTH 2
			
//���μ��ܵ���ĸ����
#define BITWIDTH 2 
      
//������������ķ�Χ 
#define L_MIT 100		
#define R_MIT 173 


void create_primer_number(void);

//���ô˺���ǰ����ȷ��primer_number.txt���� 
void create_configuration(void);



void encrype(int e,int n);

void decode(int d,int n);

int caesar(char c);
char arccaesar(int n);

int total_letter;
#endif 
