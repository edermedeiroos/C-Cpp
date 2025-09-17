#include <iostream>
#include <string>
using namespace std;

class Livro {
    private:
        string titulo, autor;
        int anoDePublicacao;
        static int quantidadeDeLivros;

    public:
        // Constructor
        Livro(string t, string a, int adp) {
            cout << "Criando Livro" << endl;

            titulo = t;
            autor = a;
            anoDePublicacao = adp;

            quantidadeDeLivros++;
        }

        ~Livro() {
            cout << "Destruindo Livro" << endl;

            quantidadeDeLivros--;
        }

        void exibirInfo() {
            cout << titulo << endl;
            cout << autor << endl;
            cout << anoDePublicacao << endl;
        }

        static int get_quantidade_de_livros();
};

int Livro::quantidadeDeLivros = 0;
int Livro::get_quantidade_de_livros() {
    return quantidadeDeLivros;
}

int main() {

    Livro** livros = new Livro*[100];

    livros[0] = new Livro("Harry Potter", "J. K.", 2000);
    livros[1] = new Livro("Harry Potter", "J. K.", 2000);
    livros[2] = new Livro("Harry Potter", "J. K.", 2000);

    livros[0]->exibirInfo();
    livros[1]->exibirInfo();
    livros[2]->exibirInfo();

    int quantidadeLivros = Livro::get_quantidade_de_livros();

    for (int i=0; i<quantidadeLivros; i++){
        delete livros[i];
    }

    delete [] livros;

}