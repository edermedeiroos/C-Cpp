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

int buscaSequencial(LISTA* l, TIPOCHAVE ch) {
		int i = 0;
		
		while (i < l->nElem){
				if(ch == l->A[i].chave) return i;
				else i++;
		}
		
		return -1;
}

bool removerElemento(LISTA* l, TIPOCHAVE ch) {
    int pos = buscaSequencial(l, ch);
    if (pos == -1) return false;

    for (int i = pos; i < l->nElem -1; i++) {
        l->A[i] = l->A[i+1];
    }

    l->nElem --;
    return true;
}

int tamanhoLista(LISTA* l) {
    return l->nElem;
}

void exibirElemento(LISTA* l) {
    for (int i=0; i<l->nElem; i++) {
        cout << l->A[i].chave << endl;
    }
}

bool reinicializarLista(LISTA* l) {
    inicilizarLista(l);
}
