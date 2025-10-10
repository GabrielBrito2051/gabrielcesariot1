#ifndef carregador_h
#define carregador_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "circulo.h"
#include "retangulo.h"
#include "linha.h"
#include "texto.h"
#include "pilha.h"
#include "fila.h"

typedef void* Carregador;

/// @brief Cria um novo carregador
/// @return Retorna um ponteiro para o carregador
Carregador cria_carregador(int i);

/// @brief Pega o id do carregador car
/// @param car O carregador que tera seu id pego
/// @return Retorna o id do carregador
int getIcarregador(Carregador car);

/// @brief Carrega o carregador com formas do chao
/// @param c O carregador que sera carregado
/// @param f O chao
/// @param i A quantidade de formas do chao que serao inseridas no carregador
/// @return Retorna um ponteiro para o carregador carregado
Carregador load_carregador(Carregador car, Fila f, int i);

/// @brief Libera a memoria de um carregador que nao e mais necessario
/// @param c O carregador que sera liberado
void free_carregador(Carregador car);

#endif