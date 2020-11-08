#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

#define TAMANHO 512
#define MAXARGS 63
#define SAIDA "quit"

int main(int argc, char*argv[]){
	for(;;){
		char entrada[TAMANHO+1]={0X0};
		char *p = entrada;
		char *args[MAXARGS+1]={NULL};
		char *args2[MAXARGS+1]={NULL};
		int estado;
		int i=0,j=0,k=1;
		
		//nosso shell
		printf("meu-shell>");
		fgets(entrada, TAMANHO, stdin);
		
		//ignorar input vazio
		if(*p == '\n')continue;
		
		//Convertendo o input para uma lista de argumentos
		for(i;i<sizeof(args)&&*p;p++){
			if(*p == ',' && p[1]=='\n') continue;
			if(*p ==','){
			p=p+1;
			for(args2[j] = p; *p && *p != ' ' && *p != '\n'; p++);
				*p ='\0';
			
			if(strcmp(SAIDA, args2[0])==0) return 0;
			
			signal(SIGINT, SIG_DFL);
			if(fork()==0)exit(execvp(args2[0],args2));
			signal(SIGINT, SIG_IGN);
			printf("terminou\n");	
								
			wait(&estado);
			}
			for(args[i++] = p; *p && *p != ' ' && *p != '\n'; p++);
				*p ='\0';	
		}
		
		if(strcmp(SAIDA, args[0])==0) return 0;
		
		signal(SIGINT, SIG_DFL);
		if(fork()==0) exit(execvp(args[0],args));
		signal(SIGINT, SIG_IGN);
		
		wait(&estado);		
	}
}
