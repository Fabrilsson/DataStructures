#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
main()
{
	FILE *arquivo;
	char mensagem[100], nome[20], senha[10];
	int chave;
	
	printf("What is the color of night?\n");
	fflush(stdin);
	gets(senha);
	
	if(strcmp(senha,"Sanguine")==0)
	{
		system("cls");
		printf("Digite o nome do arquivo: ");
		fflush(stdin);
		gets(nome);
		
		strcat(nome,".bin");
		
		printf("Digite a chave: ");
		scanf("%i",&chave);
		
		arquivo=fopen(nome,"rb");
		fread(mensagem,100*sizeof(char),1,arquivo);
		
		for (int i=0; i<strlen(mensagem); i++)
		{
			mensagem[i]+=chave;
		}
		
		printf("\nMensagem:\n\n%s",mensagem);
		
		fclose(arquivo);
	}
	else
	{
		abort();
	}
	
	remove(nome);
	getch();
}
