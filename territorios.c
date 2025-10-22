#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Definindo a estrutura do território
typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

// Função para criar o mapa (alocação dinâmica)
Territorio* criarMapa(int n) {
    Territorio* mapa = (Territorio*) calloc(n, sizeof(Territorio));
    return mapa;
}

// Função para cadastrar os territórios
void cadastrarTerritorios(Territorio* mapa, int n) {
    for (int i = 0; i < n; i++) {
        printf("\nCadastro do território %d:\n", i + 1);

        printf("Nome do território: ");
        scanf(" %[^\n]", mapa[i].nome); // Permite espaço no nome

        printf("Cor do exército: ");
        scanf(" %[^\n]", mapa[i].cor);

        printf("Quantidade de tropas: ");
        scanf("%d", &mapa[i].tropas);
    }
}

// Função para exibir os dados dos territórios
void exibirTerritorios(Territorio* mapa, int n) {
    printf("\n--- Dados dos Territórios ---\n");
    for (int i = 0; i < n; i++) {
        printf("Território %d:\n", i + 1);
        printf("Nome: %s\n", mapa[i].nome);
        printf("Cor do Exército: %s\n", mapa[i].cor);
        printf("Tropas: %d\n", mapa[i].tropas);
        printf("---------------------------\n");
    }
}

// Função que simula o ataque entre dois territórios
void atacar(Territorio* atacante, Territorio* defensor) {
    // Verifica se são cores diferentes
    if (strcmp(atacante->cor, defensor->cor) == 0) {
        printf("Erro: Você não pode atacar um território da mesma cor!\n");
        return;
    }

    // Verifica se o atacante tem tropas suficientes
    if (atacante->tropas < 2) {
        printf("Erro: O território atacante precisa ter pelo menos 2 tropas para atacar.\n");
        return;
    }

    // Sorteia os dados
    int dadoAtacante = rand() % 6 + 1;
    int dadoDefensor = rand() % 6 + 1;

    printf("\nDado do atacante: %d\n", dadoAtacante);
    printf("Dado do defensor: %d\n", dadoDefensor);

    if (dadoAtacante > dadoDefensor) {
        // Atacante venceu
        printf("Resultado: O atacante venceu a batalha!\n");

        // Transfere a cor e metade das tropas
        strcpy(defensor->cor, atacante->cor);
        defensor->tropas = atacante->tropas / 2;
        atacante->tropas = atacante->tropas / 2;

    } else {
        // Defensor venceu
        printf("Resultado: O defensor resistiu ao ataque.\n");
        atacante->tropas -= 1;
    }
}

// Função para liberar memória alocada
void liberarMemoria(Territorio* mapa) {
    free(mapa);
}

// Menu principal
void menu(Territorio* mapa, int n) {
    int opcao;
    do {
        printf("\n===== MENU =====\n");
        printf("1 - Exibir Territórios\n");
        printf("2 - Atacar Território\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            exibirTerritorios(mapa, n);
        } else if (opcao == 2) {
            int iAtacante, iDefensor;
            exibirTerritorios(mapa, n);

            printf("Digite o número do território ATACANTE: ");
            scanf("%d", &iAtacante);
            printf("Digite o número do território DEFENSOR: ");
            scanf("%d", &iDefensor);

            // Verifica se os índices são válidos
            if (iAtacante < 1 || iAtacante > n || iDefensor < 1 || iDefensor > n) {
                printf("Território inválido! Tente novamente.\n");
            } else {
                atacar(&mapa[iAtacante - 1], &mapa[iDefensor - 1]);
                exibirTerritorios(mapa, n); // Mostra atualização após o ataque
            }
        } else if (opcao == 0) {
            printf("Saindo do programa...\n");
        } else {
            printf("Opção inválida! Tente novamente.\n");
        }

    } while (opcao != 0);
}

// Função principal
int main() {
    srand(time(NULL)); // Garante aleatoriedade

    int numTerritorios;
    printf("Digite o número de territórios: ");
    scanf("%d", &numTerritorios);

    // Criação do mapa
    Territorio* mapa = criarMapa(numTerritorios);

    // Cadastro
    cadastrarTerritorios(mapa, numTerritorios);

    // Menu de opções
    menu(mapa, numTerritorios);

    // Liberação da memória
    liberarMemoria(mapa);

    return 0;
}
