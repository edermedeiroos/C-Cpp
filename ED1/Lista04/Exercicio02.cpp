#include <iostream>
#include <string>

using namespace std;

#define MAX 50

typedef int TIPOCHAVE;

typedef struct {
    TIPOCHAVE chave;
} REGISTRO;

typedef struct {
    REGISTRO A[MAX];
    int nElem;
} LISTA;

void inicializarLista(LISTA* l) {
    l->nElem = 0;
}

bool inserirElemento(LISTA* l, TIPOCHAVE chave, int posicao) {
    if ((l->nElem >= MAX) || (posicao < 0) || (posicao > l->nElem)) {
        return false;
    }

    for (int i = l->nElem; i > posicao; i--) {
        l->A[i] = l->A[i - 1];
    }

    REGISTRO novoRegistro;
    novoRegistro.chave = chave;
    l->A[posicao] = novoRegistro;

    l->nElem++;

    return true;
}

bool removerElemento(LISTA* l, int posicao) {
    if ((posicao < 0) || (posicao >= l->nElem)) {
        return false;
    }

    for (int i = posicao; i < l->nElem - 1; i++) {
        l->A[i] = l->A[i + 1];
    }

    l->nElem--;
    return true;
}

int tamanhoLista(LISTA* l) {
    return l->nElem;
}

void exibirLista(LISTA* l) {
    cout << "Lista: [ ";
    for (int i = 0; i < l->nElem; i++) {
        cout << l->A[i].chave << " ";
    }
    cout << "]" << " (Tamanho: " << l->nElem << ")" << endl;
}

int buscarElemento(LISTA* l, TIPOCHAVE chave) {
    for (int i = 0; i < l->nElem; i++) {
        if (l->A[i].chave == chave) {
            return i;
        }
    }
    return -1;
}

void reinicializarLista(LISTA* l) {
    l->nElem = 0;
}

int main() {
    LISTA lista;
    inicializarLista(&lista);

    for (int i=0; i<5; i++) {
        int chave, posicao;

        cout << "Elemento à ser inserido na lista: ";
        cin >> chave;
        cout << "Posição de inserção: ";
        cin >> posicao;

        inserirElemento(&lista, chave, posicao);
    }

    exibirLista(&lista);
}
