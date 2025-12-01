#include <iostream>
#include <queue> // Necessário para Varredura em Nível
using namespace std;

struct No {
    int valor;
    No *esq, *dir;
    No(int v) : valor(v), esq(NULL), dir(NULL) {}
};

No* inserir(No* raiz, int valor) {
    if (!raiz) return new No(valor);
    if (valor < raiz->valor) raiz->esq = inserir(raiz->esq, valor);
    else raiz->dir = inserir(raiz->dir, valor);
    return raiz;
}

// Raiz -> Esquerda -> Direita
void preOrdem(No* raiz) {
    if (!raiz) return;
    cout << raiz->valor << " ";
    preOrdem(raiz->esq);
    preOrdem(raiz->dir);
}

// Esquerda -> Direita -> Raiz
void posOrdem(No* raiz) {
    if (!raiz) return;
    posOrdem(raiz->esq);
    posOrdem(raiz->dir);
    cout << raiz->valor << " ";
}

// Nível por Nível (usa Fila)
void emNivel(No* raiz) {
    if (!raiz) return;
    queue<No*> q;
    q.push(raiz);
    
    while (!q.empty()) {
        No* atual = q.front();
        q.pop();
        cout << atual->valor << " ";
        
        if (atual->esq) q.push(atual->esq);
        if (atual->dir) q.push(atual->dir);
    }
}

int main() {
    No* raiz = NULL;
    raiz = inserir(raiz, 50);
    raiz = inserir(raiz, 30);
    raiz = inserir(raiz, 70);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 40);

    cout << "Pre-Ordem: "; preOrdem(raiz); cout << endl;
    cout << "Pos-Ordem: "; posOrdem(raiz); cout << endl;
    cout << "Em Nivel:  "; emNivel(raiz);  cout << endl;

    return 0;
}