#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>

#define TAMANHO 512
#define MAXARGS 63
#define SAIDA "quit"

int main(){
	for(;;){
		char entradainicial[1000]={0X0};	//Primeiro vetor para entrada
		char entradafinal[TAMANHO+1]={0X0};	//Vetor final que recebe o input da entrada caso seja correto
		char *p = entradainicial;		//Ponteiro
		char *args[MAXARGS+1]={NULL};		//Vetor de argumentos para conversão do input
		char *args2[MAXARGS+1]={NULL};	//Vetor de argumentos para conversão dos inputs que começam com ","
		int estado;				
		int i=0,j=0;				//variáveis iterativas
		
		printf("meu-shell>");			//nome do shell
		fgets(entradainicial,1000,stdin);	//recebendo o input
		while(strlen(entradainicial)>TAMANHO){	//caso o tamanho seja maior que 512 então recebe o erro
				printf("Erro tamanho de entrada excedido\n");
				printf("meu-shell>");
				fgets(entradainicial,1000,stdin);	// Repete até receber um entrada com tamanho menor que 512
		}
		strcpy(entradafinal, entradainicial);			//Copia o valor da entrada
	
		if(*p == '\n')continue;				//ignora o input vazio
		if(*p == ' ') continue;				//ignora o input com espaço vazio
			
		for(i=0;i<TAMANHO+1 &&*p;p++){
			if(*p == ',' && p[1]=='\n') continue;		//tudo desse if é feito para comandos que começam com a ","
			if(*p ==','){					
			p=p+1;
			for(args2[j] = p; *p && *p != ' ' && *p != '\n'; p++);	// convertendo o input para um vetor de argumentos	
			*p ='\0';
			if(strcmp(SAIDA, args2[0])==0) return 0;			//quit
			
			signal(SIGINT, SIG_DFL);
			if(fork()==0)exit(execvp(args2[0],args2));			//fork do processo filho e execução
			signal(SIGINT, SIG_IGN);
								
			wait(&estado);							//espera do fim da execução
			}
			for(args[i++] = p; *p && *p != ' ' && *p != '\n'; p++);	// convertendo o input para um vetor de argumentos
			*p ='\0';	
		}
		
		if(strcmp(SAIDA, args[0])==0) return 0;	//quit
		
		signal(SIGINT, SIG_DFL);
		if(fork()==0) exit(execvp(args[0],args));	//fork do processo filho e execução
		signal(SIGINT, SIG_IGN);
		
		wait(&estado);		//espera do fim da execução
	}
}
