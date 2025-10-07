#include <iostream>
#include <string>
#include "Inter_Livro.hpp"
using namespace std;

int Membro::totalMembros = 0;
int main() {

    Membro** membros = new Membro*[3];

    membros[0] = new Membro("João Silva");
    membros[1] = new Membro("Maria Souza");
    membros[2] = new Membro("Pedro Costa");

    cout << Membro::totalMembros << endl;

    Livro** biblioteca = new Livro*[3];

    biblioteca[0] = new Livro("Duna", "Frank Herbert");
    biblioteca[1] = new Livro("O Guia do Mochileiro das Galáxias", "Douglas Adams");
    biblioteca[2] = new Livro("Fundação", "Isaac Asimov");

    for (int i = 0; i < 3; i++) {
        biblioteca[i]->mostrarDetalhes();
    }

    biblioteca[0]->mostrarDetalhes();
    biblioteca[0]->emprestar();
    biblioteca[0]->mostrarDetalhes();

    cout << Membro::totalMembros << endl;
    Membro* membroExtra = new Membro("Ana Beatriz");
    cout << Membro::totalMembros << endl;

    delete membroExtra;
    membroExtra = nullptr;
    cout << Membro::totalMembros << endl;

    // Limpeza do Array
    for (int i = 0; i < 3; ++i) {
        delete membros[i];
        delete biblioteca[i];
    }
    delete[] membros;
    membros = nullptr;

    cout << Membro::totalMembros << endl;
}
