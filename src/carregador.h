#ifndef carregador_h
#define carregador_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"
#include "fila.h"

/*
    Arquivo .h relacionado ao carregador e suas funcoes
*/

typedef void* Carregador;

/// @brief Compara o id fornecido com o id de um carregador
/// @param c O id do carregador que sera buscado
/// @param car O carregador que tera seu id verificado
/// @return Retorna '1' se o id for o mesmo e' 0' se for diferente
int compara_car(int c, Carregador car);

/// @brief Cria um novo carregador
/// @param c O id do carregador que sera criado
/// @return Retorna um ponteiro para o carregador
Carregador cria_carregador(int c);

/// @brief Pega o id do carregador car
/// @param car O carregador que tera seu id pego
/// @return Retorna o id do carregador
int getIDcarregador(Carregador car);

/// @brief Libera a memoria de um carregador que nao e mais necessario
/// @param c O carregador que sera liberado
void free_carregador(Carregador car); 

/// @brief Pega a pilha de formas do carregador
/// @param car O carregador que tera sua pilha pega
/// @return Retorna o ponteiro para a pilha de formas do carregador
Pilha getPILHAcarregador(Carregador car);

#endif