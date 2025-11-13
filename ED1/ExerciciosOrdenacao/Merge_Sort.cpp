#include <iostream>
#include <vector>

using namespace std;

// Função de mesclagem (merge).
// Combina dois subvetores ordenados (esquerda e direita) em um único
// vetor ordenado no array original 'arr'.
void merge(vector<int>& arr, int left, int mid, int right) {
    // 1. Calcular os tamanhos dos subvetores temporários
    int n1 = mid - left + 1; // Tamanho do subvetor da esquerda
    int n2 = right - mid;    // Tamanho do subvetor da direita

    // 2. Criar vetores temporários
    vector<int> L(n1);
    vector<int> R(n2);

    // 3. Copiar dados para os vetores temporários
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // 4. Mesclar os vetores temporários de volta em 'arr'
    int i = 0; // Índice inicial do primeiro subvetor (L)
    int j = 0; // Índice inicial do segundo subvetor (R)
    int k = left; // Índice inicial do vetor mesclado (arr)

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // 5. Copiar os elementos restantes de L[], se houver
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // 6. Copiar os elementos restantes de R[], se houver
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Função principal (recursiva) do Merge Sort.
void mergeSort(vector<int>& arr, int left, int right) {
    // Caso base: se o subvetor tem 0 ou 1 elemento, já está ordenado.
    if (left >= right) {
        return;
    }

    // 1. Encontrar o ponto médio (evita overflow para vetores muito grandes)
    int mid = left + (right - left) / 2;

    // 2. Chamar recursivamente para a metade esquerda
    mergeSort(arr, left, mid);

    // 3. Chamar recursivamente para a metade direita
    mergeSort(arr, mid + 1, right);

    // 4. Mesclar (merge) as duas metades ordenadas
    merge(arr, left, mid, right);
}

void printVector(const vector<int>& arr) {
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    // Vetor do Exercício 5
    vector<int> vec = {38, 27, 43, 3, 9, 82, 10};

    cout << "Vetor original: ";
    printVector(vec);

    // Chama o Merge Sort
    // Para um vetor 'vec' de tamanho N, chamamos de 0 a N-1
    mergeSort(vec, 0, vec.size() - 1);

    cout << "Vetor ordenado: ";
    printVector(vec);

    return 0;
}

/*
 * ===================================================================
 * RESPOSTAS DO EXERCÍCIO 6
 * ===================================================================
 *
 * 1. Quantas vezes a função merge() é chamada?
 *
 * Para o vetor do Exercício 5 (N=7), a função merge() é chamada 6 vezes.
 * De forma geral, para um vetor de tamanho N, a função merge()
 * é chamada N-1 vezes.
 *
 *
 * 2. O número de divisões (nível de recursão) gerado para um vetor de tamanho 16.
 *
 * O número de níveis de recursão (a profundidade da árvore de chamadas)
 * é determinado por log2(N).
 *
 * Para N = 16:
 * log2(16) = 4
 *
 * Nível 0: 1 vetor de tamanho 16
 * Nível 1: 2 vetores de tamanho 8
 * Nível 2: 4 vetores de tamanho 4
 * Nível 3: 8 vetores de tamanho 2
 * Nível 4: 16 vetores de tamanho 1 (Caso Base)
 *
 * O número de níveis de divisão (nível de recursão) é 4.
 *
 */