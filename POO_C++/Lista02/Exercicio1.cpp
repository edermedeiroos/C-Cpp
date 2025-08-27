#include <iostream>
using namespace std;

int main() {
    int array[10];

    int espaco_array = sizeof(array);
    int espaco_elem = sizeof(array[0]);

    int tamanho_array;
    tamanho_array = espaco_array/espaco_elem;

    cout << tamanho_array << endl;

    return 0;
}