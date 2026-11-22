#include <stdio.h>
#include <stdlib.h>

FILE* abrirArq(char nome[], char modo[]);
FILE* fecharArq(FILE *arq);
int main(int argc, char *argv[]) {
	FILE *temp;
	temp=abrirArq("teste.txt","r");
	temp=fecharArq(temp);
	return 0;
}
FILE* abrirArq(char nome[], char modo[]){
	FILE *arq;
	arq=fopen(nome,modo);
	if(arq==NULL)
			printf("\nNao foi possivel abrir o arquivo %s\n",nome);
	
    return arq;
}

FILE* fecharArq(FILE *arq){
	if(arq==NULL)
	printf("\nErro ao fechar o arquivo!\n");
	else
     	fclose(arq);
	
	return arq;
}
