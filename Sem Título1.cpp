#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// Constantes para tamanhos
#define TAM_CPF 12
#define TAM_NOME 40
#define TAM_CARGO 40
#define TAM_ARQUIVO 50
#define TAM_BUFFER 200

// Protótipos das funções
int validarCPF(const char *cpf);
void salvarNoArquivo(const char *arquivo, const char *dado);
int registro();
int consulta();
int deletar();
void limparBuffer();

// Função principal
int main() {
    int opcao = 0;
    
    while (true) {
        system("cls");
        setlocale(LC_ALL, "portuguese");
        
        printf("=== CARTÓRIO DA EBAC ===\n\n");
        printf("1 - Registrar novo usuário\n");
        printf("2 - Consultar usuário\n");
        printf("3 - Deletar usuário\n");
        printf("4 - Sair do sistema\n\n\n");
        printf("Escolha uma opção: ");
        
        scanf("%d", &opcao);
        limparBuffer();
        system("cls");
        
        switch(opcao) {
            case 1:
                registro();
                break;
            case 2:
                consulta();
                break;
            case 3:
                deletar();
                break;
            case 4:
                printf("Obrigado por usar o sistema. Até logo!\n");
                exit(0);
            default:
                printf("Opção inválida! Tente novamente.\n");
                system("pause");
        }
    }
    
    return 0;
}

// Função para validar CPF (Melhoria 1)
int validarCPF(const char *cpf) {
    if (strlen(cpf) != 11) {
        return 0;
    }
    for (int i = 0; i < 11; i++) {
        if (!isdigit(cpf[i])) {
            return 0;
        }
    }
    return 1;
}

// Função para salvar dados no arquivo (Melhoria 2)
void salvarNoArquivo(const char *arquivo, const char *dado) {
    FILE *file = fopen(arquivo, "a");
    if (file == NULL) {
        printf("Erro ao abrir arquivo!\n");
        exit(1);
    }
    fprintf(file, "%s,", dado);
    fclose(file);
}

// Função para limpar o buffer de entrada
void limparBuffer() {
    while (getchar() != '\n');
}

// Função de registro com opção para cadastrar outro usuário (Melhoria 4)
int registro() {
    setlocale(LC_ALL, "portuguese");
    char arquivo[TAM_ARQUIVO];
    char cpf[TAM_CPF];
    char nome[TAM_NOME];
    char sobrenome[TAM_NOME];
    char cargo[TAM_CARGO];
    char continuar;

    do {
        system("cls");
        
        // Validação do CPF
        do {
            printf("Digite o CPF (apenas números, 11 dígitos): ");
            scanf("%11s", cpf);
            limparBuffer();
            
            if (!validarCPF(cpf)) {
                printf("CPF inválido! Tente novamente.\n");
            }
        } while (!validarCPF(cpf));

        strcpy(arquivo, cpf);
        strcat(arquivo, ".txt");
        
        // Coleta dos dados
        printf("Digite o nome: ");
        scanf("%39s", nome);
        limparBuffer();
        
        printf("Digite o sobrenome: ");
        scanf("%39s", sobrenome);
        limparBuffer();
        
        printf("Digite o cargo: ");
        scanf("%39s", cargo);
        limparBuffer();
        
        // Salva no arquivo
        salvarNoArquivo(arquivo, cpf);
        salvarNoArquivo(arquivo, nome);
        salvarNoArquivo(arquivo, sobrenome);
        salvarNoArquivo(arquivo, cargo);
        
        printf("\nRegistro concluído com sucesso!\n");
        
        // Pergunta se deseja cadastrar outro usuário
        printf("\nDeseja cadastrar outro usuário? (S/N): ");
        scanf(" %c", &continuar);
        limparBuffer();
        
    } while (toupper(continuar) == 'S');

    return 0;
}

// Função de consulta
int consulta() {
    setlocale(LC_ALL, "portuguese");
    char cpf[TAM_CPF];
    char arquivo[TAM_ARQUIVO];
    char conteudo[TAM_BUFFER];
    
    printf("Digite o CPF para consulta: ");
    scanf("%11s", cpf);
    limparBuffer();
    
    strcpy(arquivo, cpf);
    strcat(arquivo, ".txt");
    
    FILE *file = fopen(arquivo, "r");
    if (file == NULL) {
        printf("Registro não encontrado!\n");
        system("pause");
        return 1;
    }
    
    printf("\n=== DADOS ENCONTRADOS ===\n\n");
    while (fgets(conteudo, TAM_BUFFER, file) != NULL) {
        printf("%s", conteudo);
    }
    printf("=========================\n");
    
    fclose(file);
    system("pause");
    return 0;
}

// Função deletar com confirmação (Melhoria 6)
int deletar() {
    char cpf[TAM_CPF];
    char arquivo[TAM_ARQUIVO];
    char confirmacao;
    
    printf("Digite o CPF para deletar: ");
    scanf("%11s", cpf);
    limparBuffer();
    
    strcpy(arquivo, cpf);
    strcat(arquivo, ".txt");
    
    // Verifica se o arquivo existe
    FILE *file = fopen(arquivo, "r");
    if (file == NULL) {
        printf("Registro não encontrado!\n");
        system("pause");
        return 1;
    }
    fclose(file);
    
    // Confirmação antes de deletar
    printf("\nTem certeza que deseja deletar o CPF %s? (S/N): ", cpf);
    scanf(" %c", &confirmacao);
    limparBuffer();
    
    if (toupper(confirmacao) == 'S') {
        if (remove(arquivo) == 0) {
            printf("Registro deletado com sucesso!\n");
        } else {
            printf("Erro ao deletar registro.\n");
        }
    } else {
        printf("Operação cancelada.\n");
    }
    
    system("pause");
    return 0;
}
