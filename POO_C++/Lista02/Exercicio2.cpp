#include <iostream>
using namespace std;

int soma_valores(int num=0) {
    if (num == 0) {
        return 0;
    } else {
        return num += soma_valores(num-1);
    };
};

int main() {
    int numero;
    cout << "Digite um número: ";
    cin >> numero;

    int somatoria_numeros = soma_valores(numero);

    cout << "A soma dos valores unitários até 0 é: " << somatoria_numeros << endl;
    return 0;
}