// Exercício 7

#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <random>
using namespace std;

int partition_lomuto(vector<int>& arr, int low, int high, long long& comparisons) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        comparisons++;
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort_first(vector<int>& arr, int low, int high, long long& comparisons) {
    if (low < high) {
        swap(arr[low], arr[high]);
        int pi = partition_lomuto(arr, low, high, comparisons);
        quickSort_first(arr, low, pi - 1, comparisons);
        quickSort_first(arr, pi + 1, high, comparisons);
    }
}

void quickSort_last(vector<int>& arr, int low, int high, long long& comparisons) {
    if (low < high) {
        int pi = partition_lomuto(arr, low, high, comparisons);
        quickSort_last(arr, low, pi - 1, comparisons);
        quickSort_last(arr, pi + 1, high, comparisons);
    }
}

void quickSort_middle(vector<int>& arr, int low, int high, long long& comparisons) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        swap(arr[mid], arr[high]);
        int pi = partition_lomuto(arr, low, high, comparisons);
        quickSort_middle(arr, low, pi - 1, comparisons);
        quickSort_middle(arr, pi + 1, high, comparisons);
    }
}

void run_test(const string& test_name, vector<int>& arr,
              void (*sort_func)(vector<int>&, int, int, long long&))
{
    vector<int> arr_copy = arr;
    long long comparisons = 0;

    auto start = chrono::high_resolution_clock::now();
    sort_func(arr_copy, 0, arr_copy.size() - 1, comparisons);
    auto stop = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

    cout << "  " << setw(18) << left << test_name
              << " | " << setw(15) << right << comparisons << " comparacoes"
              << " | " << setw(10) << right << duration.count() << " us" << endl;
}

int main() {
    const int N = 1000;

    vector<int> ascending(N);
    iota(ascending.begin(), ascending.end(), 1);

    vector<int> descending(N);
    iota(descending.begin(), descending.end(), 1);
    reverse(descending.begin(), descending.end());

    vector<int> random(N);
    mt19937 gen(random_device{}());
    uniform_int_distribution<> dis(1, N);
    generate(random.begin(), random.end(), [&]() { return dis(gen); });

    cout << "Testando Quick Sort com N = " << N << " elementos" << endl;

    cout << "Caso 1: Lista em Ordem Crescente" << endl;
    run_test("Pivo = Primeiro", ascending, quickSort_first);
    run_test("Pivo = Ultimo", ascending, quickSort_last);
    run_test("Pivo = Meio", ascending, quickSort_middle);

    cout << "Caso 2: Lista em Ordem Decrescente" << endl;
    run_test("Pivo = Primeiro", descending, quickSort_first);
    run_test("Pivo = Ultimo", descending, quickSort_last);
    run_test("Pivo = Meio", descending, quickSort_middle);

    cout << "Caso 3: Lista Aleatoria" << endl;
    run_test("Pivo = Primeiro", random, quickSort_first);
    run_test("Pivo = Ultimo", random, quickSort_last);
    run_test("Pivo = Meio", random, quickSort_middle);

    return 0;
}

// Exercício 8

// 1. Qual algoritmo para listas pequenas?
// Insertion Sort. Possui um "overhead" (custo fixo) muito baixo. Para listas pequenas
// seu O(n^2) é irrelevante e ele supera o custo das chamadas recursivas do Quick/Merge Sort.

// 2. Qual para grandes volumes de dados?
// Merge Sort. Ele tem desempenho garantido O(n log n) em *todos* os casos (sem "pior caso" O(n^2)).
// É o padrão para ordenação externa (dados que não cabem na RAM), pois lê e escreve de forma sequencial.

// 3. Por que Quick Sort é mais rápido na prática que o Merge Sort?
// Localidade de Referência (Cache da CPU). O Quick Sort particiona os dados no local (in-place),
// o que é muito "amigável" para o cache da CPU. O Merge Sort precisa copiar constantemente dados para um array auxiliar,
// o que é uma operação mais lenta e usa mal o cache.
