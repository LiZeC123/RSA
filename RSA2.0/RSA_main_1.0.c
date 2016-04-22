#include <stdio.h>
#include <stdlib.h>
#include "RSA.h"


//打印欢迎信息，并获得用户选择 
static char welcome(void);



int main(int argc, char *argv[]) {
		
	Initialize();
	
	
	int p=101,q=103,e=2347,fn=10200,n=10403,d=9283;
	char choose;
	
	choose = welcome();
	 
	if(choose== 'e'){
		printf("Now the file source.txt will be encryped...\n");
		encrype(e,n);	
		printf("source.txt has enctyped successful!\n"); 
	}
	else{
		printf("Now the file result.txt will be decoded");
		decode(d,n);
		
	}
	
	return 0;
}


static char welcome(void){
	char choose;
	printf("Welcome to use Public Key Encryption\n");
	printf("Do you want to encrype or decode(press e for encrype or u for decode):");
	scanf("%c",&choose);
	while(choose!= 'e' && choose != 'u'){
		printf("\nError:%c is not a legal parameter\n",choose);
		//去除缓冲区多余的字符 
		while(getchar()!='\n'){
			continue;
		}
		printf("please press e for encrype or u for decode:");
		scanf("%c",&choose);
	}
	putchar('\n');
	
	return choose;
}




