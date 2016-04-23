#ifndef _RSA_H_

#define _RSA_H_
//���ж����� ת��ʱ����ʱ������������ 
#define MAX_NUMBER 20
		
//һ�μ��ܴ�����ַ��� 
#define BITWIDTH 2
			
//���μ��ܵ���ĸ����
#define BITWIDTH 2 
      
//������������ķ�Χ 
#define L_MIT 1000		
#define R_MIT 1500 

//����������Ϣ�Ľṹ 
typedef struct {
	int configuration_from_file;
	int total_number;
}Configuration;


//������Կ��˽Կ��Ϣ�Ľṹ 
typedef struct{
	int Pub_key;
	int Pri_key;
	int n;
}Key;

//��ʼ������������Ҫ���ļ� 
void Initialize(void); 

//��ȡ���ı������������Ϣ 
void GetConfiguration(void);

//��ù�Կ��˽Կ 
Key GetKey(void); 

//����Ϊ��Կ�����ı����м��� 
void encrype(int e,int n);

//����Ϊ˽Կ�����ı����� 
void decode(int d,int n);

//��¼ȫ���ַ�������ȫ�ֱ��� 
int Total_Number;

//��¼������Ϣ��ȫ�ֱ��� 
Configuration configuration;

#endif 
