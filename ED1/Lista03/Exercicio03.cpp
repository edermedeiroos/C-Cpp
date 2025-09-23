#include <iostream>
using namespace std;

#define MAX 50

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
    f->nroElem--;

    return true;
}

int tamanhoFila(FILA f) {
    return f.nroElem;
}

void exibirFila(FILA f) {
    for (int i=f.inicio; i<(f.inicio + f.nroElem); i++) {
        cout << f.A[i].chave << endl;
    }
}

void reinicializarFila(FILA* f) {
    inicializacaoFila(f);
}

int main() {
    FILA fila;
    inicializacaoFila(&fila);

    REGISTRO reg;

    for (int i=1; i<51; i++) {
        reg.chave = i;
        inserirElemento(&fila, reg);
    }

    exibirFila(fila);

    for (int i=0; i<10; i++) {
        removerElemento(&fila, &reg);
    }

    exibirFila(fila);

    for (int i=1; i<10; i++) {
        reg.chave = i*10;
        inserirElemento(&fila, reg);
    }

    exibirFila(fila);
    reinicializarFila(&fila);
}
