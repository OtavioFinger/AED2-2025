// Crie um programa em linguagem C que implemente um Trie para recuperar as polaridades de palavras contidas no léxico de sentimento OpLexiconV3.0

// https://www.inf.pucrs.br/linatural/wordpress/recursos-e-ferramentas/oplexicon/

// Crie funções para o usuário:


    // Busca de polaridade: O usuário deve poder inserir uma palavra e o programa deve retornar a polaridade associada a ela. 
    // Caso a palavra não exista, o programa deve informar a inexistência.

    // Edição de polaridade: O usuário deve poder buscar uma palavra e alterar a sua polaridade. 
    // Essa alteração deve ser refletida na estrutura Trie em memória.

    // Salvamento de arquivo: O programa deve ter a capacidade de salvar a versão atualizada do léxico, 
    // com as modificações de polaridade realizadas, em um novo arquivo.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct no {
    struct no *filhos[256]; //todos os caracteres
    char tipoPalavra[4];
    char tipoRevisao;
    bool fim;
} No;

typedef No* NODO;

int mapeamentoIndice( char c ) {
    return( (int)c - (int)'a' );
}

NODO criaNo() {
    NODO p = NULL;
    p = (NODO)malloc(sizeof(NODO));
    return p;
}

NODO inicializaTrie() {
    return ( criaNo() );
}

void insereTrie( NODO p, char* chave) {
    int nivel;
    int tamChave = strlen(chave);
    int i;
    for( nivel = 0; nivel < tamChave; nivel++ ) {
        i = mapeamentoIndice( chave[nivel] );
        if( !p->filhos[i] ) {
            p->filhos[i] = criaNo();
            p = p->filhos[i];
        }
    }
    p->fim = true; //fim da palavra
}

bool buscaTrie( NODO p, char* chave) {
    int nivel;
    int tamChave = strlen(chave);
    int i;
    for( nivel = 0; nivel < tamChave; nivel++ ) {
        i = mapeamentoIndice( chave[nivel] );
        if ( !p->filhos[i] ) {
            return false;
        }
        p = p->filhos[i];
    }
    return true;
}

int main() {

    FILE *oplexicon;

    oplexicon = fopen( "lexico_v3.0.txt", "r+");

    //Insere tudo dentro do arquivo dentro da TRIE

    printf("Insira uma palavra para alterar sua polaridade: ");
    char linha[100];
    while( fgets(linha, sizeof(linha), oplexicon) != '\n' ){ //pega a linha para guardar
        printf("%s", linha);
    }
    fclose(oplexicon);

    printf("Digite uma palavra para alterar sua polaridade: ");

    printf("Gostaria de salvar as alterações? ");


    return 0;
}