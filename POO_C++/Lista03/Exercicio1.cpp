#include <iostream>
using namespace std;

int main() {
    int num_linhas, num_colunas;

    // Pede as dimensões da matriz ao usuário
    cout << "Digite o numero de linhas: ";
    cin >> num_linhas;
    cout << "Digite o numero de colunas: ";
    cin >> num_colunas;

    // matriz é um ponteiro que aponta para um array de ponteiros de inteiro
    int** matriz = new int*[num_linhas];

    for (int i = 0; i < num_linhas; ++i) {
        // Para cada ponteiro de linha, alocamos um array de inteiros (as colunas)
        matriz[i] = new int[num_colunas];
    }

    // Preenchendo a matriz com valores
    for (int i = 0; i < num_linhas; ++i) {
        for (int j = 0; j < num_colunas; ++j) {
            matriz[i][j] = (i + 1) * 10 + (j + 1); // Ex: linha 0, col 0 -> 11
        }
    }

    // Imprimindo a matriz
    for (int i = 0; i < num_linhas; ++i) {
        for (int j = 0; j < num_colunas; ++j) {
            cout << matriz[i][j] << "\t"; // '\t' para tabular e alinhar
        }
        cout << endl;
    }

    // Liberar cada uma das linhas
    for (int i = 0; i < num_linhas; ++i) {
        delete[] matriz[i];
    }

    // Liberar o array de ponteiros
    delete[] matriz;
    return 0;
}