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

// Fun��es de manipula��o da lista
LinkedListNode* ls_create();
LinkedListNode* ls_preppend(LinkedListNode *p, Produto prod);
LinkedListNode* ls_append(LinkedListNode *p, Produto prod);
LinkedListNode* ls_remove(LinkedListNode *head, int cod);
LinkedListNode* ls_readKey(LinkedListNode *p, int cod);

// Fun��es de manipula��o da lista
void ls_printAll(LinkedListNode *p);
void ls_close(LinkedListNode *head);
int ls_isEmpty(LinkedListNode *head);

// Fun��es auxiliares de elementos da lista
Produto criaProduto(int cod, char valor[]);
void printaProduto(Produto e);

// Fun��es auxiliares do programa
LinkedListNode* createNewListWithValues();
void limpaBuffer();

#endif