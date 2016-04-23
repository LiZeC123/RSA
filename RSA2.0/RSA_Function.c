#include <stdio.h>
#include <stdlib.h> 
#include <math.h>
#include <stdbool.h>
#include "RSA.h"





//计算素数表中素数的总数 
static int GetTotalNumber(void);

//如果文件不存在，自动打印错误信息，并结束程序 
//存在，则返回对应的文件指针 
static FILE * Sfopen(char * filename); 

//计算一个单位长度的内容的RSA密文 
static int rsa(int m,int e,int n); 

//加密前对初始文本格式化处理 
static void pre_treat(void);

//解密后对文本进行格式化处理 
static void aft_treat();

//将字符转化为数字编码 
static int caesar(char c);

//将数字编码转化为字符 
static char arccaesar(int n); 

//创建初始素数表 
static void create_primer_number(void);

//创建初始配置信息表 
static void create_configuration(void);


void Initialize(void){ 
	FILE *fp_primer_number;
	FILE *fp_configuration;
	
	fp_primer_number = fopen("primer_number.txt","r");
	fp_configuration = fopen("configuration.txt","r");
	
	if(fp_primer_number == NULL){
		create_primer_number();
	}	
		
	if(fp_configuration == NULL){
		create_configuration();
	}
	
	fclose(fp_primer_number);
	fclose(fp_configuration);
	
}

void GetConfiguration(void){
	FILE * fp_configuration;
	fp_configuration = Sfopen("configuration.txt");
	fscanf(fp_configuration,"[configuration from file] = %d\n",&configuration.configuration_from_file);
	fscanf(fp_configuration,"[total number] = %d",&configuration.total_number);
	fclose(fp_configuration);
} 





void encrype(int e,int n){
	pre_treat();
	FILE *fp_worked;
	FILE *fp_result;
	fp_worked=Sfopen("worked.txt");
	fp_result=fopen("result.txt","w");
	
	int i,m,rsa_c1,rsa_c2,rsa_c,result;
	for(i=0;i<Total_Number;i=i+2){
		fscanf(fp_worked,"%d",&rsa_c1);
		fscanf(fp_worked,"%d",&rsa_c2);
		rsa_c=rsa_c1*100+rsa_c2;
		result=rsa(rsa_c,e,n);
		fprintf(fp_result,"%d\n",result);
	}
	
	fclose(fp_result);
	fclose(fp_worked);
	
	system("rm -f worked.txt"); 
}


void decode(int d,int n){
	FILE *fp_result;
	FILE *fp_worked;
	int n_result,c_work;
	fp_result=fopen("result.txt","r");
	fp_worked=fopen("worked.txt","w+");
	while(fscanf(fp_result,"%d",&n_result)>0){
		c_work=rsa(n_result,d,n);
		fprintf(fp_worked,"%d\n",c_work);		
	}
	fclose(fp_result);
	fclose(fp_worked);
	fp_result=NULL;
	fp_worked=NULL;
	aft_treat();
}


static void create_primer_number(void){
	int i,j;
	bool flag;
	FILE *fp_primer_number;
	fp_primer_number=fopen("primer_number.txt","w");
	
	printf("Create primer number...\n");
	for(i=L_MIT;i<R_MIT;i++){
		flag=true;
		if(i%2==0){
			flag=false;
			continue;
		}
		for(j=3;j<(sqrt(i)+1);j++){
			if(i%j==0){
				flag=false;
			}
		}
		if(flag==true){
			fprintf(fp_primer_number,"%d\n",i);
		}
	}
	
	fclose(fp_primer_number);
	printf("primer number done !\n");
}

static void create_configuration(void){
	FILE *fp_configuration;
	fp_configuration=fopen("configuration.txt","w");
	
	printf("Create configuration...\n");
	fprintf(fp_configuration,"[configuration from file] = 1\n");
	fprintf(fp_configuration,"[total number] = %d",GetTotalNumber());

	fclose(fp_configuration);
	printf("configuration done !\n");
}

static FILE * Sfopen(char * filename){
	FILE *fp = fopen(filename,"r");
	if(fp == NULL){
		fprintf(stderr,"Error :");
		fprintf(stderr,filename);
		fprintf(stderr," is not exist!\n");
		
		FILE * fp_error;
		fp_error = fopen("Error.txt","w");
		
		fprintf(fp_error,"Error :");
		fprintf(fp_error,filename);
		fprintf(fp_error," is not exist!\n");
		
		fclose(fp_error);
		
		exit(1);
	}

	return fp;
}

static int GetTotalNumber(void){
	FILE *fp_primer_number;
	int count=0;
	int temp;
	
	fp_primer_number=Sfopen("primer_number.txt");
	
	while(fscanf(fp_primer_number,"%d",&temp)>0){
		count++;
	}
	
	fclose(fp_primer_number);
	return count;
}

static int caesar(char c){
	int cae;
	if(c>30){
		c=c-30;
		cae=(int)c;
		return  cae;
	}
	//第一个可见的一般字符从32开始，将前两个数字分配给\n与\t 
	else if(c=='\n'){
		return 0;
	}
	else if(c=='\011'){
		return 1;
	}
	else{
		return -1;
	}
}

static char arccaesar(int n){
	int c;
	if(n==0){
		return '\n';
	}
	else if(n==1){
		return '\011';
	}
	else{
		n=n+30;
		c=(char)n;
		return c;
	}
}

static int rsa(int m,int e,int n){
	int bin_edx=0,i;
	int x=1,power;
	int binary[MAX_NUMBER];
	while(e>0){
		binary[bin_edx]=e%2;
		e=e/2;
		bin_edx++;
	}
	
	power=m%n;
	for(i=0;i<bin_edx;i++){
		if(binary[i]==1){
			x=(x*power)%n;
		}
		power=power*power;
		power=power%n;
	}
	return x;
}

static void pre_treat(void){
	char c_work;
	int n_work;
	FILE *fp_source;
	FILE *fp_worked;
	
	fp_source=Sfopen("source.txt");
	fp_worked=fopen("worked.txt","w+");

	
	Total_Number=0;
	n_work = 0 ;
	while(1){
		c_work=getc(fp_source);
		n_work=caesar(c_work);
		if(n_work!= -1){
			fprintf(fp_worked,"%d\n",n_work);
			Total_Number++;
		}
		else{
			break;
		}	
	}
	fclose(fp_source);		
	fp_source=NULL;
	while(Total_Number%BITWIDTH!=0){
		fprintf(fp_worked,"%d\n",2);
		Total_Number++;
	}
	fclose(fp_worked);
	fp_worked=NULL;
}

static void aft_treat(){
	FILE *fp_worked;
	FILE *fp_source;
	int source_c,source_c1,source_c2;
	fp_worked=Sfopen("worked.txt");
	fp_source=fopen("source.txt","w");
	while(fscanf(fp_worked,"%d",&source_c)>0){
		source_c1=source_c/100;
		source_c2=source_c%100;
		fprintf(fp_source,"%c",arccaesar(source_c1));
		fprintf(fp_source,"%c",arccaesar(source_c2));
	}
	fclose(fp_source);
	fclose(fp_worked);
	
	system("rm -f worked.txt"); 
}
