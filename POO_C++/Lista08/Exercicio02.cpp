#include <iostream>
#include <string>
using namespace std;

class Aluno {
    private:
        string nome;
        int matricula;
        double notaFinal;
        static int quantidadeDeAlunos;
    
    public:
        Aluno(string n, int m, double nf) {
            nome = n;
            matricula = m;
            notaFinal = nf;
            quantidadeDeAlunos++;

            cout << "Aluno Adicionado" << endl;
        }

        ~Aluno() {
            nome = "Aluno";
            matricula = 0;
            notaFinal = 0;
            quantidadeDeAlunos--;

            cout << "Aluno Removido" << endl;
        }

        static int get_quantidade_de_alunos();

        void exibirInformacoes() {
            cout << nome << endl;
            cout << matricula << endl;
            cout << notaFinal << endl;
        }
};

int Aluno::quantidadeDeAlunos = 0;
int Aluno::get_quantidade_de_alunos() {
    return quantidadeDeAlunos;
}

int main() {

    // Array de ponteiros
    Aluno** alunos = new Aluno*[100];

    alunos[0] = new Aluno("Eder", 123, 9);
    alunos[1] = new Aluno("João", 456, 6);
    alunos[2] = new Aluno("Maria", 789, 10);

    alunos[0]->exibirInformacoes();
    alunos[1]->exibirInformacoes();
    alunos[2]->exibirInformacoes();

    int alunosCriados = Aluno::get_quantidade_de_alunos();

    for (int i = 0; i < alunosCriados; i++) {
        delete alunos[i];
    }

    delete [] alunos;

    cout << Aluno::get_quantidade_de_alunos() << endl;
}