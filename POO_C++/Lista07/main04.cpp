#include <iostream>
#include <string>
#include "Carro04.hpp"
using namespace std;

int Carro::n_carros = 0;

void Carro::aumenta1Carro() {
    Carro::n_carros += 1;
}

int main() {

    int opcao;
    cout << "- Quantos carros competiram ? ";
    cin >> opcao;

    Carro* carros = new Carro[opcao];
    double* posicoes = new double[opcao];

    for (int i=0; i < opcao; i++) {
        carros[i] = Carro();
        Carro::aumenta1Carro();

        posicoes[i] = 0;

        string marca, modelo, piloto;
        int identificacao;
        double potencia_motor;

        cout << "\n----- Cadastro do Carro " << i+1 << " -----\n" << endl;
        cout << "- Marca do carro [" << i+1 << "]: ";
        cin >> marca;
        cout << "- Modelo do carro [" << i+1 << "]: ";
        cin >> modelo;
        cout << "- Piloto do carro [" << i+1 << "]: ";
        cin >> piloto;
        cout << "- Identificação do carro [" << i+1 << "]: ";
        cin >> identificacao;
        cout << "- Potência Motor do carro [" << i+1 << "]: ";
        cin >> potencia_motor;

        carros[i].cadastrarCarro(marca, modelo, piloto, identificacao, potencia_motor);
    }

    // Duracao da corrida
    int duracao;
    duracao = 0;

    // Condição: um dos carros ultrapassar 1000 metros
    while (true) {

        for (int i=0; i < opcao; i++) {
            if (posicoes[i] >= 1000) {
                cout << "\n- O ganhador da corrida foi: Carro" << i << "!" << endl << "- Duração da corrida: " << duracao << " segundos." << endl;
                cout << "- Informações do carro ganhador:\n" << endl;
                carros[i].exibirInformacoes();

                delete[] carros;
                delete[] posicoes;
                return 0;

            } else {
                carros[i].acelerar();
                posicoes[i] = carros[i].getDistancia();
            }
        }
        duracao += 1;
    }
    return 0;
}
