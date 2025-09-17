#include <iostream>
#include <string>
using namespace std;

class Funcionario {

    private:
        string nome, cargo;
        double salario;
        static int quantidadeDeFuncionarios;
        static double folhaTotal;

    public:

        static void soma_todos_salarios(double sal); 
        static int get_quant_de_funcionarios();
        static double get_folha_total();

        Funcionario(string n, string c, double s) {
            cout << "Criando Funcionário" << endl;

            this->nome = n;
            this->cargo = c;
            this->salario = s;

            quantidadeDeFuncionarios++;

            soma_todos_salarios(this->salario);
        }

        ~Funcionario()  {
            cout << "Destruindo Funcionário" << endl;

            quantidadeDeFuncionarios--;

            soma_todos_salarios(this->salario*-1);
        }

        void exibirInfo() {
            cout << this-> nome << endl;
            cout << this-> cargo << endl;
            cout << this-> salario << endl;
        }

};

int Funcionario::quantidadeDeFuncionarios = 0;
double Funcionario::folhaTotal = 0.0;

void Funcionario::soma_todos_salarios(double sal){
    Funcionario::folhaTotal += sal;
}

int Funcionario::get_quant_de_funcionarios() {
    return quantidadeDeFuncionarios;
}

double Funcionario::get_folha_total() {
    return folhaTotal;
}

int main() {

    Funcionario* equipe[100];

    equipe[0] = new Funcionario("Eder", "Analista de Dados", 10000);
    cout << Funcionario::get_folha_total() << endl;;

    equipe[1] = new Funcionario("Eder2", "Analista de Dados2", 10000);
    cout << Funcionario::get_folha_total() << endl;;

    equipe[2] = new Funcionario("Eder3", "Analista de Dados3", 10000);
    cout << Funcionario::get_folha_total() << endl;;

    equipe[0]->exibirInfo();
    equipe[1]->exibirInfo();
    equipe[2]->exibirInfo();

    int quantDeFuncionarios = Funcionario::get_quant_de_funcionarios();

    for (int i=0; i<quantDeFuncionarios; i++) {
        delete equipe[i];
        cout << Funcionario::get_folha_total() << endl;;
    }

}