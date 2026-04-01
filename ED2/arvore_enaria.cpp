#include <iostream>
#include <string>
using namespace std;

typedef struct PESSOA {
    string nome;
    string sobre_nome;
    string data_nascimento;
    struct PESSOA *pai;
    struct PESSOA *mae;
    struct PESSOA *prox_irmao;
} PESSOA;

typedef PESSOA* PONT_PESSOA;

PONT_PESSOA criaPessoa(string n, string sn, string dn){
    PONT_PESSOA nova_pessoa = new PESSOA;
    nova_pessoa->nome = n;
    nova_pessoa->sobre_nome = sn;
    nova_pessoa->data_nascimento = dn;
    nova_pessoa->pai = nullptr;
    nova_pessoa->mae = nullptr;
    nova_pessoa->prox_irmao = nullptr;
    return(nova_pessoa);
}

PONT_PESSOA inicializaArvore(string n, string sn, string dn) {
    return(criaPessoa(n, sn, dn));
}

PONT_PESSOA buscaPessoa(PONT_PESSOA pessoa, PONT_PESSOA raiz){
    if (raiz == nullptr) return nullptr;
    string pessoa_n = pessoa->nome;
    string pessoa_sn = pessoa->sobre_nome;
    string pessoa_dn = pessoa->data_nascimento;
    if (raiz->nome == pessoa_n && raiz->sobre_nome == pessoa_sn && raiz->data_nascimento == pessoa_dn) return raiz;

    PONT_PESSOA irmao = raiz->prox_irmao;
    PONT_PESSOA resp_irmao = buscaPessoa(pessoa, irmao);
    if (resp_irmao) return(resp_irmao);

    PONT_PESSOA pai = raiz->pai;
    PONT_PESSOA resp_pai = buscaPessoa(pessoa, pai);
    if (resp_pai) return(resp_pai);

    PONT_PESSOA mae = raiz->mae;
    PONT_PESSOA resp_mae = buscaPessoa(pessoa, mae);
    if (resp_mae) return(resp_mae);

    return(nullptr);
}

bool inserePessoa(string tipo_pessoa, PONT_PESSOA raiz, PONT_PESSOA pessoa, PONT_PESSOA pessoa_filho) {
    PONT_PESSOA filho = buscaPessoa(pessoa_filho, raiz);
    if (!filho) return(false);

    string pessoa_n = pessoa->nome;
    string pessoa_sn = pessoa->sobre_nome;
    string pessoa_dn = pessoa->data_nascimento;

    if (tipo_pessoa == "irmao") {
        if (!filho->prox_irmao) {
            filho->prox_irmao = pessoa;
        } else {
            PONT_PESSOA atual = filho->prox_irmao;
            while (atual->prox_irmao) {
                atual = atual->prox_irmao;
            }
            atual->prox_irmao = pessoa;
        }
        return(true);
    }
    else if (tipo_pessoa == "pai" && !filho->pai) {
        filho->pai = pessoa;
        return(true);
    }
    else if (tipo_pessoa == "mae" && !filho->mae) {
        filho->mae = pessoa;
        return(true);
    };

    return(false);
}

void exibirArvore(PONT_PESSOA raiz){
    if (raiz == nullptr) return;
    
    cout << raiz->nome << " " << raiz->sobre_nome << "(";
    PONT_PESSOA irmao = raiz->prox_irmao;
    PONT_PESSOA pai = raiz->pai;
    PONT_PESSOA mae = raiz->mae;
    
    exibirArvore(irmao);
    exibirArvore(pai);
    exibirArvore(mae);

    cout << ")";
}

int main() {
    PONT_PESSOA root = inicializaArvore("Eder", "Medeiros", "26/12/2007");
}
