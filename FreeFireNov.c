#include <stdio.h>
#include <string.h>

#define MAX_ITENS 10
#define MAX_NOME 50
#define MAX_TIPO 30

// Struct que representa um item da mochila
typedef struct {
    char nome[MAX_NOME];
    char tipo[MAX_TIPO];
    int quantidade;
} Item;

// Vetor estático da mochila
Item mochila[MAX_ITENS];
int numItens = 0;

// Funções auxiliares
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

// Adicionar item
void adicionarItem() {
    if (numItens >= MAX_ITENS) {
        printf("A mochila está cheia! Remova um item para adicionar outro.\n");
        return;
    }

    Item novo;

    printf("Nome do item: ");
    limparBuffer();
    fgets(novo.nome, MAX_NOME, stdin);
    novo.nome[strcspn(novo.nome, "\n")] = '\0';

    printf("Tipo do item: ");
    fgets(novo.tipo, MAX_TIPO, stdin);
    novo.tipo[strcspn(novo.tipo, "\n")] = '\0';

    printf("Quantidade: ");
    scanf("%d", &novo.quantidade);

    mochila[numItens++] = novo;

    printf("\nItem adicionado com sucesso!\n");
}

// Remover item
void removerItem() {
    if (numItens == 0) {
        printf("A mochila está vazia. Nada para remover.\n");
        return;
    }

    char nomeBusca[MAX_NOME];
    printf("Digite o nome do item a remover: ");
    limparBuffer();
    fgets(nomeBusca, MAX_NOME, stdin);
    nomeBusca[strcspn(nomeBusca, "\n")] = '\0';

    int encontrado = -1;
    for (int i = 0; i < numItens; i++) {
        if (strcmp(mochila[i].nome, nomeBusca) == 0) {
            encontrado = i;
            break;
        }
    }

    if (encontrado == -1) {
        printf("Item não encontrado!\n");
        return;
    }

    // Remove deslocando os próximos para trás
    for (int i = encontrado; i < numItens - 1; i++) {
        mochila[i] = mochila[i + 1];
    }
    numItens--;

    printf("Item removido com sucesso!\n");
}

// Listar itens
void listarItens() {
    if (numItens == 0) {
        printf("A mochila está vazia.\n");
        return;
    }

    printf("\n===== ITENS NA MOCHILA =====\n");
    printf("%-20s  %-15s  %s\n", "Nome", "Tipo", "Quantidade");
    printf("-----------------------------------------------\n");

    for (int i = 0; i < numItens; i++) {
        printf("%-20s  %-15s  %d\n",
               mochila[i].nome,
               mochila[i].tipo,
               mochila[i].quantidade);
    }
    printf("-----------------------------------------------\n");
}

// Função principal com menu
int main() {
    int opcao;

    do {
        printf("\n===== MENU DA MOCHILA =====\n");
        printf("1 - Adicionar item\n");
        printf("2 - Remover item\n");
        printf("3 - Listar itens\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarItem();
                break;

            case 2:
                removerItem();
                break;

            case 3:
                listarItens();
                break;

            case 0:
                printf("Saindo do programa...\n");
                break;

            default:
                printf("Opção inválida! Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}
