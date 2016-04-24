#ifndef _RSA_H_

#define _RSA_H_


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

//����ȡ����Կ�Ա���Ϊ�ı��ļ� 
void SaveKey(Key key); 

//����Ϊ��Կ�����ı����м��� 
void encrype(int e,int n);

//����Ϊ˽Կ�����ı����� 
void decode(int d,int n);

//��¼ȫ���ַ�������ȫ�ֱ��� 
int Total_Number;

//��¼������Ϣ��ȫ�ֱ��� 
Configuration configuration;

#endif 
