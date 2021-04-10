#include <stdio.h>
#include <stdlib.h>

typedef struct{
	
	char nome[50], ende[50];
	int idade;
	
}CLIENTE;

main (void){
	
	FILE *arquivo;
	CLIENTE pessoa[5];
	int cont;
	
	arquivo=fopen("texto.txt","w");
	
	for(cont=0;cont<1;cont++){
	
		fflush(stdin);
		printf("\nDigite o seu nome: \n");
		gets(pessoa[cont].nome);
		
		fflush(stdin);
		printf("\nDigite o seu endereço: \n");
		gets(pessoa[cont].ende);
	
		printf("\nDigite sua idade: \n");
		scanf("%i",&pessoa[cont].idade);
	
		fprintf(arquivo,"%s;%s;%i",pessoa[cont].nome,pessoa[cont].ende,pessoa[cont].idade);
	
	}
	
	fclose(arquivo);
	arquivo=fopen("texto.txt","r");
	
	while (!feof(arquivo)){
		
		char name[50], end[50];
		int age,leitura;
		
		leitura=fscanf(arquivo,"%s;%s;%i;",&name,&end,&age);
		
		if(leitura!=EOF){
			
			printf("Nome: %s",end);
			
		}
		
	}
	
}
