#include <iostream>
using namespace std;
#define TAMANHO_ARRAY 10

typedef int TIPOCHAVE;

typedef struct aux {
    TIPOCHAVE chave;
    aux* prox;
} NO;

typedef struct {
    NO* tabela[TAMANHO_ARRAY];
} ESTRUTURA;

void inicializar(ESTRUTURA &e) {
    for (int i = 0; i < TAMANHO_ARRAY; i++) {
        e.tabela[i] = nullptr;
    }
    cout << "Estrutura inicializada. Listas vazias." << endl;
}

void inserir(ESTRUTURA &e, TIPOCHAVE chave) {
    int indice = chave % 10;

    NO* novo = new NO;
    novo->chave = chave;
    
    NO* anterior = nullptr;
    NO* atual = e.tabela[indice];

    while (atual != nullptr && atual->chave < chave) {
        anterior = atual;
        atual = atual->prox;
    }

    if (anterior == nullptr) {
        novo->prox = e.tabela[indice];
        e.tabela[indice] = novo;
    } else {
        novo->prox = atual;
        anterior->prox = novo;
    }
}

NO* buscar(ESTRUTURA &e, TIPOCHAVE chave) {
    int indice = chave % 10;
    NO* atual = e.tabela[indice];

    while (atual != nullptr) {
        if (atual->chave == chave) {
            return atual;
        }
        
        if (atual->chave > chave) {
            return nullptr;
        }

        atual = atual->prox;
    }

    return nullptr;
}

bool excluir(ESTRUTURA &e, TIPOCHAVE chave) {
    int indice = chave % 10;

    NO* anterior = nullptr;
    NO* atual = e.tabela[indice];

    while (atual != nullptr && atual->chave < chave) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == nullptr || atual->chave != chave) {
        return false;
    }

    if (anterior == nullptr) {
        e.tabela[indice] = atual->prox;
    } else {
        anterior->prox = atual->prox;
    }

    delete atual;
    return true;
}

void destruir(ESTRUTURA &e) {
    for (int i = 0; i < TAMANHO_ARRAY; i++) {
        NO* atual = e.tabela[i];
        
        while (atual != nullptr) {
            NO* proximo = atual->prox;
            delete atual;
            atual = proximo;
        }
        e.tabela[i] = nullptr;
    }
    cout << "Estrutura destruida. Memoria liberada." << endl;
}

void exibir(ESTRUTURA &e) {
    cout << "\n--- Estado Atual da Estrutura ---" << endl;
    for (int i = 0; i < TAMANHO_ARRAY; i++) {
        cout << "Lista [" << i << "]: ";
        NO* atual = e.tabela[i];
        while (atual != nullptr) {
            cout << atual->chave << " -> ";
            atual = atual->prox;
        }
        cout << "NULL" << endl;
    }
    cout << "---------------------------------\n";
}

int main() {
    ESTRUTURA minhaTabela;

    inicializar(minhaTabela);

    cout << "\n--- Inserindo Elementos ---" << endl;
    inserir(minhaTabela, 20);
    inserir(minhaTabela, 15);
    inserir(minhaTabela, 10);
    inserir(minhaTabela, 1);
    inserir(minhaTabela, 27);
    inserir(minhaTabela, 5);
    inserir(minhaTabela, 40);
    inserir(minhaTabela, 11);

    exibir(minhaTabela);

    cout << "\n--- Buscando Elementos ---" << endl;
    if (buscar(minhaTabela, 15) != nullptr) {
        cout << "Chave 15 ENCONTRADA." << endl;
    }
    if (buscar(minhaTabela, 99) == nullptr) {
        cout << "Chave 99 NAO ENCONTRADA (correto)." << endl;
    }

    cout << "\n--- Excluindo Elementos ---" << endl;
    if (excluir(minhaTabela, 10)) {
        cout << "Chave 10 removida." << endl;
    }
    if (excluir(minhaTabela, 27)) {
        cout << "Chave 27 removida." << endl;
    }
    if (!excluir(minhaTabela, 99)) {
        cout << "Chave 99 nao foi removida (correto)." << endl;
    }
    
    exibir(minhaTabela);

    cout << "\n--- Destruindo Estrutura ---" << endl;
    destruir(minhaTabela);
    exibir(minhaTabela);

    return 0;
}
