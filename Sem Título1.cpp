#include <stdio.h> //biblioteca de comunicação de usuario
#include <stdlib.h> //biblioteca de alocação de espaço em memoria
#include <locale.h> //biblioteca de alocação de texto por regiao
#include <string.h> //biblioteca responsavel pelas strings

int registro()
{
	setlocale(LC_ALL, "portuguese");
	
	char arquivo[40];
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	
	printf("digite seu cpf: ");
	scanf("%s" , cpf);
	printf("\n");
	
	strcpy(arquivo, cpf);
	
	FILE *file;
	
	file = fopen(arquivo, "w");
	fprintf(file,cpf);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("digite seu nome: ");
	scanf("%s",nome);
	printf("\n");
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("digite seu sobrenome: ");
	scanf("%s", sobrenome);
	printf("\n");
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("digite seu cargo: ");
	scanf("%s", cargo);
	printf("\n");
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
}
	
int consulta()
{
	setlocale(LC_ALL, "portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("digite seu cpf:");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL);
		{
			printf("nao foi encontrado\n");
		}
	
	while(fgets(conteudo, 200, file) != NULL);
	{
		printf("essas sao suas informações: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");

}

int deletar()
{
	char cpf[40];
	
	printf("digite seu cpf: ");
	scanf("%s", cpf);
	

	remove(cpf);

	FILE *file;
	file =fopen(cpf, "r");
	
	
	if(file == NULL)
	{
		printf("\n\nesse usuario nao existe, ou ja foi deletado\n");
		system("pause");
		
	}
}



int main()
{
	int opcao = 0; //definindo as variaveis
	int repete = 1;

	// Corrigindo o loop for
	for (repete = 1; repete == 1; ) { 
		
		system("cls"); // Limpando a tela
		
    	setlocale(LC_ALL, "portuguese"); // definindo a linguagem
    	
    	printf("+++ CARTORIO DA EBAC +++\n\n\n");
    	printf("escolha a opção desejada\n\n\n");
    	printf("\t1 - registrar nomes\n");
		printf("\t2 - consultar nomes \n");
		printf("\t3 - deletar nomes \n\n\n\n\n"); // fim do menu
		printf("opção:");
		
		scanf("%d", &opcao); // guardando a escolha do usuario
		
		system("cls");
		
		switch(opcao)
		{
			case 1:
			registro();
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("essa opção não está disponivel\n");
			system("pause");
			break;
				
		}
		
    }

}

