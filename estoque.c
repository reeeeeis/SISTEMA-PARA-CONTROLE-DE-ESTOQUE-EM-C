#include <stdio.h>
#include <string.h>

// Estrutura do produto
struct Produto {
    int id;
    char nome[50];
    int quantidade;
    float preco;
};

struct Produto estoque[100];
int total_produtos = 0;

// Função para exibir o cabeçalho com arte minimalista
void cabecalho_menu() {
    printf("========================================\n");
    printf("         CONTROLE DE ESTOQUE            \n");
    printf("========================================\n\n");
}

// Função para exibir o encerramento com arte minimalista
void encerrar_programa() {
    printf("\n========================================\n");
    printf("            FIM DO PROGRAMA            \n");
    printf("========================================\n\n");
}

// Função para adicionar produto
void adicionar_produto() {
    printf("Digite o nome do produto: ");
    scanf(" %[^\n]", estoque[total_produtos].nome);
    printf("Digite a quantidade: ");
    scanf("%d", &estoque[total_produtos].quantidade);
    printf("Digite o preco: ");
    scanf("%f", &estoque[total_produtos].preco);

    estoque[total_produtos].id = total_produtos + 1;
    total_produtos++;
    printf("Produto adicionado com sucesso!\n\n");
}

// Função para listar produtos
void listar_produtos() {
    if (total_produtos == 0) {
        printf("Estoque vazio.\n");
        return;
    }

    printf("\nLista de Produtos:\n");
    for (int i = 0; i < total_produtos; i++) {
        printf("ID: %d | Nome: %s | Quantidade: %d | Preço: %.2f\n",
               estoque[i].id, estoque[i].nome, estoque[i].quantidade, estoque[i].preco);
    }
    printf("\n");
}

// Função para atualizar a quantidade de um produto
void atualizar_quantidade() {
    int id, nova_quantidade;
    printf("Digite o ID do produto: ");
    scanf("%d", &id);

    if (id < 1 || id > total_produtos) {
        printf("Produto não encontrado.\n");
    } else {
        printf("Digite a nova quantidade para o produto %s: ", estoque[id - 1].nome);
        scanf("%d", &nova_quantidade);
        estoque[id - 1].quantidade = nova_quantidade;
        printf("Quantidade atualizada com sucesso!\n\n");
    }
}

// Função para buscar produto por nome
void buscar_produto() {
    char nome[50];
    printf("Digite o nome do produto: ");
    scanf(" %[^\n]", nome);

    int encontrado = 0;
    for (int i = 0; i < total_produtos; i++) {
        if (strstr(estoque[i].nome, nome) != NULL) {
            printf("ID: %d | Nome: %s | Quantidade: %d | Preço: %.2f\n",
                   estoque[i].id, estoque[i].nome, estoque[i].quantidade, estoque[i].preco);
            encontrado = 1;
        }
    }
    if (!encontrado) {
        printf("Produto não encontrado.\n");
    }
}

// Função para calcular o valor total do estoque
void valor_total_estoque() {
    float total = 0;
    for (int i = 0; i < total_produtos; i++) {
        total += estoque[i].quantidade * estoque[i].preco;
    }
    printf("Valor total do estoque: %.2f\n\n", total);
}

// Função para excluir um produto
void excluir_produto() {
    int repetir;
    do {
        if (total_produtos == 0) {
            printf("Estoque vazio.\n");
            return;
        }

        int id;
        printf("Digite o ID do produto que deseja excluir: ");
        scanf("%d", &id);

        if (id < 1 || id > total_produtos) {
            printf("ID invalido.\n");
        } else {
            for (int i = id - 1; i < total_produtos - 1; i++) {
                estoque[i] = estoque[i + 1];
                estoque[i].id = i + 1;
            }
            total_produtos--;

            // Estilo ALERTA
            printf("\nProduto removido com sucesso!\n");
            printf("  [X] ITEM EXCLUIDO DO ESTOQUE\n");
        }

        printf("\n1. Voltar ao menu | 2. Repetir operacao: ");
        scanf("%d", &repetir);
    } while (repetir == 2);
}

int main() {
    int opcao;

    do {
        cabecalho_menu();  // Exibe a arte minimalista antes do menu

        printf("1. Adicionar produto\n");
        printf("2. Listar produtos\n");
        printf("3. Atualizar quantidade\n");
        printf("4. Buscar produto\n");
        printf("5. Valor total do estoque\n");
        printf("6. Excluir produto\n");
        printf("7. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: adicionar_produto(); break;
            case 2: listar_produtos(); break;
            case 3: atualizar_quantidade(); break;
            case 4: buscar_produto(); break;
            case 5: valor_total_estoque(); break;
            case 6: excluir_produto(); break;
            case 7: 
                encerrar_programa(); // Exibe o encerramento antes de sair
                break;
            default: printf("Opcao invalida.\n");
        }

    } while (opcao != 7);

    return 0;
}

