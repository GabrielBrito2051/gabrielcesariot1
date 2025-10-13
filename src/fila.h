#ifndef fila_h
#define fila_h

#include <stdio.h>
#include <stdlib.h>

typedef void* Fila;
typedef void* Forma;

/// @brief Cria uma nova fila vazia
/// @return Retorna um ponteiro para a fila
Fila criar_fila();

/// @brief Verifica se a fila f esta vazia
/// @param f A vila que sera verificada
/// @return Retorna '1' se a fila estiver vazia e '0' se tiver ao menos 1 elemento
int verifica_se_vazia(Fila f);

/// @brief Identifica o tamanho da fila f
/// @param f A fila que tera seu tamanho lido
/// @return Retorna o tamanho da fila
int getTAMANHOfila(Fila f);

/// @brief Insere um elemento na fila f
/// @param f A fila na qual sera inserido um elemento
/// @param forma O ponteiro para a forma que sera inserida
void pushFila(Fila f, Forma forma);

/// @brief Remove um elemento da fila f
/// @param f A fila na qual tera um elemento removido
void popFila(Fila f);

/// @brief Le o elemento no inicio da fila f
/// @param f A fila que tera o elemento lido
/// @return Retorna um ponteiro para o elemento do inicio da fila
Forma get_inicio_fila(Fila f);

#endif