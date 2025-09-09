#include <stdio.h>
#define MAX 50

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

bool PilhaVazia(PILHA* p) {
    if (p->topo == -1)
        return true;
    else 
        return false;
}

bool excluirElementoPilha(PILHA* p, REGISTRO* reg) { 
    if (PilhaVazia(p)) {
        return false;
    }

    *reg = p->A[p->topo];
    p->topo = p->topo-1;
    return true;
}