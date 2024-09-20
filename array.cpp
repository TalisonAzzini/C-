#include <iostream>
#include <String>

int main() {
	int matricula[3];
	std:: string cpf[3];
	float media[3];
	
	for (int i=0; i<3; i++) {
		printf("----- REGISTRO -----\n");
		
		printf("Matricula do aluno %i: ", i+1);
		scanf("%i", &matricula[i]);
		
		printf("CPF do aluno %i: ", i+1);
		std:: cin>>cpf[i];
		
		printf("Media do aluno %i: ", i+1);
		scanf("%f", &media[i]);
		printf("\n");
	}
	
	for (int i=0; i<3; i++) {
		printf("----- ALUNO %i -----\n", i+1);
		printf("Matricula: %i\n", matricula[i]);
		std:: cout<<"CPF: "<<cpf[i]<<std:: endl;
		printf("Media: %f\n\n", media[i]);
	}
	
}

#include <stdio.h>
#include <stdlib.h>

typedef struct vendedor {
	char nome[30];
	char matricula[15];
	float venda[3];
} Vendedor;

void limpa_linha() {
	scanf("%*[^\n]");
	scanf("%*c");
}
/*---------------------------------------*/

void registrar() {
	FILE *arq;
	Vendedor vendedor;
	int i, n_reg;
	
	printf("\nQuantidade de vendedores a incluir: ");
	scanf("%d", &n_reg);
	limpa_linha();
	
	arq = fopen("arquivo.bin", "a+b");
	if(arq==NULL) {
		perror("Erro");
		exit(1);
	}
	
	for(i=0; i<n_reg; i++) {
		printf("Digite o nome do vendedor: ");
		scanf("%[^\n]", vendedor.nome);
		limpa_linha();
		
		printf("Digite a matricula: ");
		scanf("%[^\n]", vendedor.matricula);
		limpa_linha();
		
		for(int j=0; j<3; j++) {
			printf("Digite a venda numero %i: ", j+1);
			scanf("%f", &vendedor.venda[j]);
		}
		
		fwrite(&vendedor, sizeof(Vendedor), 1, arq);
	}
	fclose(arq);
}

void ler_registros() {
	FILE *arq;
	Vendedor vendedor;
	
	arq = fopen("arquivo.bin", "rb");
	
	if(arq==NULL) {
		printf("Erro ao abrir o arquivo.\n");
		exit(1);
	}
	
	printf("===== PESSOAS CADASTRADAS =====");
	fread(&vendedor, sizeof(Vendedor), 1, arq);
	
	do {
		printf("\nNome: %s\nMatricula: %s\nPrimeira venda: %i\nSegunda venda: %i\nTerceira venda: %i\n",
		vendedor.nome, vendedor.matricula, &vendedor.venda[0], &vendedor.venda[1], &vendedor.venda[2]);
		fread(&vendedor, sizeof(Vendedor), 1, arq);
	} while(!feof(arq));
	fclose(arq);
}
/*---------------------------------------*/

int main() {
	char opcao;
	
	do {
		registrar();
		
		ler_registros();
		
		printf("\nDeseja continuar?");
		scanf("%c", &opcao);
		limpa_linha();
	} while(opcao=='s');
	return 0;
}
