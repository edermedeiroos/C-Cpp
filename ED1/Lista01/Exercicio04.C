#include <stdio.h>
#include <string.h>

#define MAX_PILHA 100
#define true 1
#define false 0

typedef int bool;

typedef struct {
    char itens[MAX_PILHA];
    int topo;
} Pilha;

void iniciaPilha(Pilha* p) {
    p->topo = -1;
}

bool pilhaVazia(Pilha* p) {
    return p->topo == -1;
}

bool push(Pilha* p, char c) {
    if (p->topo >= MAX_PILHA - 1) {
        return false;
    }
    p->topo++;
    p->itens[p->topo] = c;
    return true;
}

bool pop(Pilha* p, char* c) {
    if (pilhaVazia(p)) {
        return false;
    }
    *c = p->itens[p->topo];
    p->topo--;
    return true;
}

bool expressaoValida(const char* str) {
    Pilha p;
    iniciaPilha(&p);
    int i = 0;
    
    while (str[i] != '\0') {
        char c = str[i];
        
        if (c == '(' || c == '[' || c == '{') {
            push(&p, c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (pilhaVazia(&p)) {
                return false;
            }
            
            char topo;
            pop(&p, &topo);
            
            if (!((topo == '(' && c == ')') || (topo == '[' && c == ']') || (topo == '{' && c == '}'))) {
                return false;
            }
        }
        i++;
    }
    
    return pilhaVazia(&p);
}

int main() {
    char expressao[MAX_PILHA];
    
    printf("Digite uma expressao matematica: ");
    fgets(expressao, MAX_PILHA, stdin);
    
    // Remove o caractere de nova linha que o fgets adiciona
    expressao[strcspn(expressao, "\n")] = 0;
    
    if (expressaoValida(expressao)) {
        printf("Resultado: A expressao e valida.\n");
    } else {
        printf("Resultado: A expressao e invalida.\n");
    }
    
    return 0;
}
