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

//����������Ϣ�Ľṹ 
typedef struct {
	int configuration_from_file;
	int total_number;
}Configuration;


//��ʼ������������Ҫ���ļ� 
void Initialize(void); 

//��ȡ���ı������������Ϣ 
void GetConfiguration(void);

//����Ϊ��Կ�����ı����м��� 
void encrype(int e,int n);

//����Ϊ˽Կ�����ı����� 
void decode(int d,int n);

//��¼ȫ���ַ�������ȫ�ֱ��� 
int Total_Number;

//��¼������Ϣ��ȫ�ֱ��� 
Configuration configuration;

#endif 
