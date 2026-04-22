#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Máximo de itens possíveis na struct mochila
#define MAX_ITENS 10

typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

typedef struct {
    Item dados[MAX_ITENS];
    int quantidade;
} mochila;


//Funções do código
void limparBufferEntrada();
void inserirItem(mochila *lista, Item novo);
void removerItem(mochila *lista, Item novo);
void listarItens(mochila *lista);

//Função principal
int main() {
    mochila minhaMochila;       //Nomeação da struct mochila
    minhaMochila.quantidade=0;  //Inicialização do contador com 0 itens
    Item itens;                 //Nomeação da struct Item
    int opcao;                  //Variável de controle do menu principal

    //Loop do menu principal
    do{
        printf("==================================\n");
        printf("    MOCHILA DE SOBREVIVÊNCIA\n");
        printf("==================================\n");
        printf("Itens da mochila: %d/10\n\n", minhaMochila.quantidade); //Mostra ao usuário a quantidade de itens dentro da mochila

        printf("1. Adicionar Item (Loot)\n");
        printf("2. Remover Item\n");
        printf("3. Listar Itens na Mochila\n");
        printf("0. Sair\n");
        printf("----------------------------------\n");
        printf("Escolha uma opção: ");
        if (scanf("%d", &opcao) != 1){
            limparBufferEntrada();
            printf("Opção inválida!\n");
            opcao = -1;
            continue;
        }
        limparBufferEntrada();

        switch (opcao) {
        case 1:
            inserirItem(&minhaMochila, itens);
            break;
        
        case 2:
            removerItem(&minhaMochila, itens);
            break;
        
        case 3:
            listarItens(&minhaMochila);
            break;
        
        case 0:
            printf("Saindo...");
            break;
        
        default:
            break;
        }
    } while (opcao != 0);
    return 0;
}


//-----------------------------------------------------
//              IMPLEMENTAÇÃO DE FUNÇÕES
//-----------------------------------------------------

//Função para limpar espaços "\n" deixado pelo scanf
void limparBufferEntrada(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

//FUNÇÃO PARA INSERIR ITENS NA MOCHILA
void inserirItem(mochila *lista, Item novo){
    //Verificação se a lista está cheia
    if (lista->quantidade == MAX_ITENS){
        printf("\nMochila cheia! Não é possível adicionar novo item.\n");
        printf("Pressione 'ENTER' para continuar...\n");
        getchar();
        return;
    }

    //Caso não esteja cheia solicita os dados do item ao usuário
    printf("\n--- ADICIONAR NOVO ITEM ---\n\n");
    printf("Nome do item: ");
    fgets(novo.nome, sizeof(novo.nome), stdin);    
    novo.nome[strcspn(novo.nome, "\n")] = '\0';

    printf("Tipo do item (arma, municao, cura, etc.): ");
    fgets(novo.tipo, sizeof(novo.tipo), stdin);
    novo.tipo[strcspn(novo.tipo, "\n")] = '\0';

    printf("Quantidade: ");
    while (scanf("%d", &novo.quantidade) != 1 || novo.quantidade <= 0){
        limparBufferEntrada();
        printf("Entrada inválida. Digite um número inteiro válido: ");
    }
    limparBufferEntrada();

    //Faz a cópia dos dados informados para a struct mochila
    lista->dados[lista->quantidade] = novo;
    lista->quantidade++; // Incrementa o contador da struct mochila

    printf("\nItem '%s' adicionado com sucesso!\n\n", novo.nome);

    listarItens(lista); //Lista os itens da struct mochila
}

//FUNÇÃO PARA REMOVER ITENS DA MOCHILA
void removerItem(mochila *lista, Item novo){
    //Verifica se a lista está vazia
    if(lista->quantidade == 0){
        printf("\nA mochila está vazia! Pressione 'ENTER' para voltar ao menu principal...\n");
        getchar();
        return;
    }

    //Caso não esteja solicita ao usuário o nome do item a ser removido
    printf("\n--- REMOVER ITEM ---\n\n");
    printf("Digite o nome do item a ser removido: ");
    fgets(novo.nome, sizeof(novo.nome), stdin);
    novo.nome[strcspn(novo.nome, "\n")] = '\0';

    //Percorre a lista para encontrar o item
    int i, pos = -1;
    for (i=0; i < lista->quantidade; i++){
        if (strcmp(lista->dados[i].nome, novo.nome) == 0){
            pos = i;
            break;
        }
    }

    //Retorna mensagem de erro se não encontrar o item
    if (pos == -1){
        printf("Erro! Item '%s' não encontrado na mochila. Pressione 'ENTER' para retornar ao menu principal...\n", novo.nome);
        getchar();
        return;
    }

    //Atualiza a posição dos itens caso seja removido
    for (i=pos; i < lista->quantidade -1; i++){
        lista->dados[i] = lista->dados[i+1];
    }

    lista->quantidade--; //Atualiza o contador da struct mochila

    printf("\nItem '%s' removido com sucesso! Pressione 'ENTER' para voltar ao menu principal...\n", novo.nome);
    getchar();
}

//FUNÇÃO PARA MOSTRAR OS ITENS CONTIDOS DENTRO DA MOCHILA
void listarItens(mochila *lista){
    //Verifica se a lista está vazia
    if(lista->quantidade == 0){
        printf("\nA mochila está vazia! Pressione 'ENTER' para voltar ao menu principal...\n");
        getchar();
        return;
    }


    printf("\n--- ITENS NA MOCHILA (%d/10) ---\n", lista->quantidade);
    printf("----------------------------------------------------------\n");
    printf(" %-25s | %-15s | %s \n", "NOME", "TIPO", "QUANTIDADE");
    printf("----------------------------------------------------------\n");
    //Percorre todos os itens da struct mochila e mostra os dados
    for (int i=0; i < lista->quantidade; i++){
        printf(" %-25s | %-15s | %d \n", lista->dados[i].nome, lista->dados[i].tipo, lista->dados[i].quantidade);
    }
    printf("----------------------------------------------------------\n\n");

    printf("Pressione 'ENTER' para continuar...\n");
    getchar();
}
