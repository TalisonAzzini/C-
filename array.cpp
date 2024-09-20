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
