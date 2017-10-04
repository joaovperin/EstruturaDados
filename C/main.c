#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void exe1();
void exe2();
void exe3();
void exe4();
void exe5();

void limpaBuffer();

void tstStr() {
    char str[] = "batata";

    char *p = &str[0];
    do {
        printf("%c", *p);
    } while (*(p++));
}

void tstMaloc() {
    printf("testando malloc...");
    int i=0;
    while (malloc(250000) != NULL) {
        i++;
    }
    printf("Num: %d", i);
}

int main() {
    tstMaloc();

    return 0;

    printf("\n\nExercicio 1...\n");
    exe1();

    printf("\n\nExercicio 2...\n");
    exe2();

    printf("\n\nExercicio 3...\n");
    exe3();

    printf("\n\nExercicio 4...\n");
    exe4();

    printf("\n\nExercicio 5...\n");
    exe5();

    return 0;
}

void exe1() {
    int matriz[2][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10}
    };
    int i, j;
    int *p;
    for (j = 0; j < 2; j++)
        for (i = 0; i < 2; i++)
            printf("%d\t", matriz[j][i]);
    printf("\n\n");
    p = &matriz[1][2];
    i = 0;
    while (i < 3) {
        printf("%d\t", *p);
        p++;
        i++;
    }
    printf("\n\n");
    p = &matriz[0][0];
    i = 0;
    while (i < 10) {
        printf("%d\t", *(p + i));
        i = i + 2;
    }
    printf("\n\n");
}

void exe2() {
    char placar[30] = "Internacional 0 x 1 Grêmio";
    char *p;
    int i;

    printf("%u %u\n", placar, &placar[0]);

    for (i = 0; placar[i] != '\0'; i++)
        printf("%c", placar[i]);
    printf("\n");

    for (p = placar; *p != '\0'; p++)
        printf("%c", *p);
    printf("\n");
    for (p = placar; *p != 'e'; p++)
        printf("%u\n", p);
    printf("\n");
}

void somaprod(int a, int b, int *p, int *q);

void exe3() {
    int s, p;
    somaprod(3, 5, &s, &p);
    printf("Soma = %d Produto = %d\n", s, p);
}
void zera(int *a, int *b);

void exe4() {
    int a = 10;
    int b = 20;
    printf("a: %d - b: %d\n\n", a, b);

    /* chamar a função nesse ponto */

    zera(&a, &b);
    printf("a: %d - b: %d", a, b);
}

struct TipoProduto {
    int codigo;
    char descricao[60];
};
void leitura(struct TipoProduto *p, int qtd);
void escrita(struct TipoProduto *p, int qtd);

void exe5() {
    int qtd = 3;
    struct TipoProduto *p;
    struct TipoProduto vetor[3];
    p = vetor;
    leitura(p, qtd);
    escrita(p, qtd);
}

void somaprod(int a, int b, int *p, int *q) {
    *p = a + b;
    *q = a * b;
}

void zera(int *a, int *b) {
    *a = 0;
    *b = 0;
}

void leitura(struct TipoProduto *p, int qtd) {
    int i = 0;
    while (i++<qtd) {
        printf("\n%3d.Digite o codigo: ", i);
        limpaBuffer();
        scanf("%d", &p->codigo);
        printf("\n%3d.Digite a descricao: ", i);
        limpaBuffer();
        gets(&p->descricao[0]);
        p++;
    }
    printf("\n");
}

void escrita(struct TipoProduto *p, int qtd) {
    int i = 0;
    while (i++<qtd) {
        printf("\n%3d.Codigo: %d", i, p->codigo);
        printf("\n%3d.Descricao: %s", i, p->descricao);
        p++;
    }
    printf("\n");
}

void limpaBuffer() {
    fflush(stdin);
}