#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

struct Produto {
    int codigo;
    char *descricao;
};
typedef struct Produto Produto;

struct LinkedListNode {
    Produto e;
    struct LinkedListNode *next;
};
typedef struct LinkedListNode LinkedListNode;

LinkedListNode* ls_create();
LinkedListNode* ls_add(LinkedListNode *p, Produto prod);
LinkedListNode* ls_readkey(LinkedListNode *p, int cod);
LinkedListNode* ls_remove(LinkedListNode *head, int cod);

void ls_close(LinkedListNode *head);
void ls_list(LinkedListNode *p);

Produto criaProduto(int cod, char valor[]);
void printaProduto(Produto e);
void limpaBuffer();

int main() {
    // Declaração do nodo inicial
    LinkedListNode *head;
    int idx;
    // Inicializa o nodo inicial e o índice
    head = ls_create();
    idx = 1;
    // Adiciona alguns valores
    head = ls_add(head, criaProduto(idx++, "tstdsadsa"));
    head = ls_add(head, criaProduto(idx++, "tstdsadsa"));
    head = ls_add(head, criaProduto(idx++, "tstdsadsa"));
    head = ls_add(head, criaProduto(idx++, "tstdsadsa"));
    head = ls_add(head, criaProduto(idx++, "tstdsadsa"));
    head = ls_add(head, criaProduto(idx++, "tstdsadsa"));
    head = ls_add(head, criaProduto(idx++, "tstdsadsa"));
    // Lista a lista
    putchar('\n');
    ls_list(head);
    // Remove o elemento de código 3
    ls_remove(head, 3);
    // Lista a lista
    putchar('\n');
    ls_list(head);
    //    printf("Digite um numero: ");
    //    scanf("%d", &n);
    //    limpaBuffer();
    //    it -> e = n;
    //    it -> next = NULL;
    //
    //    char ch = 'N';
    //    do {
    //        printf("\nQuer ler mais um? Y/N: ");
    //        ch = getch();
    //        limpaBuffer();
    //        putchar('\n');
    //
    //        if ((ch != 'N' && ch != 'n')) {
    //            it -> next = (struct LinkedListNode *) malloc(sizeof (struct LinkedListNode));
    //            it = it -> next;
    //            printf("Digite um numero: ");
    //            scanf("%d", &n);
    //            limpaBuffer();
    //
    //            it -> e = n;
    //            it -> next = NULL;
    //        }
    //
    //    } while (ch != 'N' && ch != 'n');
    //
    //    printf("\n\nTodos os valores:\n");
    //
    //    it = head;
    //    while (it != NULL) {
    //        printf("Valor: %d\n", it -> e);
    //        it = it -> next;
    //    }

    printf("\nend");

    return 0;
}

void limpaBuffer() {
    fflush(stdin);
}

//void ls_add2(LinkedListNode *p, Produto prod) {
//    LinkedListNode *itr = p;
//    while (itr -> next != NULL) itr = itr -> next;
//
//    itr = (struct LinkedListNode *) malloc(sizeof (struct LinkedListNode));
//    itr -> e = prod;
//    itr -> next = NULL;
//}

LinkedListNode* ls_create() {
    return NULL;
}

LinkedListNode* ls_add(LinkedListNode *p, Produto prod) {
    LinkedListNode* node = (struct LinkedListNode *) malloc(sizeof (struct LinkedListNode));
    node -> e = prod;
    node -> next = p;
    return node;
}

LinkedListNode* ls_readkey(LinkedListNode *p, int cod) {
    LinkedListNode *i = p;
    while (i -> next != NULL) {
        if (i -> e.codigo == cod) return i;
        i = i -> next;
    }
    return NULL;
}

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

void ls_close(LinkedListNode *head) {
    LinkedListNode *i = head;
    while (i != NULL) {
        LinkedListNode *tmp = i->next;
        free(tmp);
        i = tmp;
    }
}

void ls_list(LinkedListNode *p) {
    // Declara um iterador apontando pro início da lista
    LinkedListNode *it = p;
    // Printa os cabeçalhos
    printf("\nDados: ");
    printf("\n|Cod--|Desc----------------|");
    // Percorre a lista printando
    while (it -> next != NULL) {
        putchar('\n');
        printaProduto(it -> e);
        it = it -> next;
    }
    putchar('\n');
}

void printaProduto(Produto e) {
    printf("|%5d|%20s|", e.codigo, e.descricao);
}

Produto criaProduto(int cod, char valor[]) {
    Produto prr;
    prr.codigo = cod;
    prr.descricao = (char*) malloc(strlen(valor) * sizeof (char));
    strcpy(prr.descricao, valor);
    return prr;
}