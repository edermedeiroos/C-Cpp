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
    if (!raiz || !pessoa) return nullptr;
    
    if (
        raiz->nome == pessoa->nome && \
        raiz->sobre_nome == pessoa->sobre_nome && \
        raiz->data_nascimento == pessoa->data_nascimento
    ) return raiz;

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

bool inserePessoa(string tipo_pessoa, PONT_PESSOA pessoa, PONT_PESSOA pessoa_filho) {
    if (!pessoa_filho || !pessoa) return(false);

    if (tipo_pessoa == "irmao") {
        if (!pessoa_filho->prox_irmao) {
            pessoa_filho->prox_irmao = pessoa;
        } else {
            inserePessoa("irmao", pessoa, pessoa_filho->prox_irmao);
        }

        pessoa->pai = pessoa_filho->pai;
        pessoa->mae = pessoa_filho->mae;
        return(true);
    }
    else if (tipo_pessoa == "pai" && !pessoa_filho->pai) {
        pessoa_filho->pai = pessoa;

        if (pessoa_filho->prox_irmao) {
            inserePessoa("pai", pessoa, pessoa_filho->prox_irmao);
        }

        return(true);
    }
    else if (tipo_pessoa == "mae" && !pessoa_filho->mae) {
        pessoa_filho->mae = pessoa;

        if (pessoa_filho->prox_irmao) {
            inserePessoa("mae", pessoa, pessoa_filho->prox_irmao);
        }

        return(true);
    };

    return(false);
}

void exibirIrmaos(PONT_PESSOA raiz) {
    cout << "[";
    PONT_PESSOA atual = raiz;
    while (atual) {
        cout << atual->nome;
        atual = atual->prox_irmao;
        if (atual) cout << " - ";
    }
    cout << "]";
}

void exibirArvore(PONT_PESSOA raiz);

void exibirPais(PONT_PESSOA raiz) {
    if (!raiz->pai && !raiz->mae) return;

    if (raiz->pai) {
        cout << "Linhagem Paterna de "; exibirIrmaos(raiz); cout << ": ";
        exibirArvore(raiz->pai);
    }
    if (raiz->mae) {
        cout << "Linhagem Materna de "; exibirIrmaos(raiz); cout << ": ";
        exibirArvore(raiz->mae);
    }
}

void exibirArvore(PONT_PESSOA raiz) {
    if (!raiz) return;

    exibirIrmaos(raiz);
    cout << endl;
    exibirPais(raiz);
}

int main() {
    PONT_PESSOA eu = inicializaArvore("Eder", "Medeiros", "26/12/2007");
    PONT_PESSOA irmao1 = criaPessoa("Dara", "Medeiros", "26/02/1997");
    PONT_PESSOA mae = criaPessoa("Marilda", "Silva", "02/06/1966");
    PONT_PESSOA pai = criaPessoa("Marcelino", "Medeiros", "08/05/1963");
    PONT_PESSOA tio1 = criaPessoa("Mara", "Silva", "26/02/1987");
    PONT_PESSOA tio2 = criaPessoa("Marcia", "Silva", "26/02/1964");
    PONT_PESSOA tio3 = criaPessoa("Sandra", "Medeiros", "26/02/1997");
    PONT_PESSOA tio4 = criaPessoa("Marcio", "Medeiros", "26/02/1997");
    PONT_PESSOA avo1 = criaPessoa("Nair", "Silva", "26/02/1997");
    PONT_PESSOA avo2 = criaPessoa("Antonio", "Silva", "26/02/1997");
    PONT_PESSOA avo3 = criaPessoa("Marlene", "Medeiros", "26/02/1997");
    PONT_PESSOA avo4 = criaPessoa("Marcelino", "Medeiros", "26/02/1997");

    inserePessoa("irmao", irmao1, eu);
    inserePessoa("mae", mae, eu);
    inserePessoa("pai", pai, eu);
    inserePessoa("irmao", tio1, mae);
    inserePessoa("irmao", tio2, mae);
    inserePessoa("irmao", tio3, pai);
    inserePessoa("irmao", tio4, pai);
    inserePessoa("mae", avo1, mae);
    inserePessoa("pai", avo2, mae);
    inserePessoa("mae", avo3, pai);
    inserePessoa("pai", avo4, pai);

    cout << " --- ARVORE GENEALOGICA --- " << endl << endl;
    exibirArvore(eu);
}
