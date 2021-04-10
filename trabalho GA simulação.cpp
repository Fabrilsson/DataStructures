#include <stdlib.h>
#include <stdio.h>

//Prototipação----------------------------------------------------------



//Modularização---------------------------------------------------------

void menu (int **opcao){
	
	printf("1-Simulacao 2-Registros 3-Sair");
	scanf("%i",&*opcao);
		
}

void escolha (int *opcao){
	
	switch(*opcao){
		
		case (1): {
		
			
			FILE *balconistas;
			char balcoes;
			
			if((balconistas=fopen("b.txt","r"))==NULL)
			
			printf("Erro na abertura do arquivo dos balconistas");
			
			else{
			
			balcoes=fgetc(balconistas);
			
			while(balcoes!=EOF){
			printf("%c",balcoes);
			balcoes=fgetc(balconistas);
			}
			}
			
			break;
		
		}
	}
	
}

main (void){
	
	int *opcao;
	
	opcao=(int *)malloc(sizeof(int));
	
	menu(&opcao);	
	
	escolha(opcao);
	
}
