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
	  printf("\n===== VENDEDOR %i =====\n", i+1);
		printf("Nome: ");
		scanf("%[^\n]", vendedor.nome);
		limpa_linha();
		
		printf("Matricula: ");
		scanf("%[^\n]", vendedor.matricula);
		limpa_linha();
		
		for(int j=0; j<3; j++) {
			printf("Venda nº%i: R$", j+1);
			scanf("%f", &vendedor.venda[j]);
		}
		limpa_linha();
		
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
	
	fread(&vendedor, sizeof(Vendedor), 1, arq);
	
	do {
	    printf("\n===== PESSOAS CADASTRADAS =====");
		printf("\nNome: %s\nMatricula: %s\nPrimeira venda: %f\nSegunda venda: %f\nTerceira venda: %f\n",
		vendedor.nome, vendedor.matricula, vendedor.venda[0], vendedor.venda[1], vendedor.venda[2]);
		fread(&vendedor, sizeof(Vendedor), 1, arq);
	} while(!feof(arq));
	fclose(arq);
}
/*---------------------------------------*/

int main() {
	char opcao;
	printf("===== BEM VINDO =====");
	
	do {
		registrar();
		ler_registros();
		
		printf("\nDeseja continuar(s/n)? ");
		scanf("%c", &opcao);
		limpa_linha();
	} while(opcao=='s' or opcao=='S');
	return 0;
}
