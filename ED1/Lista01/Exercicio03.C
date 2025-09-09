#include <stdio.h>
#define MAX 10

typedef int bool;
#define true 1
#define false 0
typedef int TIPOCHAVE;

typedef struct {
        TIPOCHAVE chave;
} REGISTRO;

typedef struct {
        REGISTRO A[MAX];
        int topo;
} PILHA;

bool PilhaCheia(PILHA* p) {
    if (p->topo >= MAX-1)
        return true;
    else 
        return false;
}

bool PilhaVazia(PILHA* p) {
    if (p->topo == -1)
        return true;
    else 
        return false;
}

bool inserirElementoPilha(PILHA* p, REGISTRO reg) { 
    if (PilhaCheia(p)) {
        return false;
    }

    p->topo = p->topo + 1;
    p->A[p->topo] = reg;
    return true;
}

bool excluirElementoPilha(PILHA* p, REGISTRO* reg) { 
    if (PilhaVazia(p)) {
        return false;
    }

    *reg = p->A[p->topo];
    p->topo = p->topo-1;
    return true;
}

PILHA invertePilha(PILHA* p) {
    PILHA pilhaAux;
    pilhaAux.topo = -1;

    for (int i = p->topo; i > -1; i--) {
        inserirElementoPilha(&pilhaAux, p->A[i]);
    }

    return pilhaAux;
}
