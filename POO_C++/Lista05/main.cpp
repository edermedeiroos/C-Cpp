#include <iostream>
#include <string>
#include "Carro.hpp"
using namespace std;

int main() {
    Carro carros[10];

    for (int i = 0; i < 10; i++) {

        // MENU
        cout << "[1] Cadastrar Carro \n[2] Exibir Carro\n[3] Exibir todos os Carros\n[4] Limpar dados de um Carro\n[5] Limpar todos os cadastros\n[6] Sair" << endl;
        cout << "\n- Opção desejada: "; 
        int opcao;
        cin >> opcao;

        if (opcao == 1) {
            cout << "- Cadastro de Carro" << endl;

            string marca, modelo;
            int ano_de_fabricacao, ano_do_modelo;
            double valor, km, combustivel;
            
            cout << "Marca do carro: ";
            cin >> marca;
            cout << "Modelo do carro: ";
            cin >> modelo;
            cout << "Ano de fabricacao do carro: ";
            cin >> ano_de_fabricacao;
            cout << "Ano do modelo do carro: ";
            cin >> ano_do_modelo;
            cout << "Valor do carro: ";
            cin >> valor;
            cout << "Quilômetros rodados do carro: ";
            cin >> km;
            cout << "Combustível do carro: ";
            cin >> combustivel;

            carros[i].cadastrarCarro(marca, modelo, ano_de_fabricacao, ano_do_modelo, valor, km, combustivel);

        } else if (opcao == 2) {
            cout << "- Exibir Carro" << endl;
            cout << "Indíce do carro a ser exibido: ";
            int indice;
            cin >> indice;

            carros[i].exibirInformacoes();

        } else if (opcao == 3) {
            cout << "- Exibir todos os carros" << endl;

            for (int i = 0; i < 10; i++) {
                carros[i].exibirInformacoes();
            }

        } else if (opcao == 4) {
            
        } else if (opcao == 5) {
            
        } else if (opcao == 6) {
            cout << "- Encerrando Programa" << endl;
            break;
        } else {
            cout << "*Opção Inexistente*" << endl;
        }
    }
}