#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <stdlib.h>
main()
{
	FILE *arquivo;
	char mensagem[100],nome[20],senha[10];
	int chave;
	
	printf("What is the music of life?\n");
	fflush(stdin);
	gets(senha);
	
	if(strcmp(senha,"Silence")==0)
	{
		system("cls");
		printf("Digite a mensagem: ");
		fflush(stdin);
		gets(mensagem);
		
		printf("Digite a chave que deseja utilizar: ");
		scanf("%i",&chave);
		
		printf("Digite o nome do arquivo: ");
		fflush(stdin);
		gets(nome);
		
		strcat(nome,".bin");
		//strcat(mensagem,"\0");
		
		arquivo=fopen(nome,"wb");
		
		for (int i=0; i<strlen(mensagem); i++)
		{
			mensagem[i]-=chave;
		}
		
		fwrite(mensagem,strlen(mensagem)*sizeof(char),1,arquivo);
		
		fclose(arquivo);
	}
	else
	{
		abort();
	}
}
