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


void create_primer_number(void);

//调用此函数前必须确认primer_number.txt存在 
void create_configuration(void);



void encrype(int e,int n);

void decode(int d,int n);

int caesar(char c);
char arccaesar(int n);

int total_letter;
#endif 
