#include <iostream>
using namespace std;

// Exercício 1:

int vetor[5] = {7, 2, 9, 4, 1};

// Primeira Passagem:

int vetor[5] = {2, 7, 4, 1, 9}; // 3 Trocas

// Segunda Passagem:

int vetor[5] = {2, 4, 1, 7, 9}; // 2 Trocas

// Terceira Passagem:

int vetor[5] = {2, 1, 4, 7, 9}; // 1 Troca

// Quarta Passagem:

int vetor[5] = {1, 2, 4, 7, 9}; // 1 Troca

// São realizadas 7 trocas.
// O algoritmo é estavel pois não troca valores equivalentes.

// ----------------------------------------------------------

// Exercício 2:

struct TItem {
    int Chave;
};

void Bolha(TItem *v, int n) {
    int i, j;
    TItem aux;
    for (i = 0; i < n - 1; i++) {
        for (j = 1; j < n - i; j++) {
            if (v[j].Chave < v[j - 1].Chave) {
                aux = v[j];
                v[j] = v[j - 1];
                v[j - 1] = aux;
            }
        }
    }
}

void imprimirItens(TItem *v, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Chave: " << v[i].Chave << endl;
    }
}

int main() {
    const int N = 3;
    TItem alunos[N];

    alunos[0] = {102};
    alunos[1] = {101};
    alunos[2] = {103};

    imprimirItens(alunos, N);

    Bolha(alunos, N);

    imprimirItens(alunos, N);
}

// Ao todo, foram feitas 3 comparações e 1 troca
