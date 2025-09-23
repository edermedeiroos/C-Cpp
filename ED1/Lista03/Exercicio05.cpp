#include <iostream>
using namespace std;

typedef int TIPOCHAVE;

typedef struct {
    TIPOCHAVE chave;
} REGISTRO;

typedef struct aux {
	REGISTRO reg;
	struct aux* prox;
} ELEMENTO, *PONT;

typedef struct {
	PONT inicio; 
	PONT fim;
} FILA;

void inicializacaoFila(FILA* f) {
    f->inicio = NULL;
    f->fim = NULL;
}

void inserirElemento(FILA* f, REGISTRO reg) {
    PONT novoElem = new ELEMENTO;
    novoElem->reg = reg;
    novoElem->prox = NULL;

    if (f->inicio = NULL) {
        f->inicio = novoElem;
    } else {
        f->fim->prox = novoElem;
    }
}

bool removerElemento(FILA* f, REGISTRO* elemCopia) {
    if (f->inicio != NULL) {

        *elemCopia = f->inicio->reg;
        PONT apagar = f->inicio;
        f->inicio = f->inicio->prox;
        delete f->inicio;

        if (f->inicio = NULL) {
            f->fim = NULL;
        }

        return true;
    } else {
        return false;
    }
}

int tamanhoFila(FILA f) {
    int tamanho = 0;
    while (f.inicio != NULL) {
        tamanho += 1;
        f.inicio = f.inicio->prox;
    }

    return tamanho;
}

void exibirFila(FILA f) {
    while (f.inicio != NULL) {
        cout << f.inicio->reg.chave << endl;
        f.inicio = f.inicio->prox;
    }
}

void reinicializarFila(FILA* f) {
    while (f->inicio != NULL) {
        PONT apagar = f->inicio;
        f->inicio = f->inicio->prox;
        delete apagar;
    }

    f->inicio = NULL;
    f->fim = NULL;
}

int main() {}