#include <iostream>
#include "Calculadora.hpp"
using namespace std;

double Calculadora::soma(double a, double b) {
    return a+b;
}

double Calculadora::subtracao(double a, double b) {
    return a-b;
}

double Calculadora::multiplicacao(double a, double b) {
    return a*b;
}

double Calculadora::divisao(double a, double b) {
    return a/b;
}

int main() {
    
    double a, b;
    int opcao;

    cout << "--- CALCULADORA ---" << endl;
    cout << "\n- Valor a: ";
    cin >> a;
    cout << "\n- Valor b:";
    cin >> b;

    cout << "\n[1] Soma\n[2] Subtração\n[3] Multiplicação\n[4] Divisão" << endl;
    cout << "\n- Operação desejada: ";
    cin >> opcao;

    switch (opcao) {
        case 1:
            cout << "Soma a+b = " << Calculadora::soma(a, b) << endl;
            break;
        
        case 2:
            cout << "Subtração a-b = " << Calculadora::subtracao(a, b) << endl;
            break;

        case 3:
            cout << "Multiplicação a*b = " << Calculadora::multiplicacao(a, b) << endl;
            break;

        case 4:
            cout << "Divisão a/b = " << Calculadora::divisao(a, b) << endl;
            break;
        } 
}
