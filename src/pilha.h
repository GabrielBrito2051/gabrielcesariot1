#ifndef pilha_h
#define pilha_h

#include <stdio.h>
#include <stdlib.h>
#include "formas.h"

typedef void* Pilha;
typedef void* Forma;

/*
    Arquivo .h relacionado a uma estrutura de uma pilha, com funcaoes de inserir, remover e destruir
*/

/// @brief Cria uma nova pilha vazia
/// @return Retorna um ponteiro para a pilha criada
Pilha criar_pilha();

/// @brief Verifica se a pilha esta vazia
/// @param p A pilha que sera verificada
/// @return Retorna '1' se estiver vazia e '0' se posuuir ao menos 1 elemento
int verifica_pilha_vazia(Pilha p);

/// @brief Pega o tamanho da pilha
/// @param p A pilha que tera seu tamanho verificado
/// @return Retorna o tamanho da pilha
int getTAMANHOpilha(Pilha p);

/// @brief Insere um elemento na pilha p
/// @param p A pilha na qual tera um elemento inserido
void pushPilha(Pilha p, Forma forma);

/// @brief Remove um elemento da pilha p
/// @param p A pilha na qual tera um elemento removido
void popPilha(Pilha p);

/// @brief Le qual forma esta no topo da pilha
/// @param p A pilha que sera lida
/// @return Retorna um ponteiro para a forma no topo da pilha
Forma get_topo_pilha(Pilha p);

/// @brief Libera a memoria de uma pilha
/// @param p A pilha que sera liberada
void destruir_pilha(Pilha p);

#endif