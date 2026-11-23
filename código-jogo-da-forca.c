#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

FILE* abrirArq(char nome[], char modo[]);
FILE* fecharArq(FILE *arq);
void adicionarDica();

int main(int argc, char *argv[]) {
	FILE *temp;
	temp=abrirArq("dicas.fc","a");
	temp=fecharArq(temp);
	adicionarDica();
	return 0;
}
void adicionarDica(){
	char dica[201];
	char temp [201];
	char resp;
	bool erro=false;
	do{
		
		system("cls");
		printf("DIGITE UMA DICA DE ATE 200 CARACTERES:  ");
		fflush(stdin);
	    scanf("%200[^\n]",dica);
	    printf("DESEJA CONTINUAR COM A DICA %s? <S/N>",dica);
		fflush(stdin);
		scanf(" %c", &resp);
		
	}while(resp != 'S' && resp != 'N');
		if(resp == 'N'){
		printf("\nDica cancelada.\n");
		return;
	}
	FILE *arq;
	strupr(dica);
	arq=abrirArq("dicas.fc","r");
	while(fscanf(arq,"%200[^\n]\n", temp)==1){
    if(strcmp(dica,temp)==0){
        printf("\nEssa dica ja existe!");
        erro=true;
        break;
    }
		
}

arq=fecharArq(arq);
if(erro==false){
	arq=abrirArq("dicas.fc" , "a");
	fseek(arq,0,SEEK_END);
	fprintf(arq,"%s\n", dica);
	arq=fecharArq(arq);	
  }
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
