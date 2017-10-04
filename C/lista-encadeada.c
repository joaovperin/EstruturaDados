#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

#define MAX 30
#define EML 3

struct String {
    char arr[MAX];
};

struct LinkedListNode {
    int e;
    struct LinkedListNode *next;
};

struct LinkedList {
    struct LinkedListNode head;
};

void tst1();
void tst2();
void listaItensLista(struct LinkedListNode n1);

int leQtd();
void limpaBuffer();

int main() {

    printf("\n\nTeste 1...\n");
    tst1();

    return 0;
}

void tst1() {

    // Declaração do nodo inicial
    struct LinkedListNode *head;

    struct LinkedListNode *it;
    int n = 0;

    head = (struct LinkedListNode *) malloc(sizeof (struct LinkedListNode));

    it = head;
    it -> e = 0;
    it -> next = NULL;

    printf("Digite um numero: ");
    scanf("%d", &n);
    limpaBuffer();
    it -> e = n;
    it -> next = NULL;

    char ch = 'N';
    do {
        printf("\nQuer ler mais um? Y/N: ");
        ch = getch();
        limpaBuffer();
        putchar('\n');

        if ((ch != 'N' && ch != 'n')) {
            it -> next = (struct LinkedListNode *) malloc(sizeof (struct LinkedListNode));
            it = it -> next;
            printf("Digite um numero: ");
            scanf("%d", &n);
            limpaBuffer();

            it -> e = n;
            it -> next = NULL;
        }

    } while (ch != 'N' && ch != 'n');

    printf("\n\nTodos os valores:\n");

    it = head;
    while (it != NULL) {
        printf("Valor: %d\n", it -> e);
        it = it -> next;
    }

    printf("end");
    return;


    //    free(arr);
    //    exit(0);

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