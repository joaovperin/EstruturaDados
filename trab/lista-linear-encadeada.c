#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

// Declaração das estruturas e prototipação dos métodos
#include "lista-linear-encadeada.h"
#define DEBUG 1

/**
 * 1) Criar uma estrutura com no mínimo dois membros, um valor inteiro e um vetor de caracteres. Por exemplo:
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
 * 2) Implementar as seguintes funções:
 *
 * a) Criar uma lista;                                        = ls_create();
 * b) Inserir um nodo no início da lista;                     = ls_preppend();
 * c) Inserir um nodo no final da lista;                      = ls_append();
 * d) Remover um nodo da lista;                               = ls_remove();
 * e) Buscar um nodo na lista a partir da matrícula do aluno; = ls_readKey();
 * f) Imprimir a lista;                                       = ls_printAll();
 * g) Limpar a lista;                                         = ls_close();
 * h) Verificar se a lista está vazia.                        = ls_isEmpty();
 *
 * 3) Implementar uma função que insira os nodos de modo ordenado (crescente), considerando a matrícula;
 *
 * 4) Implementar uma função que insira os nodos de modo ordenado (decrescente), considerando a matrícula ;
 *
 */
int main() {
    // Declaração do nodo inicial
    LinkedListNode *head;
    // Inicializa o nodo inicial
    head = ls_create();
    // Lista a lista
    putchar('\n');
    ls_printAll(head);
    // Remove o elemento de código 3 e lista novamente
    //ls_remove(head, 2);
    //putchar('\n');
    //ls_printAll(head);

    printf("\nend");
    return 0;
}

/**
 * Cria uma lista
 */
LinkedListNode* ls_create() {
    if (DEBUG == 1) {
        return createNewListWithValues();
    }
    return NULL;
}

/**
 * Adiciona um elemento no final de uma lista
 */
LinkedListNode* ls_append(LinkedListNode *p, Produto prod) {
    // Se for uma lista vazia, adiciona no final
    if (p == NULL) {
        return ls_preppend(p, prod);
    }
    // Itera lista até encontrar o fim
    LinkedListNode* it = p;
    while (it -> next != NULL) {
        it = it -> next;
    }
    // Cria elemento
    it -> next = (struct LinkedListNode *) malloc(sizeof (struct LinkedListNode));
    it -> next -> e = prod;
    it -> next -> next = NULL;
    return p;
}

/**
 * Adiciona um elemento no início de uma lista
 */
LinkedListNode* ls_preppend(LinkedListNode *p, Produto prod) {
    LinkedListNode* node = (struct LinkedListNode *) malloc(sizeof (struct LinkedListNode));
    node -> e = prod;
    node -> next = p;
    return node;
}

/**
 * Lê e retorna um elemento da lista pela chave
 */
LinkedListNode* ls_readKey(LinkedListNode *p, int cod) {
    LinkedListNode *i = p;
    while (i -> next != NULL) {
        if (i -> e.codigo == cod) return i;
        i = i -> next;
    }
    return NULL;
}

/**
 * Remove um elemento da lista
 */
LinkedListNode* ls_remove(LinkedListNode *head, int cod) {
    LinkedListNode *a = NULL;
    LinkedListNode *p = head;
    while (p != NULL && p->e.codigo != cod) {
        a = p;
        p = p->next;
    }
    if (a == NULL) head = p->next;
    else a->next = p->next;
    free(p);
    return head;
}

/**
 * Printa todos os elementos de uma lista
 */
void ls_printAll(LinkedListNode *p) {
    // Declara um iterador apontando pro início da lista
    LinkedListNode *it = p;
    // Printa os cabeçalhos
    printf("\nDados: ");
    printf("\n|-Cod--|-Descricao----------------------|");
    // Percorre a lista printando
    while (it != NULL) {
        putchar('\n');
        printaProduto(it -> e);
        it = it -> next;
    }
    putchar('\n');
}

/**
 * Fecha (apaga) uma lista
 */
void ls_close(LinkedListNode *head) {
    LinkedListNode *i = head;
    while (i != NULL) {
        LinkedListNode *tmp = i->next;
        free(tmp);
        i = tmp;
    }
}

/**
 * Retorna verdadeiro se uma lista está vazia
 */
int ls_isEmpty(LinkedListNode *head) {
    LinkedListNode *i = head;
    while (i->next != NULL) {
        if (i) return 0;
        i = i -> next;
    }
    return 1;
}

/**
 * Printa um produto
 */
void printaProduto(Produto e) {
    printf("| %5d| %30s |", e.codigo, e.descricao);
}

/**
 * Cria e retorna um novo produto
 */
Produto criaProduto(int cod, char valor[]) {
    Produto prr;
    prr.codigo = cod;
    prr.descricao = (char*) malloc(PROD_DESC_LEN * sizeof (char));
    //    prr.descricao = (char*) malloc(strlen(valor) * sizeof (char));
    strcpy(prr.descricao, valor);
    return prr;
}

/**
 * Cria uma nova lista com valores já inicializados
 */
LinkedListNode* createNewListWithValues() {
    LinkedListNode* head = NULL;
    head = ls_append(head, criaProduto(1, "FAR. AMIZADE A71"));
    head = ls_append(head, criaProduto(3225, "RLC 250 GR EMBALAGENS"));
    head = ls_append(head, criaProduto(3908, "BERCO COQUETEL INTEGRAL LIGHT"));
    head = ls_append(head, criaProduto(4047, "COQUETEL INTEGRAL LIGHT 250 G"));
    head = ls_append(head, criaProduto(4730, "PPLC- PASTEIS CALABRESA 280 GR"));
    head = ls_append(head, criaProduto(10010, "ERVA MATE TRADICIONAL 1KG"));
    head = ls_append(head, criaProduto(10120, "LASANHA 1000G"));
    head = ls_append(head, criaProduto(10150, "ERVA MATE CITRICOS 500G"));
    head = ls_append(head, criaProduto(10160, "TERERE 500G"));
    head = ls_append(head, criaProduto(10170, "DANONE BAND C/6UN"));
    head = ls_append(head, criaProduto(10180, "MASSA INDUSTRIAL"));
    head = ls_append(head, criaProduto(10185, "MASSA PARA PASTEL ROLO 500G"));
    head = ls_append(head, criaProduto(10190, "MASSA PASTEL DISCO ESP.400G"));
    head = ls_append(head, criaProduto(10191, "MASSA P/ PASTEL DL RECORD"));
    head = ls_append(head, criaProduto(10020, "ERVA MATE TRADICIONAL 500G"));
    head = ls_append(head, criaProduto(10030, "MASSA ESPAGUETE ESPINAFRE 500G"));
    head = ls_append(head, criaProduto(10060, "PASTEL DE FORNO MEDIO 300G."));
    head = ls_append(head, criaProduto(10070, "FRESA TOPO RET 2C MD K40 TINAL"));
    head = ls_append(head, criaProduto(10080, "MASSA FOLHADA ROLO 300G"));
    head = ls_append(head, criaProduto(10090, "LASANHA (300G)"));
    head = ls_append(head, criaProduto(10100, "IOGURTE 100G FRD C/10"));
    return head;
}

/**
 * Limpa o buffer do teclado
 */
void limpaBuffer() {
    fflush(stdin);
}