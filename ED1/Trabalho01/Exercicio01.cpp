#include <iostream>

#define TAMANHO_INICIAL 10
#define MAX_ESTOUROS 3

using namespace std;

typedef int TIPOCHAVE;

TIPOCHAVE* estrutura;
int capacidade;
int topo1;
int topo2;
int total_estouros;

void inicializar() {
    cout << "Iniciando a estrutura com capacidade " << TAMANHO_INICIAL << endl;
    
    capacidade = TAMANHO_INICIAL;
    
    estrutura = new TIPOCHAVE[capacidade];
    
    topo1 = -1;
    topo2 = capacidade;
    
    total_estouros = 0;
}

bool redimensionar() {
    if (total_estouros >= MAX_ESTOUROS) {
        cout << "Estouro. Limite de 3 redimensionamentos atingido." << endl;
        return false;
    }

    int novaCapacidade = (int)(capacidade * 1.5);

    TIPOCHAVE* novoArray = new TIPOCHAVE[novaCapacidade];
    
    cout << "Estouro. Aumentando capacidade de " << capacidade << " para " << novaCapacidade << "." << endl;

    for (int i = 0; i <= topo1; i++) {
        novoArray[i] = estrutura[i];
    }

    int novoTopo2Temp = novaCapacidade;
    for (int i = capacidade - 1; i >= topo2; i--) {
        novoTopo2Temp--;
        novoArray[novoTopo2Temp] = estrutura[i];
    }

    delete[] estrutura;

    estrutura = novoArray;
    capacidade = novaCapacidade;
    topo2 = novoTopo2Temp;
    total_estouros++;

    return true;
}

bool inserirPilha1(TIPOCHAVE chave) {
    if (topo1 + 1 == topo2) {
        bool conseguiu = redimensionar();
        if (!conseguiu) {
            return false;
        }
    }

    topo1++;
    estrutura[topo1] = chave;
    cout << "Inserido na Pilha 1: " << chave << endl;
    return true;
}

bool inserirPilha2(TIPOCHAVE chave) {
    if (topo1 + 1 == topo2) {
        bool conseguiu = redimensionar();
        if (!conseguiu) {
            return false;
        }
    }

    topo2--;
    estrutura[topo2] = chave;
    cout << "Inserido na Pilha 2: " << chave << endl;
    return true;
}

bool removerPilha1() {
    if (topo1 == -1) {
        cout << "Pilha 1 esta vazia" << endl;
        return false;
    }

    cout << "Removido da Pilha 1: " << estrutura[topo1] << endl;
    topo1--;
    return true;
}

bool removerPilha2() {
    if (topo2 == capacidade) {
        cout << "Pilha 2 esta vazia" << endl;
        return false;
    }

    cout << "Removido da Pilha 2: " << estrutura[topo2] << endl;
    topo2++;
    return true;
}

void exibirEstado() {
    cout << "Estado Atual (Capacidade: " << capacidade << ")";
    cout << "Pilha 1 (Topo: " << topo1 << "): ";
    for (int i = 0; i <= topo1; i++) cout << estrutura[i] << " ";
    
    cout << "Pilha 2 (Topo: " << topo2 << "): ";
    for (int i = capacidade - 1; i >= topo2; i--) cout << estrutura[i] << " ";
    cout << "-------------------------------------";
}

int main() {
    inicializar();

    cout << "Enchendo o array" << endl;
    inserirPilha1(10);
    inserirPilha1(20);
    inserirPilha1(30);
    inserirPilha1(40);
    inserirPilha1(50);
    
    inserirPilha2(1);
    inserirPilha2(2);
    inserirPilha2(3);
    inserirPilha2(4);
    inserirPilha2(5);
    exibirEstado();

    cout << "Forcando o 1 Estouro" << endl;
    inserirPilha1(60);
    exibirEstado();

    cout << "Forcando o 2 Estouro" << endl;
    inserirPilha2(6);
    inserirPilha2(7);
    inserirPilha2(8);
    inserirPilha2(9);
    inserirPilha1(70);
    exibirEstado();

    cout << "Forcando o 3 Estouro" << endl;
    for(int i=0; i < 7; i++) inserirPilha1(100 + i);
    inserirPilha1(199);
    exibirEstado();

    cout << "Forcando o 4 Estouro" << endl;
    for(int i=0; i < 11; i++) inserirPilha2(500 + i);
    exibirEstado();
    
    inserirPilha1(999);
    
    cout << "Remocoes" << endl;
    removerPilha1();
    removerPilha2();
    exibirEstado();
    
    delete[] estrutura;

    return 0;
}