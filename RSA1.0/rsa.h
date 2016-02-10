#ifndef RSA_H

#define RSA_H
#define MAX_NUMBER 20		//进行二进制 转换时的临时数组的最大限制 
#define BITWIDTH 2			//一次加密处理的字符数 

void encrype(int e,int n);

void decode(int d,int n);

int caesar(char c);
char arccaesar(int n);

int total_letter;
#endif 
