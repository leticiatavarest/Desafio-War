#include <stdio.h>    // Para entrada e saída padrão
#include <string.h>   // Para manipulação de strings

typedef struct 
{
    char nome[30];
    char cor[10];
    int tropas;
} Territorio; 

int main() {
    // Essse vetor serve para armazenar 5 territórios
    Territorio territorios[5];

    // loop para entrada dos dados dos territórios 

    for (int i= 0; i < 5; i++) {
        printf("Cadastro do território %d\n", i +1);

        printf("Informe o nome do território: ");
        scanf("%s", territorios[i].nome);

        printf("Informe a cor do exécito: ");
        scanf("%s", territorios[i].cor);

        printf("Informe a quantidade de tropas: ");
        scanf("%d", &territorios[i].tropas);

        printf("\n"); 
    }

    // Exibindo os dados cadastrados
    printf("Dados dos territórios\n");
    for (int i=0; i < 5; i++) {
        printf("Território %d:\n", i + 1); 
        printf("Território %d:\n", i + 1);
        printf("Nome: %s\n", territorios[i].nome);
        printf("Cor do Exército: %s\n", territorios[i].cor);
        printf("Tropas: %d\n", territorios[i].tropas);
        printf("--------------------------\n");
    }

    return 0;
}