#include <iostream>
using namespace std;

struct No {
    int valor;
    No *esq, *dir;
    No(int v) : valor(v), esq(NULL), dir(NULL) {}
};

No* inserir(No* raiz, int valor) {
    if (!raiz) return new No(valor);
    if (valor < raiz->valor) raiz->esq = inserir(raiz->esq, valor);
    else if (valor > raiz->valor) raiz->dir = inserir(raiz->dir, valor);
    return raiz;
}

int contarNos(No* raiz) {
    if (!raiz) return 0;
    return 1 + contarNos(raiz->esq) + contarNos(raiz->dir);
}

void exibirEmOrdem(No* raiz) { // Método simples para validar a árvore
    if (!raiz) return;
    exibirEmOrdem(raiz->esq);
    cout << raiz->valor << " ";
    exibirEmOrdem(raiz->dir);
}

int main() {
    No* raiz = NULL;
    raiz = inserir(raiz, 50);
    raiz = inserir(raiz, 30);
    raiz = inserir(raiz, 70);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 40);

    cout << "Arvore (Em Ordem): ";
    exibirEmOrdem(raiz);
    cout << "\nTotal de nos: " << contarNos(raiz) << endl;

    return 0;
}