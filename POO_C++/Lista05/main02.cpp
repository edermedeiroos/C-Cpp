#include <iostream>
#include <string>
#include "Carro02.hpp"
using namespace std;

int main() {
    Carro carro1;
    Carro carro2;

    // Criação do gerador aleatório
    random_device rd;
    mt19937 gen(rd());

    string marca, modelo, piloto;
    int identificacao;
    double potencia_motor;

    // Dados do Carro 1
    cout << "\n----- Cadastro do Carro 01 -----\n" << endl;
    cout << "- Marca do carro [1]: ";
    cin >> marca;
    cout << "- Modelo do carro [1]: ";
    cin >> modelo;
    cout << "- Piloto do carro [1]: ";
    cin >> piloto;
    cout << "- Identificação do carro [1]: ";
    cin >> identificacao;
    cout << "- Potência Motor do carro [1]: ";
    cin >> potencia_motor;

    // Cadastro do Carro 1
    carro1.cadastrarCarro(marca, modelo, piloto, identificacao, potencia_motor, gen);

    // Dados do Carro 2
    cout << "\n----- Cadastro do Carro 02 -----\n" << endl;
    cout << "- Marca do carro [2]: ";
    cin >> marca;
    cout << "- Modelo do carro [2]: ";
    cin >> modelo;
    cout << "- Piloto do carro [2]: ";
    cin >> piloto;
    cout << "- Identificação do carro [2]: ";
    cin >> identificacao;
    cout << "- Potência Motor do carro [2]: ";
    cin >> potencia_motor;

    // Cadastro do Carro 2
    carro2.cadastrarCarro(marca, modelo, piloto, identificacao, potencia_motor, gen);

    // Posições iniciais
    double posicao_carro1, posicao_carro2;
    posicao_carro1 = 0;
    posicao_carro2 = 0;

    // Duracao da corrida
    int duracao;
    duracao = 0;

    // Condição: um dos carros ultrapassar 1000 metros
    while (posicao_carro1 < 1000 && posicao_carro2 < 1000) {

        carro1.acelerar();
        carro2.acelerar();

        posicao_carro1 = carro1.getDistancia();
        posicao_carro2 = carro2.getDistancia();

        duracao += 1;
    }

    if (posicao_carro1 > posicao_carro2) {
        cout << "\n- O ganhador da corrida foi: Carro1!" << endl << "- Duração da corrida: " << duracao << " segundos." << endl;
        cout << "- Informações do carro ganhador:\n" << endl;
        carro1.exibirInformacoes();
        
    } else if (posicao_carro2 > posicao_carro1) {
        cout << "\n- O ganhador da corrida foi: Carro2!" << endl << "- Duração da corrida: " << duracao << " segundos.\n" << endl;
        cout << "- Informações do carro ganhador:\n" << endl;
        carro2.exibirInformacoes();
    } else {
        cout << "\n- A corrida terminou em empate!" << endl;
        cout << "\n- Informações do Carro1:\n" << endl;
        carro1.exibirInformacoes();
        cout << "\n- Informações do Carro2:\n" << endl;
        carro2.exibirInformacoes();
    }

    return 0;
}
