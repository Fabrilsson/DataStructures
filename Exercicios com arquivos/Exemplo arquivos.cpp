#include<stdio.h>
#include<stdlib.h>
int main(){
FILE *arquivo; //vai ser associada ao arquivo
arquivo = fopen("desktop/texto.txt","r");
if(arquivo==0)
printf("Erro na leitura do arquivo\n");
else
printf("Arquivo aberto com sucesso\n");
fclose(arquivo); //fecha arquivo
system("pause");
}
