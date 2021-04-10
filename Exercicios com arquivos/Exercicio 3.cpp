#include <stdio.h>
#include <stdlib.h>

//PROTOTIPAÇÃO------------------------------------------



//MODULARIZAÇÃO----------------------------------------




main (void){
	
	FILE *arquivo;
	char nome[30];
	int cont;
	char num;
	
	printf("Digite o nome do arquivo: ");
	gets(nome);
	
	arquivo = fopen(nome,"w");
	
	if(arquivo==0){
		
		printf("Arquivo desconhecido");
		
	}
	else{
		
		for (cont=100;cont<=200;cont++){
			
			if(cont%4==0){
				
				fprintf(arquivo,"%i\n",cont);
				
			}
			
		}
		
	}
	
	fclose(arquivo);
	arquivo=fopen(nome,"r");
	
	int leitura;
	
	while (!feof(arquivo)){
		
		leitura = fgetc(arquivo);
			
		if (leitura != EOF){
			
			
			printf("%c",leitura);
			
		}
		
	}
	
	fclose(arquivo);
	
}
