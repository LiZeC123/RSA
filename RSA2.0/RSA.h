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

//��ʼ������������Ҫ���ļ� 
void Initialize(void); 

//����Ϊ��Կ�����ı����м��� 
void encrype(int e,int n);

//����Ϊ˽Կ�����ı����� 
void decode(int d,int n);

int total_letter;
#endif 
