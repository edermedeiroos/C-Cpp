#include <iostream>
#include <algorithm>

using namespace std;

struct No {
    int dado;
    No* esquerda;
    No* direita;
};

typedef No* PONT;

PONT criarNovoNo(int valor) {
    PONT novo = new No;
    novo->dado = valor;
    novo->esquerda = nullptr;
    novo->direita = nullptr;
    return novo;
}

PONT inserir(PONT raiz, int valor) {
    if (raiz == nullptr) return criarNovoNo(valor);
    if (valor < raiz->dado) raiz->esquerda = inserir(raiz->esquerda, valor);
    else if (valor > raiz->dado) raiz->direita = inserir(raiz->direita, valor);
    return raiz;
}

int contarNos(PONT raiz) {
    if (raiz == nullptr) return 0;
    return 1 + contarNos(raiz->esquerda) + contarNos(raiz->direita);
}

bool ehFolha(PONT no) {
    if (no == nullptr) return false;
    return (no->esquerda == nullptr && no->direita == nullptr);
}

int altura(PONT raiz) {
    if (raiz == nullptr) return 0;
    int altEsq = altura(raiz->esquerda);
    int altDir = altura(raiz->direita);
    if (altEsq > altDir) return altEsq + 1;
    else return altDir + 1;
}

void destruirArvore(PONT raiz) {
    if (raiz != nullptr) {
        destruirArvore(raiz->esquerda);
        destruirArvore(raiz->direita);
        delete raiz;
    }
}

int main() {
    PONT raiz = nullptr;

    raiz = inserir(raiz, 40);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 60);
    raiz = inserir(raiz, 10);
    raiz = inserir(raiz, 30);
    raiz = inserir(raiz, 50);
    raiz = inserir(raiz, 70);

    cout << "Total de nos: " << contarNos(raiz) << endl;
    cout << "Altura da arvore: " << altura(raiz) << endl;

    if (ehFolha(raiz->esquerda->esquerda)) { 
        cout << "O no 10 eh folha" << endl; 
    } else {
        cout << "O no 10 nao eh folha" << endl;
    }

    if (ehFolha(raiz)) { 
        cout << "A raiz eh folha" << endl; 
    } else {
        cout << "A raiz nao eh folha" << endl;
    }

    destruirArvore(raiz);
    raiz = nullptr; 
    cout << "Arvore destruida com sucesso" << endl;

    return 0;
}
