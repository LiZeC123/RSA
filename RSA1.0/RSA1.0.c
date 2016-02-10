#include <stdio.h>
#include <stdlib.h>
#include "rsa.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(int argc, char *argv[]) {
	int p=101,q=103,e=2347,fn=10200,n=10403,d=9283;
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
	 
	if(choose== 'e'){
		printf("Now the file source.txt will be encryped");
		encrype(e,n);	
	}
	else{
		printf("Now the file result.txt will be decoded");
		decode(d,n);
		
	}
	encrype(e,n);
	return 0;
}

