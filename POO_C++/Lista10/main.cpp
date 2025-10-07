#include <iostream>
#include <string>
#include "Personagem.hpp"

using namespace std;

double Personagem::danoBase = 2;
int Jogo::totalPersonagens = 0;

int main() {

    // Criação Personagem 1
    Personagem* personagem1;
    personagem1 = new Personagem("Cavaleiro", 5, 10);

    // Criação Personagem 2
    Personagem* personagem2;
    personagem2 = new Personagem("Mago", 8, 6);

    // Criação Personagem 3
    Personagem* personagem3;
    personagem3 = new Personagem("Soldado", 3, 5);

    cout << "Total de Personagens Criados: " << Jogo::getTotalPersonagens() << endl;

    personagem1->atacar(personagem2);
    personagem2->atacar(personagem3);
    personagem3->atacar(personagem1);

    delete personagem1;
    delete personagem2;
    delete personagem3;
}