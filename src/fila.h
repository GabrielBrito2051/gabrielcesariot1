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
int verifica_fila_vazia(Fila f);

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

/// @brief Percorre a fila e verifica se o id da forma daquele no e o que estamos procurando
/// @param f A fila na qual sera procurado o elemento
/// @param comparaElemento Ponteiro para a funcao que compara os elementos do tipo especifico
/// @param i O id da forma que queremos buscar
/// @return Retorna a forma que possui o id procurado
Forma buscar_na_fila(Fila f, int (*comparaElemento)(int i,  void* elemento),int i);

/// @brief Remove um item especifico da fila
/// @param f A fila
/// @param forma O item que sera removido
void removeDaFila(Fila f, Forma forma);

/// @brief Libera a memoria de uma fila
/// @param f A fila que sera liberada
void destruir_fila(Fila f); 

#endif