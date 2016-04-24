#ifndef _RSA_H_

#define _RSA_H_


//包含配置信息的结构 
typedef struct {
	int configuration_from_file;
	int total_number;
}Configuration;


//包含公钥与私钥信息的结构 
typedef struct{
	int Pub_key;
	int Pri_key;
	int n;
}Key;

//初始化程序运行需要的文件 
void Initialize(void); 

//获取从文本读入的配置信息 
void GetConfiguration(void);

//获得公钥和私钥 
Key GetKey(void); 

//将获取的密钥对保存为文本文件 
void SaveKey(Key key); 

//参数为公钥，对文本进行加密 
void encrype(int e,int n);

//参数为私钥，对文本解密 
void decode(int d,int n);

//记录全部字符数量的全局变量 
int Total_Number;

//记录配置信息的全局变量 
Configuration configuration;

#endif 
