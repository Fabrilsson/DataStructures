//copia o conteudo do arquivo tmp.txt em tmpCopy.txt
#include<stdio.h>
#include<stdlib.h>
#define MAX 80
main(){
int ch;
char linha[MAX], entrada[30], saida[30];
FILE *input, *output;
// uma forma de copiar (linha a linha)

printf("digite o nome do arquivo de entrada: ");
fflush(stdin);
gets(entrada);
printf("digite o nome do arquivo de saida: ");
fflush(stdin);
gets(saida);

input = fopen( entrada, "r" );
if(input){
output = fopen( saida, "w" );
fgets(linha, MAX, input);
while(!feof(input) ) {
fputs( linha, output );
fgets(linha, MAX, input);
}
fputs( linha, output ); //para escrever a ultima linha (do EOF)
fclose( input );
fclose( output );
}
else printf ("deu erro na abertura do arquivo texto.txt\n");
system("pause");
}
