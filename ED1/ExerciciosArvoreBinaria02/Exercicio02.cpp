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
    else raiz->dir = inserir(raiz->dir, valor);
    return raiz;
}

// Retorna o nó e seu pai por referência
void buscarComPai(No* raiz, int chave, No*& atual, No*& pai) {
    atual = raiz;
    pai = NULL;
    while (atual != NULL && atual->valor != chave) {
        pai = atual;
        if (chave < atual->valor) atual = atual->esq;
        else atual = atual->dir;
    }
}

No* encontrarMinimo(No* no) {
    while (no->esq != NULL) no = no->esq;
    return no;
}

No* remover(No* raiz, int chave) {
    No *atual, *pai;
    buscarComPai(raiz, chave, atual, pai);

    if (atual == NULL) return raiz; // Não encontrado

    // Caso 1 e 2: 0 ou 1 filho
    if (atual->esq == NULL || atual->dir == NULL) {
        No* novoFilho = (atual->esq != NULL) ? atual->esq : atual->dir;
        
        if (pai == NULL) raiz = novoFilho; // Removendo a raiz
        else if (pai->esq == atual) pai->esq = novoFilho;
        else pai->dir = novoFilho;
        
        delete atual;
    }
    // Caso 3: 2 filhos
    else {
        No* sucessor = encontrarMinimo(atual->dir);
        int valSucessor = sucessor->valor;
        raiz = remover(raiz, valSucessor); // Remove recursivamente o sucessor
        
        // Precisamos atualizar o nó atual com o valor do sucessor
        // Como o 'atual' original pode ter sido invalidado, buscamos novamente
        buscarComPai(raiz, chave, atual, pai); 
        atual->valor = valSucessor;
    }
    return raiz;
}

void imprimir(No* raiz) {
    if (!raiz) return;
    imprimir(raiz->esq);
    cout << raiz->valor << " ";
    imprimir(raiz->dir);
}

int main() {
    No* raiz = NULL;
    raiz = inserir(raiz, 50);
    raiz = inserir(raiz, 30);
    raiz = inserir(raiz, 70);
    raiz = inserir(raiz, 40); 

    cout << "Original: "; imprimir(raiz); cout << endl;

    raiz = remover(raiz, 30); // Remove nó com filhos

    cout << "Apos remover 30: "; imprimir(raiz); cout << endl;
    return 0;
}