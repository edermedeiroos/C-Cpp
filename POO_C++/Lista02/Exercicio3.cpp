#include <iostream>
using namespace std;

bool verifica_bissexto(int ano) {
    if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int ano;
    cout << "Verificação de ano Bissexto: ";
    cin >> ano;
    if (verifica_bissexto(ano)) {
        cout << "O ano " << ano << " é bissexto" << endl;
    } else {
        cout << "O ano " << ano << " não é bissexto" << endl;
    }

    return 0;
}