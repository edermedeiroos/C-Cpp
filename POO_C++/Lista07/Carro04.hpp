#include <iostream>
#include <string>
#include <random>
using namespace std;

class Carro {
    public: 

        Carro() {
            setMarca("");
            setModelo("");
            setPiloto("");
            setIdentificacao(0);
            setPotencia(0);
            setVelocidade(0);

            random_device rd;
            mt19937 gen(rd());
            uniform_real_distribution<> distrib(0.0, 1.0);

            double numeroAleatorio = distrib(gen);

            setAceleracao(numeroAleatorio);
            setDistancia(0);
        }

        ~Carro() {
            setMarca("");
            setModelo("");
            setPiloto("");
            setIdentificacao(0);
        }

        void cadastrarCarro(string marca, string modelo, string piloto, int identificacao, double potencia_motor) {
            setMarca(marca);
            setModelo(modelo);
            setPiloto(piloto);
            setIdentificacao(identificacao);
            setPotencia(potencia_motor);
        }

        void exibirInformacoes() {
            cout << "Marca: " << getMarca() << endl;
            cout << "Modelo: " << getModelo() << endl;
            cout << "Piloto: " << getPiloto() << endl;
            cout << "Identificação: " << getIdentificacao() << endl;
            cout << "Potência: " << getPotencia() << endl;
            cout << "Velocidade Final: " << getVelocidade() << endl;
            cout << "Aceleração (aleatório): " << getAceleracao() << endl;
            cout << "Posição Final: " << getDistancia() << endl;
        }

        double acelerar() {
            calculo_velocidade();
            calculo_distancia();
        };

        double getDistancia() {
            return distancia_percorrida;
        }

        static void aumenta1Carro();

    private:

        static int n_carros;

        // Atributos
        string marca, modelo, piloto;
        int identificacao;
        double potencia_motor, velocidade_atual, taxa_aceleracao, distancia_percorrida;

        // Setters
        void setMarca(string m) {
            marca = m;
        }

        void setModelo(string m) {
            modelo = m;
        }

        void setPiloto(string p) {
            piloto = p;
        }

        void setIdentificacao(int id) {
            identificacao = id;
        }

        void setPotencia(double p) {
            potencia_motor = p;
        }

        void setVelocidade(double v) {
            velocidade_atual = v;
        }

        void setAceleracao(double a) {
            taxa_aceleracao = a;
        }

        void setDistancia(double d) {
            distancia_percorrida = d;
        }

        // Getters
        string getMarca() {
            return marca;
        }

        string getModelo() {
            return modelo;
        }

        string getPiloto() {
            return piloto;
        }

        int getIdentificacao() {
            return identificacao;
        }

        double getPotencia() {
            return potencia_motor;
        }

        double getVelocidade() {
            return velocidade_atual;
        }

        double getAceleracao() {
            return taxa_aceleracao;
        }

        void calculo_velocidade() {
            this->velocidade_atual += this->taxa_aceleracao * this->potencia_motor;
        }

        void calculo_distancia() {
            this->distancia_percorrida += this->velocidade_atual;
        };
};
