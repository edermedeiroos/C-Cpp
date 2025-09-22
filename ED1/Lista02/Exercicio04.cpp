#include <iostream>
#include <string>
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

// Função para adicionar elemento (push)
void empilhar(PILHA* p, REGISTRO reg) {
    PONT novoElemento = new ELEMENTO;

    novoElemento->reg = reg;
    novoElemento->prox = p->topo;
    p->topo = novoElemento;
}

// Função para destruir a pilha 
void destruirPilha(PILHA* p) {
    while (p->topo != NULL) {
        PONT novoTopo = p->topo->prox;
        delete p->topo;
        p->topo = novoTopo;
    }
    p->topo = NULL;
}

// Função para exibir pilha
void exibirPilha(PILHA* p) {
		PONT end = p->topo;
		printf("Pilha: \" ");
		
		while (end != NULL) {
			cout << end->reg.chave << endl;
			end = end->prox;
		}
		
		printf("\"\n");
}

// Função para desempilhar
bool desempilhar(PILHA* p, REGISTRO* reg) {
    if (p->topo == NULL) return false;
    
    *reg = p->topo->reg;
    PONT apagar = p->topo;
    p->topo = p->topo->prox;
    delete apagar;
    return true;
}

// Função para ver o topo
bool verTopo(PILHA* p, REGISTRO* reg) {
    if (p->topo == NULL) return false;
    
    *reg = p->topo->reg;
    return true;
}

bool pilhaVazia(PILHA* p) {
    return p->topo == NULL; 
}

int main() {
    
    PILHA pilha;
    pilha.topo = NULL;
    string expressao;
    int tamanhoExpressao;
    char operadores[4] = {'+', '-', '*', '/'};

    // Entrada de Dados
    cout << "Digite uma expressao matemática: ";
    getline(cin, expressao); 

    tamanhoExpressao = expressao.length();

    // Percorre cada caracter da expressao
    for (int i=0; i<tamanhoExpressao; i++) {
        char caractereAtual = expressao[i];

        // Pula se o caracter for um espaço branco
        if (caractereAtual == ' ') continue;

        // Verifica se o caracter é um operador
        bool verificacaoOperador = false;
        for (int j=0; j<4; j++) {
            if (caractereAtual == operadores[j]) {
                verificacaoOperador = true; 
                }
            }

        // Se for um número/letra, empilha na pilha
        if (verificacaoOperador == false) {

            REGISTRO reg;
            reg.chave = caractereAtual - '0';
            empilhar(&pilha, reg);

        } else { // Se for operador, desempilha os dois últimos registros e opera encima
            REGISTRO ultimoReg, penultimoReg;
            desempilhar(&pilha, &ultimoReg);
            desempilhar(&pilha, &penultimoReg);
            
            // Resultado da operação
            REGISTRO resultado;

            switch (caractereAtual) {
            case '+':
                resultado.chave = penultimoReg.chave + ultimoReg.chave;
                empilhar(&pilha, resultado);
                break;
            case '-':
                resultado.chave = penultimoReg.chave - ultimoReg.chave;
                empilhar(&pilha, resultado);
                break;
            case '*':
                resultado.chave = penultimoReg.chave * ultimoReg.chave;
                empilhar(&pilha, resultado);
                break;
            case '/':
                resultado.chave = penultimoReg.chave / ultimoReg.chave;
                empilhar(&pilha, resultado);
                break;
            }
        }
    }

    cout << pilha.topo->reg.chave << endl;
    destruirPilha(&pilha);

}