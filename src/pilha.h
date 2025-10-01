#ifndef pilha_h
#define pilha_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// @brief Cria uma nova pilha vazia
/// @return Retorna um ponteiro para a pilha criada
pilha *criar_pilha();

/// @brief Verifica se a pilha esta vazia
/// @param p A pilha que sera verificada
/// @return Retorna '1' se estiver vazia e '0' se posuuir ao menos 1 elemento
int verifica_se_vazia(pilha *p);

/// @brief Insere um elemento na pilha p
/// @param p A pilha na qual tera um elemento inserido
void push(pilha *p, void* forma);

/// @brief Remove um elemento da pilha p
/// @param p A pilha na qual tera um elemento removido
void pop(pilha *p);

/// @brief Le qual forma esta no topo da pilha
/// @param p A pilha que sera lida
/// @return Retorna um ponteiro para a forma no topo da pilha
void* get_topo_pilha(pilha *p);

#endif