#include <iostream>

using namespace std;

struct No {
    int dado;
    No* esquerda;
    No* direita;
};

No* criarNovoNo(int valor) {
    No* novo = new No;
    novo->dado = valor;
    novo->esquerda = nullptr;
    novo->direita = nullptr;
    return novo;
}

No* criarRaiz(int valor) {
    return criarNovoNo(valor);
}

No* inserirFilho(No* raiz, int valor) {
    if (raiz == nullptr) {
        return criarNovoNo(valor);
    }
    if (valor < raiz->dado) {
        raiz->esquerda = inserirFilho(raiz->esquerda, valor);
    } else if (valor > raiz->dado) {
        raiz->direita = inserirFilho(raiz->direita, valor);
    }
    return raiz;
}

bool buscarChave(No* raiz, int chave) {
    if (raiz == nullptr) {
        return false;
    }
    if (raiz->dado == chave) {
        return true;
    }
    if (chave < raiz->dado) {
        return buscarChave(raiz->esquerda, chave);
    }
    return buscarChave(raiz->direita, chave);
}

int main() {
    No* raiz = nullptr;

    raiz = criarRaiz(10);

    inserirFilho(raiz, 5);
    inserirFilho(raiz, 15);
    inserirFilho(raiz, 3);
    inserirFilho(raiz, 7);

    if (buscarChave(raiz, 7)) {
        cout << "Chave 7 encontrada" << endl;
    } else {
        cout << "Chave 7 nao encontrada" << endl;
    }

    if (buscarChave(raiz, 20)) {
        cout << "Chave 20 encontrada" << endl;
    } else {
        cout << "Chave 20 nao encontrada" << endl;
    }

    return 0;
}
