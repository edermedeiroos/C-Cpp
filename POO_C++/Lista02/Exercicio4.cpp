#include <iostream>
using namespace std;

bool primo_recursivo_helper(int n, int divisor) {
    if (divisor * divisor > n) {
        return true;
    }

    if (n % divisor == 0) {
        return false;
    }

    return primo_recursivo_helper(n, divisor + 1);
}

bool is_primo(int num) {
    if (num <= 1) {
        return false;
    }

    return primo_recursivo_helper(num, 2);
}

int main() {
    int numero;
    cout << "Verificador de número primo: ";
    cin >> numero;

    if (is_primo(numero)) {
        cout << "O número " << numero << " é primo!" << endl;
    } else {
        cout << "O número " << numero << " não é primo." << endl;
    };

    return 0;
}