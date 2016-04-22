#ifndef _RSA_H_

#define _RSA_H_
//进行二进制 转换时的临时数组的最大限制 
#define MAX_NUMBER 20
		
//一次加密处理的字符数 
#define BITWIDTH 2
			
//单次加密的字母数量
#define BITWIDTH 2 
      
//定义随机素数的范围 
#define L_MIT 100		
#define R_MIT 173 

//初始化程序运行需要的文件 
void Initialize(void); 

//参数为公钥，对文本进行加密 
void encrype(int e,int n);

//参数为私钥，对文本解密 
void decode(int d,int n);

int total_letter;
#endif 
