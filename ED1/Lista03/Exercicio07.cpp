#include <iostream>
#include <chrono>
using namespace std;

#define MAX 500000

typedef int TIPOCHAVE;
typedef struct {
    TIPOCHAVE chave;
} REGISTRO;

typedef struct {
    REGISTRO A[MAX];
    int inicio, nroElem;
} FILAESTATICA;

typedef struct aux {
	REGISTRO reg;
	struct aux* prox;
} ELEMENTO, *PONT;

typedef struct {
	PONT inicio; 
	PONT fim;
    int tamanho;
} FILADINAMICA;

void inicializacaoFila(string tipo, FILADINAMICA* fd=NULL, FILAESTATICA* fe=NULL) {
    if (tipo == "dinamica") {

        fd->inicio = NULL;
        fd->fim = NULL;
        fd->tamanho = 0;

    } else {

        fe->inicio = 0;
        fe->nroElem = 0;

    }
}

bool inserirElemento(string tipo, FILADINAMICA* fd=NULL, FILAESTATICA* fe=NULL, REGISTRO* reg=NULL) {
    if (tipo == "dinamica") {

        PONT novoElem = new ELEMENTO;
        novoElem->reg = *reg;
        novoElem->prox = NULL;

        if (fd->inicio == NULL) {
            fd->inicio = novoElem;
            fd->fim = novoElem;
        } else {
            fd->fim->prox = novoElem;
            fd->fim = novoElem;
        }

        fd->tamanho++;
        return true;

    } else {

        if (fe->nroElem >= MAX) return false;

        int indice = (fe->inicio + fe->nroElem) % MAX;
        fe->A[indice] = *reg;
        fe->nroElem += 1;

        return true;
    }
}

bool removerElemento(string tipo, FILADINAMICA* fd=NULL, FILAESTATICA* fe=NULL, REGISTRO* elemCopia=NULL) {
    if (tipo == "dinamica") {

        if (fd->inicio != NULL) {

            *elemCopia = fd->inicio->reg;
            PONT apagar = fd->inicio;
            fd->inicio = fd->inicio->prox;
            delete apagar;

            if (fd->inicio == NULL) {
                fd->fim = NULL;
            }
            fd->tamanho--;
            return true;

        } else {

            return false;

        }
        
    } else {

        if (fe->nroElem == 0) return false;

        *elemCopia = fe->A[fe->inicio];
        fe->inicio = (fe->inicio + 1) % MAX;
        fe->nroElem -= 1;

        return true;
    }
}

int tamanhoFila(string tipo, FILADINAMICA* fd=NULL, FILAESTATICA* fe=NULL) {
    if (tipo == "dinamica") {

        return fd->tamanho;

    } else {

        return fe->nroElem;

    }

}

void exibirFila(string tipo, FILADINAMICA* fd=NULL, FILAESTATICA* fe=NULL) {
    if (tipo == "dinamica") {

        PONT atual = fd->inicio;
        while (atual != NULL) {
            cout << atual->reg.chave << endl;
            atual = atual->prox;
        }

    } else {

        for (int i=0; i<fe->nroElem; i++){
            int indice = (fe->inicio + i) % MAX;
            cout << fe->A[indice].chave << endl;
        }

    }

}

void reinicializarFila(string tipo, FILADINAMICA* fd=NULL, FILAESTATICA* fe=NULL) {
    if (tipo == "dinamica") {

        while (fd->inicio != NULL) {
            PONT apagar = fd->inicio;
            fd->inicio = fd->inicio->prox;
            delete apagar;
        }

        fd->inicio = NULL;
        fd->fim = NULL;
        fd->tamanho = 0;

    } else {

        inicializacaoFila("estatica", NULL, fe);

    }

}

void reinicializarFila(FILADINAMICA* f) {
    while (f->inicio != NULL) {
        PONT apagar = f->inicio;
        f->inicio = f->inicio->prox;
        delete apagar;
    }

    f->inicio = NULL;
    f->fim = NULL;
}

int main() {

    FILADINAMICA filaDinamica;
    FILAESTATICA filaEstatica;
    REGISTRO reg;
    inicializacaoFila("dinamica", &filaDinamica, NULL);
    inicializacaoFila("estatica", NULL, &filaEstatica);

    auto inicio = chrono::high_resolution_clock::now();
    for (int i=0; i<MAX; i++) {
        reg.chave = i;
        inserirElemento("estatica", NULL, &filaEstatica, &reg);
    }
    auto fim = chrono::high_resolution_clock::now();
    double tempoFilaEstInsercao = chrono::duration_cast<chrono::duration<double>>(fim - inicio).count();
    cout << tempoFilaEstInsercao << endl;

    auto inicio2 = chrono::high_resolution_clock::now();
    for (int i=0; i<MAX; i++) {
        reg.chave = i;
        inserirElemento("dinamica", &filaDinamica, NULL, &reg);
    }
    auto fim2 = chrono::high_resolution_clock::now();
    double tempoFilaEstInsercao2 = chrono::duration_cast<chrono::duration<double>>(fim2 - inicio2).count();
    cout << tempoFilaEstInsercao2 << endl;

    reinicializarFila(&filaDinamica);

}

/*
A fila estática ganha em velocidade pois ja reserva todos os pedaços de memória logo em sua inicialização,
enquanto a fila dinâmica deve, a cada iteração para adição de um elemento, verificar um espaço de memória vazio,
e só então inserir seu elemento.
*/
