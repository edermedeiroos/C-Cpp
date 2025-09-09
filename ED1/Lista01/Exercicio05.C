#include <stdio.h>

#define MAX 100
#define true 1
#define false 0
typedef int bool;

typedef struct {
    int itens[MAX];
    int topo;
} Pilha;

void inicializarPilha(Pilha* p) {
    p->topo = -1;
}

bool pilhaVazia(Pilha* p) {
    if (p->topo == -1) {
        return true;
    }
    return false;
}

void push(Pilha* p, int valor) {
    p->topo = p->topo + 1;
    p->itens[p->topo] = valor;
}

int pop(Pilha* p) {
    int valor = p->itens[p->topo];
    p->topo = p->topo - 1;
    return valor;
}

void converterDecimalParaBinario(int numero) {
    Pilha p;
    inicializarPilha(&p);
    int resto;

    printf("Convertendo o numero %d para binario...\n", numero);
    
    if (numero == 0) {
        push(&p, 0);
    }

    while (numero > 0) {
        resto = numero % 2;
        push(&p, resto);
        numero = numero / 2;

        printf("Resultado em binario: ");
        while (!pilhaVazia(&p)) {
            int digitoBinario = pop(&p);
            printf("%d", digitoBinario);
        }
    printf("\n");
    }
}

int main() {
    int numeroDecimal;

    printf("--- CONVERSOR DE DECIMAL PARA BINARIO ---\n");
    printf("Digite um numero decimal (inteiro e positivo): ");
    scanf("%d", &numeroDecimal);

    if (numeroDecimal < 0) {
        printf("Erro: Este programa funciona apenas com numeros positivos.\n");
    } else {
        converterDecimalParaBinario(numeroDecimal);
    }

    return 0;
}
