#include <iostream>
#include <string>
using namespace std;

class Livro {

    private:
        string titulo, autor;
        bool disponivel;

        void setter_titulo(string value) {
            titulo = value;
        } 

        void setter_autor(string value) {
            autor = value;
        } 

        void setter_disponivel(bool value) {
            disponivel = value;
        } 

        string getter_titulo() {
            return titulo;
        }

        string getter_autor() {
            return autor;
        }

        bool getter_disponivel() {
            return disponivel;
        }

    public:
        Livro(string t="Titulo", string a="Autor") { // Constructor
            setter_titulo(t);
            setter_autor(a);
            setter_disponivel(true);
        }

        void mostrarDetalhes() {
            cout << "Titulo: " << getter_titulo() << endl;
            cout << "Autor: " << getter_autor() << endl;
            cout << "Disponivel: " << getter_disponivel() << endl << endl;
        }

        void emprestar() {
            setter_disponivel(false);
        }

        void devolver() {
            setter_disponivel(true);
        }

};

class Membro {
    private:
        string nome;
        int idMembro;
        Livro livrosEmprestados[4];

        void setter_nome(string value) {
            nome = value;
        }

        void setter_idMembro(int value) {
            idMembro = value;
        }
        
        string getter_nome() {
            return nome;
        }

        int getter_idMembro() {
            return idMembro;
        }

    public:
        static int totalMembros; 
        Membro(string n) {
            setter_nome(n);
            setter_idMembro(totalMembros);
            totalMembros++;
        }

        ~Membro() {
            setter_nome("");
            setter_idMembro(0);
            totalMembros--;
        }

        void mostrarDetalhes() {
            cout << "Nome" << getter_nome() << endl;
            cout << "ID Membro" << getter_idMembro() << endl;
            for (int i=0; i<4; i++) {
                cout << "Livro emprestado " << i << ": " << endl;
                livrosEmprestados[i].mostrarDetalhes();
            }
        }

};
