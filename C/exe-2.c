#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define MAX 30

void exe1();
void exe2();
void exe3();
void exe3_1();

void limpaBuffer();

int main() {

    //    printf("\n\nExercicio 1...\n");
    //    exe1();

    //    printf("\n\nExercicio 2...\n");
    //    exe2();

    printf("\n\nExercicio 3...\n");
    exe3();
    putchar('\n');
    putchar('\n');
    printf("\n\nExercicio 3_1...\n");
    exe3_1();

    return 0;
}

void exe1() {
    // Declaração
    float *arr;
    // Iterator
    float *it;
    int qtd = 0;
    int i = 0;

    // Leitura
    printf("Diga quantos quer alocar: ");
    limpaBuffer();
    scanf("%d", &qtd);

    // Validação
    if (!qtd) {
        printf("\nValor invalido! Flw.\n");
        exit(-1);
        return;
    }

    // Alocação
    arr = malloc(qtd * sizeof (float));
    if (!arr) {
        printf("Falha ao alocar memoria!\n");
        exit(-1);
        return;
    }
    putchar('\n');

    // Leitura
    it = arr;
    for (i = 0; i < qtd; i++) {
        printf("Digite a pos %2d:", i + 1);
        scanf("%f", it);
        putchar('\n');
        it++;
    }
    putchar('\n');

    // Impressão
    it = arr;
    for (i = 0; i < qtd; i++) {
        printf("%d: %.2f\n", i + 1, *it);
        it++;
    }

    printf("oi");
    exit(0);

}

struct Aluno {
    int matricula;
    char nome[30];
    float media;
};

void exe2() {

    // Declaração
    struct Aluno *arr;
    // Iterator
    struct Aluno *it;
    int qtd = 0;
    int i = 0;

    // Leitura
    printf("Diga quantos quer alocar: ");
    limpaBuffer();
    scanf("%d", &qtd);

    // Validação
    if (!qtd) {
        printf("\nValor invalido! Flw.\n");
        exit(-1);
        return;
    }

    // Alocação
    arr = (struct Aluno*) malloc(qtd * sizeof (struct Aluno));
    if (!arr) {
        printf("Falha ao alocar memoria!\n");
        exit(-1);
        return;
    }
    putchar('\n');

    // Leitura
    it = arr;
    for (i = 0; i < qtd; i++) {
        printf("Aluno: %2d\n", i + 1);
        printf("Matricula:");
        limpaBuffer();
        scanf("%d", &it->matricula);
        printf("Nome:");
        limpaBuffer();
        gets(&it->nome[0]);
        printf("Media:");
        limpaBuffer();
        scanf("%f", &it->media);
        putchar('\n');
        it++;
    }
    putchar('\n');

    // Impressão
    it = arr;
    for (i = 0; i < qtd; i++) {
        printf("Matricula do aluno %2d: %d\tNome: %s\tMedia: %.2f\n", i + 1, it->matricula, &it->nome, it->media);
        it++;
    }

    printf("Fim.");
    free(arr);
    exit(0);

}

struct String {
    char arr[MAX];
};

void exe3() {

    // Declaração
    struct String *arr;
    // Iterator
    struct String *it;
    int qtd = 0;
    int i = 0;

    // Leitura
    printf("Diga quantos quer alocar: ");
    limpaBuffer();
    scanf("%d", &qtd);

    // Validação
    if (!qtd) {
        printf("\nValor invalido! Flw.\n");
        exit(-1);
        return;
    }

    // Alocação
    arr = (struct String*) malloc(qtd * sizeof (struct String));
    if (!arr) {
        printf("Falha ao alocar memoria!\n");
        exit(-1);
        return;
    }
    putchar('\n');

    // Leitura
    it = arr;
    for (i = 0; i < qtd; i++) {
        printf("String: %2d\n", i + 1);
        printf("String:");
        limpaBuffer();
        gets(it->arr);
        putchar('\n');
        it++;
    }
    putchar('\n');

    // Impressão
    it = arr;
    for (i = 0; i < qtd; i++) {
        printf("String %2d: %s\n", i + 1, it->arr);
        it++;
    }

    printf("Fim.");
    free(arr);
    exit(0);

}

void exe3_1() {

    // Declaração
    char **arr;
    // Iterator
    char **it;
    int qtd = 0;
    int i = 0;

    // Leitura
    printf("Diga quantos quer alocar: ");
    limpaBuffer();
    scanf("%d", &qtd);

    // Validação
    if (!qtd) {
        printf("\nValor invalido! Flw.\n");
        exit(-1);
        return;
    }

    // Alocação
    arr = (char **) malloc(qtd * sizeof (char[MAX]));
    if (!arr) {
        printf("Falha ao alocar memoria!\n");
        exit(-1);
        return;
    }
    putchar('\n');

    // Leitura
    it = arr;
    for (i = 0; i < qtd; i++) {
        printf("String: %2d\n", i + 1);
        printf("String:");
        limpaBuffer();
        gets(*it);
        putchar('\n');
        it++;
    }
    putchar('\n');

    // Impressão
    it = arr;
    for (i = 0; i < qtd; i++) {
        printf("String %2d: %s\n", i + 1, *it[0]);
        it++;
    }

    printf("Fim.");
    free(arr);
    exit(0);

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