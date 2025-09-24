#include <iostream>
#include <string>
using namespace std;

typedef int NOME;
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

bool atenderPaciente(FILA* f) {
    if (f->tamanho == 0) {
        return false;
    } else {
        PONT apagado = f->inicio;
        f->inicio = f->inicio->prox;

        cout << apagado->reg.nome << endl;
        cout << apagado->reg.sintoma << endl;

        if (f->inicio == NULL) {
            f->fim = NULL;
        }

        delete apagado;
        f->tamanho--;
        return true;
    }
}

int pacientesAguardando(FILA* f) {
    return f->tamanho;
}

int main() {

    FILA filaPacientes;
    ELEMENTO paciente;

    inicializarFila(&filaPacientes);

    for (int i=0; i<5; i++) {
        REGISTRO novoPaciente;
        novoPaciente.nome = i;
        novoPaciente.sintoma = "Tosse";

        adicionarPaciente(&filaPacientes, novoPaciente);
    }

    cout << pacientesAguardando(&filaPacientes) << endl;

    for (int i=0; i<5; i++) {
        atenderPaciente(&filaPacientes);
    }

    cout << pacientesAguardando(&filaPacientes) << endl;

}
