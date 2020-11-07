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
		char *args2[MAXARGS+1]={NULL};
		int estado;
		int i=0,j=0;
		
		//nosso shell
		printf("meu-shell>");
		fgets(entrada, TAMANHO, stdin);
		
		//ignorar input vazio
		if(*p == '\n')continue;
		
		//Convertendo o input para uma lista de argumentos
		for(i;i<sizeof(args)&&*p;p++){
			if(*p ==','){
			p=p+1;
			printf("%c",*p);
			if(*p == ' ') continue;
			if(*p == '\n') break;
			printf("continua\n");
			for(args2[j] = p; *p && *p != ' ' && *p != '\n'; p++);
				*p ='\0';
			printf("ta indo\n");
			signal(SIGINT, SIG_DFL);
			if(fork()==0)exit(execvp(args2[0],args2));
			signal(SIGINT, SIG_IGN);
			printf("terminou\n");	
			wait(&estado);
			}
			if(*p == ' ') continue;
			if(*p == '\n') break;
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
