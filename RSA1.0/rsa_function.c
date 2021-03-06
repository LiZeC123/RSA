#include <stdio.h>
#include <stdlib.h> 
#define MAX_NUMBER 20		//进行二进制 转换时的临时数组的最大限制 
#define BITWIDTH 2			//一次加密处理的字符数 
int total_letter;

int caesar(char c){
	int cae;
	if(c>30){
		c=c-30;
		cae=(int)c;
		return  cae;
	}
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

char arccaesar(int n){
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
	fp_source=fopen("source.txt","r");
	fp_worked=fopen("worked.txt","w+");
	if(fp_source==NULL){
		system("cls");
		printf("fail to open the source file");
		system("pause");
		exit(1);
	}
	

	total_letter=0;
	while(1){
		c_work=getc(fp_source);
		n_work=caesar(c_work);
		if(n_work!= -1){
			fprintf(fp_worked,"%d\n",n_work);
			total_letter++;
		}
		else{
			break;
		}	
	}
	fclose(fp_source);		
	fp_source=NULL;
	while(total_letter%BITWIDTH!=0){
		fprintf(fp_worked,"%d\n",2);
		total_letter++;
	}
	fclose(fp_worked);
	fp_worked=NULL;
}

void encrype(int e,int n){
	pre_treat();
	FILE *fp_worked;
	FILE *fp_result;
	fp_worked=fopen("worked.txt","r");
	if(fp_worked==NULL){
		system("cls");
		printf("fail to open the worked file");
		system("pause");
		exit(2);
	}

	fp_result=fopen("result.txt","w");
	int i,m,rsa_c1,rsa_c2,rsa_c,result;
	for(i=0;i<total_letter;i=i+2){
		fscanf(fp_worked,"%d",&rsa_c1);
		fscanf(fp_worked,"%d",&rsa_c2);
		rsa_c=rsa_c1*100+rsa_c2;
		result=rsa(rsa_c,e,n);
		fprintf(fp_result,"%d\n",result);
	}
	fclose(fp_result);
	fp_result=NULL;
}

static void aft_treat(){
	FILE *fp_worked;
	FILE *fp_source;
	int source_c,source_c1,source_c2;
	fp_worked=fopen("worked.txt","r");
	fp_source=fopen("source.txt","w");
	while(fscanf(fp_worked,"%d",&source_c)>0){
		source_c1=source_c/100;
		source_c2=source_c%100;
		fprintf(fp_source,"%c",arccaesar(source_c1));
		fprintf(fp_source,"%c",arccaesar(source_c2));
	}
	fclose(fp_source);
	fclose(fp_worked);
	fp_source=NULL;
	fp_worked=NULL;
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


