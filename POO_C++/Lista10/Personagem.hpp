#include <iostream>
#include <string>
using namespace std;

class Jogo { 
    public:
        static int totalPersonagens;
        static int getTotalPersonagens() {
            return totalPersonagens;
        }
};

class Personagem {
    private:
        string nome;
        int nivel;
        double vida;

    public:
        static double danoBase;

        Personagem(string nom, int niv, double vid) {
            nome = nom;
            nivel = niv;
            vida = vid;
            Jogo::totalPersonagens++;
        }

        ~Personagem() {
            Jogo::totalPersonagens++;
        }

        void exibir() {
            cout << nome << endl;
            cout << nivel << endl;
            cout << vida << endl;
        }

        void atacar(Personagem* ferido) {
            cout << "Dano do Ataque: " << danoBase << endl;
            cout << "Vida inicial " << ferido->nome << ": " << ferido->vida << endl;
            ferido->retirar_vida(danoBase);
            cout << "Vida final " << ferido->nome << ": " << ferido->vida << endl;
        }

        void retirar_vida(double dano) {
            vida -= dano;
        }
};
