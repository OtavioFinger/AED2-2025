//Exercício 1: Construção de uma Trie

//Enunciado: Construa uma Árvore Trie (também conhecida como árvore de prefixos) inserindo, 
//na ordem, as seguintes palavras: RATO, RITA, AMIGO, AMORA e ELA. 

//Desenhe o estado final da Trie, indicando claramente quais nós marcam o fim de uma palavra.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    struct no *filhos[26];
    bool fim;
} NO;

typedef NO* PONT;

PONT criaNo() {
    PONT p = NULL;
    p = (PONT)malloc(sizeof(NO));
    return(p);
}

PONT inicializa() {
    return( criaNo() );
}

int mapearIndice(char c) {
    return( (int)c - (int)'a' );
}

void insere(PONT raiz, char *chave) {
    int nivel;
    int compr = strlen(chave);
    int i;

    PONT p = raiz;
    for( nivel = 0; nivel < compr; nivel++ ) {
        i = mapearIndice( chave[nivel] );
            if ( !p->filhos[i])
                p->filhos[i] = criaNo();
            p = p->filhos[i];
    }
    p->fim = true; //marca o fim de uma palavra
}
int main() {

    PONT raiz = inicializa(); //criamos nó sem memória
    char rato[] = "rato";
    char rita[] = "rita";
    char amigo[] = "amigo";
    char amora[] = "amora";
    char ela[] = "ela";

    insere( raiz, rato );
    insere( raiz, rita );
    insere( raiz, amigo );
    insere( raiz, amora );
    insere( raiz, ela );

    return 0;
}