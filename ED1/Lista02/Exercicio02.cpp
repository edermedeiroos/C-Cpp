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

void destruirPilha(PILHA* p) {
    while (p->topo != NULL) {
        PONT novoTopo = p->topo->prox;
        cout << p->topo->reg.chave << endl;
        delete p->topo;
        p->topo = novoTopo;
    }
    p->topo = NULL;
}

int main() {
    PILHA pilha;
    pilha.topo = NULL;
    REGISTRO reg;

    reg.chave = 10;
    empilhar(&pilha, reg);
    reg.chave = 20;
    empilhar(&pilha, reg);
    reg.chave = 30;
    empilhar(&pilha, reg);

    destruirPilha(&pilha);

    if (pilha.topo == NULL) cout << "Pilha apagada" << endl;
}