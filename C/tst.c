#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define MAX 30
#define EML 3

struct String {
    char arr[MAX];
};

struct LinkedListNode {
    struct String e;
    struct LinkedListNode *next;
};

struct LinkedList {
    struct LinkedListNode arr;
};

void tst1();
void tst2();
void listaItensLista(struct LinkedListNode n1);

int leQtd();
void limpaBuffer();

int main() {

    //    printf("\n\nTeste 1...\n");
    //    tst1();

    printf("\n\nTeste 2...\n");
    tst2();

    return 0;
}

void tst1() {

    // Declaração
    struct LinkedListNode *arr;
    // Iterator
    struct LinkedListNode *it;
    int i = 0;

    int qtd = leQtd();
    if (!qtd) {
        return;
    }

    // Alocação
    arr = (struct LinkedListNode*) malloc(qtd * sizeof (struct LinkedListNode));
    if (!arr) {
        printf("Falha ao alocar memoria!\n");
        exit(-1);
        return;
    }
    putchar('\n');

    // Leitura
    it = arr;
    for (i = 0; i < qtd; i++) {
        printf("Elm: %2d\n", i + 1);
        limpaBuffer();
        gets(&it->e.arr[0]);
        putchar('\n');
        it++;
    }
    putchar('\n');

    // Impressão
    it = arr;
    for (i = 0; i < qtd; i++) {
        printf("Eml %2d: %s\n", i + 1, it->e.arr);
        it++;
    }

    printf("Fim.");
    free(arr);
    exit(0);

}

void tst2() {

    // Declaração
    struct LinkedListNode initialNode;

    struct LinkedListNode *it;
    int i = 0;

    // Alocação
    arr = (struct LinkedListNode*) malloc(sizeof (struct LinkedListNode));
    if (!arr) {
        printf("Falha ao alocar memoria!\n");
        exit(-1);
        return;
    }
    putchar('\n');

    // Salva o endereço do nó inicial
    it = &initialNode;

    // Leitura
    char tec = -1;

    // 
    // continuar a pt daqui
    printf("Elm: %2d\n", i + 1);
    limpaBuffer();
    gets(it->e.arr[0]);
    // continuar a pt daqui
    // 
    printf("Elm: %2d\n", i + 1);



    for (i = 0; i < qtd; i++) {
        printf("Elm: %2d\n", i + 1);
        limpaBuffer();
        gets(&it->e.arr[0]);
        putchar('\n');
        it++;
    }
    putchar('\n');

    // Impressão
    it = arr;
    listaItensLista(*it);

    printf("Fim.");
    free(arr);
    exit(0);

}

void listaItensLista(struct LinkedListNode n1) {
    struct LinkedListNode *p = &n1;
    int i = 1;
    // Impressão
    while (p) {
        printf("Eml %2d: %s\n", i + 1, p->e.arr);
        p = n1.next;
        i++;
    }
}

int leQtd() {
    int qtd = 0;
    // Leitura
    printf("Diga quantos quer alocar: ");
    limpaBuffer();
    scanf("%d", &qtd);

    // Validação
    if (!qtd) {
        printf("\nValor invalido! Flw.\n");
        exit(-1);
        return 0;
    }
    return qtd;
}

void limpaBuffer() {
    fflush(stdin);
}

void tstStr() {
    char str[] = "batata";

    char *p = &str[0];
    do {
        printf("%c", *p);
    } while (*(p++));
}

void tstMaloc() {
    printf("testando malloc...");
    int i = 0;
    while (malloc(250000) != NULL) {
        i++;
    }
    printf("Num: %d", i);
}