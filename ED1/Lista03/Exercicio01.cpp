#include <iostream>
using namespace std;

#define MAX 5

typedef int TIPOCHAVE;

typedef struct {
    TIPOCHAVE chave;
} REGISTRO;

typedef struct {
    REGISTRO A[MAX];
    int inicio, nroElem;
} FILA;

void inicializacaoFila(FILA* f) {
    f->inicio = 0;
    f->nroElem = 0;
}

bool inserirElemento(FILA* f, REGISTRO reg) {
    if (f->nroElem >= MAX) return false;

    int indice = (f->inicio + f->nroElem) % MAX;
    f->A[indice] = reg;
    f->nroElem += 1;

    return true;
}

bool removerElemento(FILA* f, REGISTRO* regCopia) {
    if (f->nroElem == 0) return false;

    *regCopia = f->A[f->inicio];
    f->inicio = (f->inicio + 1) % MAX;
    f->nroElem -= 1;

    return true;
}

int tamanhoFila(FILA f) {
    return f.nroElem;
}

void exibirFila(FILA f) {
    for (int i=0; i<f.nroElem; i++) {
        cout << f.A[i].chave << endl;
    }
}

void reinicializarFila(FILA* f) {
    inicializacaoFila(f);
}

int main() {}