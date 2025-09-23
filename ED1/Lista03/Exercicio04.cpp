#include <iostream>
using namespace std;

#define MAX 50

typedef int ID;
typedef int NUMPAG;

typedef struct {
    ID id;
    NUMPAG numPag;
} IMPRESSAO;

typedef struct {
    IMPRESSAO A[MAX];
    int inicio, nroImpressoes;
} FILA;

void inicializacaoFila(FILA* f) {
    f->inicio = 0;
    f->nroImpressoes = 0;
}

bool inserirImpressao(FILA* f, IMPRESSAO impressao) {
    if (f->nroImpressoes >= MAX) return false;

    int indice = (f->inicio + f->nroImpressoes) % MAX;
    f->A[indice] = impressao;
    f->nroImpressoes += 1;

    return true;
}

bool removerImpressao(FILA* f, IMPRESSAO* impressaoCopia) {
    if (f->nroImpressoes == 0) return false;

    *impressaoCopia = f->A[f->inicio];
    f->inicio = (f->inicio + 1) % MAX;
    f->nroImpressoes--;

    return true;
}

int tamanhoFila(FILA f) {
    return f.nroImpressoes;
}

void exibirFila(FILA f) {
    for (int i=f.inicio; i<(f.inicio + f.nroImpressoes); i++) {
        cout << "ID da impressão: " << f.A[i].id << endl;
        cout << "Número de páginas da impressão: " << f.A[i].numPag << endl << endl;
    }
}

void reinicializarFila(FILA* f) {
    inicializacaoFila(f);
}

int main() {
    FILA filaImpressao;
    inicializacaoFila(&filaImpressao);
    IMPRESSAO impressao;

    for (int i=1; i <= 10; i++) {
        impressao.id = i;
        impressao.numPag = i*5;
        inserirImpressao(&filaImpressao, impressao);
    }

    exibirFila(filaImpressao);

    for (int i=0; i<3; i++) {
        removerImpressao(&filaImpressao, &impressao);
    }

    exibirFila(filaImpressao);

    for (int i=1; i<=5; i++) {
        impressao.id = i*20;
        impressao.numPag = i*100;
        inserirImpressao(&filaImpressao, impressao);
    }

    exibirFila(filaImpressao);
}
