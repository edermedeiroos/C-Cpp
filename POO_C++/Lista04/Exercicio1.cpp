#include <iostream>
#include <string>
using namespace std;

class Carro {
    public: 

        void exibirInformacoes() {
            cout << "Marca: " << getMarca() << endl;
            cout << "Modelo: " << getModelo() << endl;
            cout << "Ano de Fabricação: " << getAnoFabricacao() << endl;
            cout << "Ano do Modelo: " << getAnoModelo() << endl;
            cout << "Valor: " << getValor() << endl;
            cout << "Quilômetros Rodados: " << getQuilometros() << endl;
            cout << "Combustível: " << getCombustivel() << endl;
        }

        void cadastrarCarro(string marca, string modelo, int ano_fabricacao, int ano_modelo, double valor, double km, double combustivel) {
            setMarca(marca);
            setModelo(modelo);
            setAnoFabricacao(ano_fabricacao);
            setAnoModelo(ano_modelo);
            setValor(valor);
            setQuilometros(km);
            setCombustivel(combustivel);

            exibirInformacoes();
        }

        void atualizarInformacoes(string marca="", string modelo="", int ano_fabricacao=0, int ano_modelo=0, double valor=0, double km=0, double combustivel=0) {
            if (marca != "") 
                setMarca(marca);
            if (modelo != "") 
                setModelo(modelo);
            if (ano_fabricacao != 0) 
                setAnoFabricacao(ano_fabricacao);
            if (ano_modelo != 0) 
                setAnoModelo(ano_modelo);
            if (valor != 0) 
                setValor(valor);
            if (km != 0) 
                setQuilometros(km);
            if (combustivel != 0) 
                setCombustivel(combustivel);

            exibirInformacoes();
        }

        void limparInformacoes() {
            setMarca("");
            setModelo("");
            setAnoFabricacao(0);
            setAnoModelo(0);
            setValor(0);
            setQuilometros(0);
            setCombustivel(0);

            exibirInformacoes();
        }

    private:

        string marca, modelo;
        int ano_de_fabricacao, ano_do_modelo;
        double valor, quilometros_rodados, combustivel;

        // Setters
        void setMarca(string m) {
            marca = m;
        }

        void setModelo(string m) {
            modelo = m;
        }

        void setAnoFabricacao(int ano) {
            ano_de_fabricacao = ano;
        }

        void setAnoModelo(int ano) {
            ano_do_modelo = ano;
        }

        void setValor(double v) {
            valor = v;
        }

        void setQuilometros(double km) {
            quilometros_rodados = km;
        }

        void setCombustivel(double comb) {
            combustivel = comb;
        }

        // Getters
        string getMarca() {
            return marca;
        }

        string getModelo() {
            return modelo;
        }

        int getAnoFabricacao() {
            return ano_de_fabricacao;
        }

        int getAnoModelo() {
            return ano_do_modelo;
        }

        double getValor() {
            return valor;
        }

        double getQuilometros() {
            return quilometros_rodados;
        }

        double getCombustivel() {
            return combustivel;
        }
};

int main() {

    Carro carro;
    carro.cadastrarCarro("Porsche", "V8", 2015, 2016, 100000, 500, 30);
    carro.atualizarInformacoes("", "", 0, 0, 200000, 0, 0);
    carro.limparInformacoes();

    return 0;
}