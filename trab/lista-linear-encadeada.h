#ifndef LISTA_LINEAR_ENCADEADA
#define LISTA_LINEAR_ENCADEADA

#define PROD_DESC_LEN 30

/**
 * Estrutura de produtos
 */
struct Produto {
    int codigo;
    char *descricao;
};
typedef struct Produto Produto;

/**
 * Estrutura de um nodo da lista
 */
struct LinkedListNode {
    Produto e;
    struct LinkedListNode *next;
};
typedef struct LinkedListNode LinkedListNode;

// Funções de manipulação da lista
LinkedListNode* ls_create();
LinkedListNode* ls_preppend(LinkedListNode *p, Produto prod);
LinkedListNode* ls_append(LinkedListNode *p, Produto prod);
LinkedListNode* ls_remove(LinkedListNode *head, int cod);
LinkedListNode* ls_readKey(LinkedListNode *p, int cod);

// Funções de manipulação da lista
void ls_printAll(LinkedListNode *p);
void ls_close(LinkedListNode *head);
int ls_isEmpty(LinkedListNode *head);

// Funções auxiliares de elementos da lista
Produto criaProduto(int cod, char valor[]);
void printaProduto(Produto e);

// Funções auxiliares do programa
LinkedListNode* createNewListWithValues();
void limpaBuffer();

#endif