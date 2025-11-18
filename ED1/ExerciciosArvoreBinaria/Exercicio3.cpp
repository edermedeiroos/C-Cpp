#include <iostream>
#include <string>

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

No* buscarNo(No* raiz, int valor) {
    if (raiz == nullptr || raiz->dado == valor) {
        return raiz;
    }
    No* encontrado = buscarNo(raiz->esquerda, valor);
    if (encontrado != nullptr) {
        return encontrado;
    }
    return buscarNo(raiz->direita, valor);
}

void inserirFilho(No* raiz, int pai, int filho, string direcao) {
    No* noPai = buscarNo(raiz, pai);
    if (noPai != nullptr) {
        if (direcao == "esquerdo") {
            noPai->esquerda = criarNovoNo(filho);
        } else if (direcao == "direito") {
            noPai->direita = criarNovoNo(filho);
        }
    }
}

bool buscarComCaminho(No* raiz, int chave) {
    if (raiz == nullptr) {
        return false;
    }

    cout << "- Visitado: " << raiz->dado << endl;

    if (raiz->dado == chave) {
        cout << "- Encontrado!" << endl;
        return true;
    }

    if (chave < raiz->dado) {
        return buscarComCaminho(raiz->esquerda, chave);
    }
    return buscarComCaminho(raiz->direita, chave);
}

int main() {
    No* raiz = criarNovoNo(40);

    inserirFilho(raiz, 40, 20, "esquerdo");
    inserirFilho(raiz, 40, 60, "direito");
    inserirFilho(raiz, 20, 10, "esquerdo");
    inserirFilho(raiz, 20, 30, "direito");

    int alvo = 30;
    cout << "- Buscando por " << alvo << "..." << endl;
    buscarComCaminho(raiz, alvo);

    return 0;
}
