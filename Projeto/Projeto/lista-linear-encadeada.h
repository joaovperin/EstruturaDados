/**
 * 1) Criar uma estrutura com no m�nimo dois membros, um valor inteiro e um vetor de caracteres. Por exemplo:
 *
 * struct cliente {
 *  int mat;
 *  char nome[40];
 * };
 *
 * struct elemento {
 *  struct cliente cli;
 *  struct elemento *prox;
 * }
 *
 * 2) Implementar as seguintes fun��es:
 *
 * a) Criar uma lista;                                        = ls_create();
 * b) Inserir um nodo no in�cio da lista;                     = ls_preppend();
 * c) Inserir um nodo no final da lista;                      = ls_append();
 * d) Remover um nodo da lista;                               = ls_remove();
 * e) Buscar um nodo na lista a partir da matr�cula do aluno; = ls_readKey();
 * f) Imprimir a lista;                                       = ls_printAll();
 * g) Limpar a lista;                                         = ls_close();
 * h) Verificar se a lista est� vazia.                        = ls_isEmpty();
 *
 * 3) Implementar uma fun��o que insira os nodos de modo ordenado (crescente), considerando a matr�cula;
 *
 * 4) Implementar uma fun��o que insira os nodos de modo ordenado (decrescente), considerando a matr�cula ;
 *
 */
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

LinkedListNode* ls_insertAsc(LinkedListNode *p, Produto prod);
LinkedListNode* ls_insertDesc(LinkedListNode *p, Produto prod);

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