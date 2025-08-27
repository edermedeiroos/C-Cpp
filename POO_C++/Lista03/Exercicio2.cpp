#include <iostream>
using namespace std;

// Esta função recebe os ENDEREÇOS de 'a' e 'b'.
// ptrA e ptrB são ponteiros que guardam esses endereços.
int troca_por_ponteiro(int* ptrA, int* ptrB) {
    cout << "Enderecos recebidos: ptrA=" << ptrA << ", ptrB=" << ptrB << endl;

    int temp = *ptrA; // temp recebe o VALOR que está no endereço ptrA
    *ptrA = *ptrB;    // O VALOR no endereço ptrA recebe o VALOR do endereço ptrB
    *ptrB = temp;     // O VALOR no endereço ptrB recebe o valor de temp

    return 0;
}

int main() {
    int num1 = 10;
    int num2 = 20;

    cout << "Valores ANTES da chamada: num1=" << num1 << ", num2=" << num2 << endl;

    troca_por_ponteiro(&num1, &num2); // Execução da troca dos valores

    cout << "Valores DEPOIS da chamada: num1=" << num1 << ", num2=" << num2 << endl;

    return 0;
}