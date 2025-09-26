// Exercício 2: Busca por Palavras e Prefixos

//         Enunciado: Dada a Trie construída no Exercício 1, execute as seguintes operações de busca e determine o resultado (true se a palavra completa existe, false caso contrário). Em seguida, execute uma busca por prefixo e liste todas as palavras que começam com "AM".
        
//         Operações de Busca de Palavra Completa:
        
//             search("RITA")
//             search("RATO")
//             search("AMOR")
//             search("ELA")
//             search("RIT")
        
//         Operação de Busca por Prefixo:
        
//             keysWithPrefix("AM")

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

bool search( PONT raiz, char *chave ) {
    int nivel;
    int compr = strlen(chave);
    int i;

    PONT p = raiz;
    for( int nivel = 0; nivel < compr; nivel++ ) {
        i = mapearIndice( chave[nivel] );
        if ( !p->filhos[i] ) { //significa que aquele nodo do vet de pont tá apontando pra nada
            printf("Tá na árvore? Não!\n");
            return false;
        } 
        p = p->filhos[i];
    }
    printf("Tá na árvore? Sim!\n");
    return true;
}

void keysWithPrefix( PONT p, char *prefixo ) {
    int tamSufixo = strlen(prefixo);
    int nivel;
    int i;

    for( nivel = 0; nivel < tamSufixo; nivel++ ) {
        i = mapearIndice( prefixo[nivel] );
        if ( !p->filhos[i] ) {
            printf("Tem palavra com esse prefixo '%s' não\n", prefixo);
            return;
        }
        p = p->filhos[i];
    }
    //Se achou a palavra, usa a função para IMPRIMIR 

} 

int main() {

    PONT raiz = inicializa(); //criamos nó sem memória
    char rato[] = "rato";
    char rita[] = "rita";
    char amigo[] = "amigo";
    char amora[] = "amora";
    char ela[] = "ela";
    char ulisses[] = "ulisses";

    insere( raiz, rato );
    insere( raiz, rita );
    insere( raiz, amigo );
    insere( raiz, amora );
    insere( raiz, ela );

    search( raiz, rato );
    search( raiz, ulisses );
    search( raiz, rita );
    search( raiz, amigo );
    search( raiz, amora );
    search( raiz, ela );

    keysWithPrefix( raiz ,"AM" );

    return 0;
}