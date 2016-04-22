#include <stdio.h>
#include <stdlib.h>
#include "RSA.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
static char welcome(void);


int main(int argc, char *argv[]) {
	int p=101,q=103,e=2347,fn=10200,n=10403,d=9283;
	char choose;
	
	choose = welcome();
	 
	if(choose== 'e'){
		printf("Now the file source.txt will be encryped");
		encrype(e,n);	
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
		printf("\nerror:%c is not a legal parameter\n",choose);
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
