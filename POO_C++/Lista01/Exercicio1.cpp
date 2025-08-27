#include <iostream>
#include <string>
using namespace std;

int main() {
    struct notas {
        float nota1;
        float nota2;
        float nota3;
        float nota4; 
    };

    int array_notas[4] ;
    for (int i = 0; i <= 3; i++) {
        cout << "Nota " << i+1 << " do aluno: " << endl;
        cin >> array_notas[i];
    };

    notas aluno;
    aluno.nota1 = array_notas[0];
    aluno.nota2 = array_notas[1];
    aluno.nota3 = array_notas[2];
    aluno.nota4 = array_notas[3];

    float media;
    media = (aluno.nota1 + aluno.nota2 + aluno.nota3 + aluno.nota4)/4;
    cout << media << endl;

    if (media < 4) {
        cout << "Reprovado" << endl;
    } else if (media < 6) {
        cout << "Exame" << endl;
    } else {
        cout << "Aprovado" << endl;
    };

    return 0;
}