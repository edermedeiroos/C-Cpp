#include <iostream>
#include <string>

using namespace std;

#define MAX 50

typedef int TIPOCHAVE;

typedef struct {
    TIPOCHAVE chave;  
} REGISTRO;

typedef struct {
    REGISTRO A[50];
    int nElem;
} LISTA;

void inicilizarLista(LISTA* l) {
    l->nElem = 0;
}

bool inserirElemento(LISTA* l, TIPOCHAVE chave, int posicao) {
    if ((l->nElem = MAX) || (posicao >= MAX)) 
        return false;

    l->A[posicao].chave = chave;
    l->nElem ++;
    return true;
}

bool removerElement(LISTA* l, int posicao) {
    if ((l->nElem = 0) || (posicao >= MAX))
        return false;

    l->A[posicao].chave = NULL;
    l->nElem --;
    return true;
}

int tamanhoLista(LISTA* l) {
    return l->nElem;
}

void exibirElemento(LISTA* l) {
    for 
}
