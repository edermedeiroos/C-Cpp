#include <iostream>
using namespace std;

// Inicialização da Pilha
typedef int TIPOCHAVE;

typedef struct {
    TIPOCHAVE chave;
} REGISTRO; // Registro é a chave (int)

typedef struct aux { // aux - nome temporário da struct para referir-se à si mesma
    REGISTRO reg; // Registro
    struct aux* prox; // Conexão com o próximo registro
} ELEMENTO;

typedef ELEMENTO* PONT; // Ponteiro para um elemento (registro + conexão)

typedef struct {
	PONT topo;
} PILHA;

// Adicionar Elemento (push)
void empilhar(PILHA* p, REGISTRO reg) {
    PONT novoElemento = new ELEMENTO;

    novoElemento->reg = reg;
    novoElemento->prox = p->topo;
    p->topo = novoElemento;
}

int main() {
    PILHA pilha;
    pilha.topo = NULL;
    REGISTRO reg;

    for (int i=0; i < 10; i++) {
        reg.chave = i*3;
        empilhar(&pilha, reg);
        cout << pilha.topo->reg.chave << endl;
    }
}