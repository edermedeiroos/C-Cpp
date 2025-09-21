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
        cout << p->topo->reg.chave << endl;
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

// Função auxiliar para definir a precedência dos operadores
int precedencia(char op) {
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0; // Para parênteses e outros caracteres
}

// Função de conversão SEM usar a biblioteca <cctype>
string infixaParaPosfixa(string expressao) {
    PILHA pilhaOperadores;
    pilhaOperadores.topo = NULL;
    
    string saida = "";

    for (char caractere : expressao) {
        if (caractere == ' ') continue;

        // MODIFICAÇÃO AQUI: Substituindo isalnum()
        // Verificação manual: checa se o caractere é uma letra (minúscula ou maiúscula) ou um número.
        if ((caractere >= 'a' && caractere <= 'z') ||
            (caractere >= 'A' && caractere <= 'Z') ||
            (caractere >= '0' && caractere <= '9')) 
        {
            saida += caractere;
            saida += ' '; 
        } 
        else if (caractere == '(') {
            REGISTRO reg;
            reg.chave = caractere;
            empilhar(&pilhaOperadores, reg);
        }
        else if (caractere == ')') {
            REGISTRO topoPilha;
            while (verTopo(&pilhaOperadores, &topoPilha) && topoPilha.chave != '(') {
                desempilhar(&pilhaOperadores, &topoPilha);
                saida += (char)topoPilha.chave;
                saida += ' ';
            }
            desempilhar(&pilhaOperadores, &topoPilha);
        }
        else { // Se for um operador
            REGISTRO topoPilha;
            while (!pilhaVazia(&pilhaOperadores) && verTopo(&pilhaOperadores, &topoPilha) && precedencia((char)topoPilha.chave) >= precedencia(caractere)) {
                desempilhar(&pilhaOperadores, &topoPilha);
                saida += (char)topoPilha.chave;
                saida += ' ';
            }
            REGISTRO regOp;
            regOp.chave = caractere;
            empilhar(&pilhaOperadores, regOp);
        }
    }

    REGISTRO regFinal;
    while (desempilhar(&pilhaOperadores, &regFinal)) {
        saida += (char)regFinal.chave;
        saida += ' ';
    }

    return saida;
}

int main() {
    string expressao1 = "a + b * c";
    cout << "Expressao Infixa : " << expressao1 << endl;
    string posfixa1 = infixaParaPosfixa(expressao1);
    cout << "Expressao Posfixa: " << posfixa1 << endl; 

    cout << "\n--------------------------\n";
    
    string expressao2 = "( a + b ) * c";
    cout << "Expressao Infixa : " << expressao2 << endl;
    string posfixa2 = infixaParaPosfixa(expressao2);
    cout << "Expressao Posfixa: " << posfixa2 << endl;

    return 0;
}
