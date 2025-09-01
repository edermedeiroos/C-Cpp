#include <iostream>
#include <string>
#include "Carro01.hpp"
using namespace std;

int main() {
    Carro carros[10];

    int indice_carro = 0;

    while (indice_carro < 10) {

        // MENU
        cout << "[1] Cadastrar Carro \n[2] Exibir Carro\n[3] Exibir todos os Carros\n[4] Limpar dados de um Carro\n[5] Limpar todos os cadastros\n[6] Sair" << endl;
        cout << "\n- Opção desejada: "; 
        int opcao;
        cin >> opcao;

        if (opcao == 1) { // Cadastro de Carro
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

            carros[indice_carro].cadastrarCarro(marca, modelo, ano_de_fabricacao, ano_do_modelo, valor, km, combustivel);
            cout << "\n-------------------------\n";

            indice_carro += 1;

        } else if (opcao == 2) { // Exibir Carro
            cout << "- Exibir Carro" << endl;
            cout << "Indíce do carro a ser exibido: ";
            int indice;
            cin >> indice;

            if (indice >= indice_carro) {
                cout << "*Indice indisponível*" << endl;
            } else {
                cout << "\n-------------------------\n";
                carros[indice].exibirInformacoes();
                cout << "\n-------------------------\n";
            }

        } else if (opcao == 3) { // Exibir Carros
            cout << "- Exibir todos os carros" << endl;

            for (int i = 0; i < indice_carro; i++) {
                cout << "Carro [" << i << "]:" << endl;
                cout << "\n-------------------------\n";
                carros[i].exibirInformacoes();
                cout << "\n-------------------------\n";
            }

        } else if (opcao == 4) { // Limpar Carro
            cout << "- Limpar Carro" << endl;
            cout << "Indíce do carro a ser apagado: ";
            int indice;
            cin >> indice;

            if (indice >= indice_carro) {
                cout << "*Indice indisponível*" << endl;
            } else {
                carros[indice].limparInformacoes();
                cout << "\n-------------------------\n";
            }

            indice_carro -= 1;
            
        } else if (opcao == 5) { // Limpar Carros
            cout << "- Limpar todos os carros" << endl;

            for (int i = 0; i < indice_carro; i++) {
                cout << "Carro [" << i << "]:" << endl;
                carros[i].limparInformacoes();
                cout << "\n-------------------------\n";
            }

            indice_carro = 0;
            
        } else if (opcao == 6) { // Sair
            cout << "- Encerrando Programa" << endl;
            break;
        } else {
            cout << "*Opção Inexistente*" << endl;
        }
    }
}