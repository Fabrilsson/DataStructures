#include <stdio.h>
#include <stdlib.h>

//PROTOTIPA��O---------------------------------------



//MODULARIZA��O-------------------------------------



main (void){
	
	FILE *arquivo;
	char abertura[50],fechar[50];
	int cont;
	
	printf("Digite o nome de abertura do arquivo: ");
	fflush(stdin);
	gets(abertura);
	
	arquivo = fopen(abertura,"w");
	
	if (arquivo==0){
		
		system("cls");
		printf("Erro na abertura do arquivo");
		
	}
	
	else{
		
		for(cont=0;cont<10;cont++){
			
			int num;
			
			printf("Digite o numero que voc� quer gravar: ");
			scanf("%i",&num);
			
			fprintf(arquivo,"%i \n",num);
			
		}
		
	}
	
}
