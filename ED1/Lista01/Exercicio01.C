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

bool PilhaCheia(PILHA* p) {
    if (p->topo >= MAX-1)
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