#include <iostream>
#include <string>
using namespace std;

typedef int NOME; // Usando int como um ID do paciente
typedef string SINTOMA;

typedef struct {
    NOME nome;
    SINTOMA sintoma;
} REGISTRO;

typedef struct aux{
    REGISTRO reg;
    struct aux* prox;
} ELEMENTO;

typedef ELEMENTO* PONT;

typedef struct {
    PONT inicio;
    PONT fim;
    int tamanho;
} FILA;

void inicializarFila(FILA* f) {
    f->inicio = NULL;
    f->fim = NULL;
    f->tamanho = 0;
}

// Adiciona um paciente a uma fila específica
void adicionarPaciente(FILA* f, REGISTRO p) {
    PONT novoPaciente = new ELEMENTO;
    novoPaciente->reg = p;
    novoPaciente->prox = NULL;

    if (f->inicio == NULL) {
        f->inicio = novoPaciente;
    } else {
        f->fim->prox = novoPaciente;
    }

    f->fim = novoPaciente;
    f->tamanho++;
}

// Função de atendimento "inteligente" que implementa a lógica de prioridade
void atenderProximoPaciente(FILA* altaPrioridade, FILA* baixaPrioridade) {
    PONT pacienteAtendido = NULL;
    FILA* filaDeOrigem = NULL;

    cout << "\n--- Verificando filas para atendimento ---" << endl;

    if (altaPrioridade->tamanho > 0) {
        cout << "Paciente de ALTA PRIORIDADE encontrado." << endl;
        filaDeOrigem = altaPrioridade;
    } 

    else if (baixaPrioridade->tamanho > 0) {
        cout << "Fila de alta prioridade vazia. Atendendo paciente de BAIXA PRIORIDADE." << endl;
        filaDeOrigem = baixaPrioridade;
    } 

    else {
        cout << "Nao ha pacientes para atender em nenhuma fila." << endl;
        return;
    }

    pacienteAtendido = filaDeOrigem->inicio;
    filaDeOrigem->inicio = filaDeOrigem->inicio->prox;

    if (filaDeOrigem->inicio == NULL) {
        filaDeOrigem->fim = NULL;
    }
    
    filaDeOrigem->tamanho--;
    cout << "Atendendo Paciente ID: " << pacienteAtendido->reg.nome 
         << " | Sintoma: " << pacienteAtendido->reg.sintoma << endl;
    
    delete pacienteAtendido;
}

int pacientesAguardando(FILA* f) {
    return f->tamanho;
}

int main() {
    FILA filaAltaPrioridade;
    FILA filaBaixaPrioridade;

    inicializarFila(&filaAltaPrioridade);
    inicializarFila(&filaBaixaPrioridade);

    cout << "--- Chegada de Pacientes ---" << endl;
    adicionarPaciente(&filaBaixaPrioridade, {101, "Tosse Leve"});
    adicionarPaciente(&filaAltaPrioridade, {201, "Dor no Peito"});
    adicionarPaciente(&filaBaixaPrioridade, {102, "Resfriado"});
    adicionarPaciente(&filaAltaPrioridade, {202, "Fratura Exposta"});
    
    cout << "\nStatus das Filas:" << endl;
    cout << "Pacientes em Alta Prioridade : " << pacientesAguardando(&filaAltaPrioridade) << endl;
    cout << "Pacientes em Baixa Prioridade: " << pacientesAguardando(&filaBaixaPrioridade) << endl;

    for (int i=0; i<4; i++) {
        atenderProximoPaciente(&filaAltaPrioridade, &filaBaixaPrioridade);
    }

    cout << "\nStatus Final das Filas:" << endl;
    cout << "Pacientes em Alta Prioridade : " << pacientesAguardando(&filaAltaPrioridade) << endl;
    cout << "Pacientes em Baixa Prioridade: " << pacientesAguardando(&filaBaixaPrioridade) << endl;

    return 0;
}
