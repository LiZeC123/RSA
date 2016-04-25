#include <stdio.h>
#include <stdlib.h>
#include "RSA.h"
#include <string.h>
#include <ctype.h>


//打印欢迎信息，并获得用户选择 
static char welcome(void);



int main(int argc, char *argv[]) {
		
	Initialize();
	GetConfiguration();
	
	int n ,e ,d;
	char choose;
		
	choose = welcome();
	 
	if(choose== 'e'){
		printf("Please input Public Key:");
		scanf("%d %d",&e,&n);
		printf("Now the file source.txt will be encryped...\n");
		encrype(e,n);	
		printf("source.txt has been enctyped successful!\n"); 
	}
	else if(choose== 'd'){
		printf("Please input Private Key:");
		scanf("%d %d",&d,&n);
		printf("Now the file result.txt will be decoded...\n");
		decode(d,n);
		printf("result.txt has been decoded successful!\n");
	}
	else if(choose== 'g'){
		Key key;
		key = GetKey();
		SaveKey(key);
		printf("Your Public  Key Is[ %8d %8d ]\n",key.Pub_key,key.n);
		printf("Your Private Key Is[ %8d %8d ]\n",key.Pri_key,key.n);
	}
	
	
	return 0;
}


static char welcome(void){
	char choose;
	puts("############################################");
	puts("Welcome to use Public Key Encryption");
	puts("Enter the letter correspnoding to your choice:");
	puts("e)encrype   d)decode ");
	puts("g)get keys  q)quit   ");
	
	
	while((choose = getchar()) != EOF){
		while(getchar()!='\n'){
			continue;
		}
		choose = tolower(choose);
		if(strchr("edgq",choose) == NULL){
			puts("Please enter an e,d,g or q:");
		}
		else{
			break;
		}
	}
	if(choose == EOF){
		choose = 'q';
	}
	return choose;
}




