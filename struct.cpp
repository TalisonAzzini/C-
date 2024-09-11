#include <iostream>
#include <string>
#include <limits>

struct Filme {
	int id;
	std:: string nome;
	int duracao;
	std:: string categoria;
};

struct Serie {
	int id;
	std:: string nome;
	int qntEpisodios;
	std:: string categoria;
};

struct Streaming {
	Filme filmes[3];
	Serie series[3];
};

void registrarFilme(Streaming streaming, int x) {
	printf("\n----- REGISTRO DE FILME -----\n");
	Filme filme1;
	filme1.id = x+1;
	
	printf("Nome: ");
	std:: getline(std::cin, filme1.nome);
	
	printf("Duracao: ");
	scanf("%i", filme1.duracao);
	
	printf("Categoria: ");
	std:: cin>>filme1.categoria;
	
	streaming.filmes[x] = filme1;
	printf("Registro efetuado!\n\n");
}

void registrarSerie(Streaming streaming, int x) {
	printf("\n----- REGISTRO DE SERIE -----\n");
	Serie serie1;
	serie1.id = x+1;
	
	printf("Nome: ");
	std:: getline(std::cin, serie1.nome);
	
	printf("Quantidade de episodios: ");
	scanf("%i", serie1.qntEpisodios);
	
	printf("Categoria: ");
	std:: cin>>serie1.categoria;
	
	streaming.series[x] = serie1;
	printf("Registro efetuado!\n\n");
}

int main() {
	int op=0,f=0,s=0;
	Streaming TesteFlix;
	printf("Bem vindo!\n");
	
	do {
		
		printf("----- MENU -----\n1 - Registrar filme\n2 - Registrar serie\n0 - Sair\nOpcao: ");
		scanf("%i", &op);
		std:: cin.ignore(std:: numeric_limits <std::streamsize> ::max(), '\n');
		
		switch(op) {
			case 1:
				if(f==3) {
					printf("Quantidade maxima de filmes ja registrada.\n\n");
				}
				else {
					
					registrarFilme(TesteFlix, f);
					f+=1;
				}
				break;
				
			case 2:
				if(s==3) {
					printf("Quantidade maxima de series ja registrada.\n\n");
				}
				else {
					registrarSerie(TesteFlix, s);
					s+=1;
				}
				break;
				
			default:
				printf("Opcao invalida!\n\n");
				break;
		}
			
	} while(op!=0);
	
}
