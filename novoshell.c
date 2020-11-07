#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

#define TAMANHO 512
#define MAXARGS 63
#define SAIDA "quit"

int main(void){
	for(;;){
		char entrada[TAMANHO+1]={0X0};
		char *p = entrada;
		char *args[MAXARGS+1]={NULL};
		int estado;
		
		//nosso shell
		printf("meu-shell>");
		fgets(entrada, TAMANHO, stdin);
		
		//ignorar input vazio
		if(*p == '\n'){
			continue;
		}
		//Convertendo o input para uma lista de argumentos
		for(int i=0;i<sizeof(args)&&*p;p++){
			if(*p == ' '){ 
				continue;
			}
			if(*p == '\n'){
				break;
			}
			for(args[i++]= p; *p && *p != ' ' && *p != '\n'; p++){
				*p ='\0';
			}
		}
		//se o usuário digitar quit então o programa fecha
		if(strcmp(SAIDA, args[0])==0){
			return 0;
		}
		//fork child and execute program
		signal(SIGINT, SIG_DFL);
		if(fork()==0){
			exit(execvp(args[0],args));
		}
		signal(SIGINT, SIG_IGN);
		
		wait(&estado);
		
	}
	
}

