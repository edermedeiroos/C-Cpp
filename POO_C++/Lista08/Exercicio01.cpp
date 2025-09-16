#include <iostream>
#include <string>
using namespace std;

class ContaBancaria {
    private:
        int numeroDaConta;
        string nomeDoTitular;
        double saldo;
        static double taxaDeJuros;
        
    public:
        // Constructor
        ContaBancaria() {
            numeroDaConta = 0000;
            nomeDoTitular = "Titular Padrão";
            saldo = 0;
        }

        void depositar(double quantia) {
            saldo += quantia;
        }

        void sacar(double quantia) {
            saldo -= quantia;
        }

        void aplicarJuros(int quantidadeDeAnos) {
            for (int i = 0; i < quantidadeDeAnos; i++) {
                saldo *= taxaDeJuros;
            }
        }

        void alterarInformacoes(int ndc, string ndt) {
            numeroDaConta = ndc;
            nomeDoTitular = ndt;
        }

        void exibirInformacoes() {
            cout << numeroDaConta << endl;
            cout << nomeDoTitular << endl;
            cout << saldo << endl;
        }
};

double ContaBancaria::taxaDeJuros = 1.3;

int main() {
    ContaBancaria contaEder;

    contaEder.exibirInformacoes();

    contaEder.alterarInformacoes(1234, "Eder Medeiros");
    contaEder.exibirInformacoes();

    contaEder.depositar(1000);
    contaEder.exibirInformacoes();

    contaEder.sacar(500);
    contaEder.exibirInformacoes();

    contaEder.aplicarJuros(2);
    contaEder.exibirInformacoes();
}