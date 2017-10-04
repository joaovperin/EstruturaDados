#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

// Declara��o das estruturas e prototipa��o dos m�todos
#include "lista-linear-encadeada.h"
#define DEBUG 0

/**
 * M�todo auxiliar para testes
 */
LinkedListNode* ls_insert(LinkedListNode *p, Produto prod) {
    return ls_insertAsc(p, prod);
}

/**
 * Entry point principal
 * 
 * @return int
 */
int main() {

    // Declara��o e inicializa��o do nodo inicial
    LinkedListNode *head;
    head = ls_create();

    // Inser��o de alguns elementos
    head = ls_insert(head, criaProduto(1010, "perin 1010"));
    head = ls_insert(head, criaProduto(3050, "perin 3050"));
    head = ls_insert(head, criaProduto(2020, "perin 2020"));

    // Printa todos os elementos da lista
    ls_printAll(head);
    putchar('\n');

    printf("\nFim.");
    return 0;
}

/*
 * Insere um elemento em ordem crescente na lista
 */
LinkedListNode* ls_insertAsc(LinkedListNode *p, Produto prod) {
    // Se for uma lista vazia, adiciona no final
    if (p == NULL) {
        return ls_preppend(NULL, prod);
    }
    // Encontra a posi��o
    LinkedListNode* it = p;
    LinkedListNode* ant = it;
    while (it -> next != NULL) {
        ant = it;
        it = it -> next;
        if (it -> e.codigo >= prod.codigo) {
            break;
        }
    }
    // Cria novo elemento
    LinkedListNode* tmp = (struct LinkedListNode *) malloc(sizeof (struct LinkedListNode));
    tmp -> e = prod;
    ant -> next = tmp;
    ant -> next -> next = it;
    return p;
}

/*
 * Insere um elemento em ordem decrescente na lista
 */
LinkedListNode* ls_insertDesc(LinkedListNode *p, Produto prod) {
    // Se for uma lista vazia, adiciona no final
    if (p == NULL) {
        return ls_preppend(p, prod);
    }
    // Encontra a posi��o
    LinkedListNode* it = p;
    LinkedListNode* ant = it;
    while (it -> next != NULL) {
        ant = it;
        it = it -> next;
        if (it -> e.codigo <= prod.codigo) {
            break;
        }
    }
    // Cria um novo elemento e insere-o na lista
    LinkedListNode* newElm = (struct LinkedListNode *) malloc(sizeof (struct LinkedListNode));
    newElm -> e = prod;
    newElm -> next = ant -> next;
    ant -> next = newElm;
    return p;
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
    // Itera lista at� encontrar o fim
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
 * Adiciona um elemento no in�cio de uma lista
 */
LinkedListNode* ls_preppend(LinkedListNode *p, Produto prod) {
    LinkedListNode* node = (struct LinkedListNode *) malloc(sizeof (struct LinkedListNode));
    node -> e = prod;
    node -> next = p;
    return node;
}

/**
 * L� e retorna um elemento da lista pela chave
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
    // Declara um iterador apontando pro in�cio da lista
    LinkedListNode *it = p;
    // Printa os cabe�alhos
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
 * Retorna verdadeiro se uma lista est� vazia
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
    prr.descricao = (char*) malloc(PROD_DESC_LEN /*strlen(valor)*/ * sizeof (char));
    strcpy(prr.descricao, valor);
    return prr;
}

/**
 * Cria uma nova lista com valores j� inicializados
 */
LinkedListNode* createNewListWithValues() {
    LinkedListNode* head = NULL;
    head = ls_append(head, criaProduto(5000, "elm5000"));
    head = ls_append(head, criaProduto(4000, "elm3000"));
    head = ls_append(head, criaProduto(3000, "elm3000"));
    head = ls_append(head, criaProduto(2000, "elm2000"));
    head = ls_append(head, criaProduto(1000, "elm1000"));
    //    head = ls_append(head, criaProduto(1, "FAR. AMIZADE A71"));
    //    head = ls_append(head, criaProduto(3225, "RLC 250 GR EMBALAGENS"));
    //    head = ls_append(head, criaProduto(3908, "BERCO COQUETEL INTEGRAL LIGHT"));
    //    head = ls_append(head, criaProduto(4047, "COQUETEL INTEGRAL LIGHT 250 G"));
    //    head = ls_append(head, criaProduto(4730, "PPLC- PASTEIS CALABRESA 280 GR"));
    //    head = ls_append(head, criaProduto(10010, "ERVA MATE TRADICIONAL 1KG"));
    //    head = ls_append(head, criaProduto(10120, "LASANHA 1000G"));
    //    head = ls_append(head, criaProduto(10150, "ERVA MATE CITRICOS 500G"));
    //    head = ls_append(head, criaProduto(10160, "TERERE 500G"));
    //    head = ls_append(head, criaProduto(10170, "DANONE BAND C/6UN"));
    //    head = ls_append(head, criaProduto(10180, "MASSA INDUSTRIAL"));
    //    head = ls_append(head, criaProduto(10185, "MASSA PARA PASTEL ROLO 500G"));
    //    head = ls_append(head, criaProduto(10190, "MASSA PASTEL DISCO ESP.400G"));
    //    head = ls_append(head, criaProduto(10191, "MASSA P/ PASTEL DL RECORD"));
    //    head = ls_append(head, criaProduto(10020, "ERVA MATE TRADICIONAL 500G"));
    //    head = ls_append(head, criaProduto(10030, "MASSA ESPAGUETE ESPINAFRE 500G"));
    //    head = ls_append(head, criaProduto(10060, "PASTEL DE FORNO MEDIO 300G."));
    //    head = ls_append(head, criaProduto(10070, "FRESA TOPO RET 2C MD K40 TINAL"));
    //    head = ls_append(head, criaProduto(10080, "MASSA FOLHADA ROLO 300G"));
    //    head = ls_append(head, criaProduto(10090, "LASANHA (300G)"));
    //    head = ls_append(head, criaProduto(10100, "IOGURTE 100G FRD C/10"));
    return head;
}

/**
 * Limpa o buffer do teclado
 */
void limpaBuffer() {
    fflush(stdin);
}