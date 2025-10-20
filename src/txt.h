#ifndef txt_h
#define txt_h

#include <stdio.h>
#include <stdlib.h>
#include "formas.h"

/*
    Arquivo .h relacionado a impressao do log no arquivo de texto
*/

/// @brief Imprime o log de um carregamento de carregador
/// @param txt Ponteiro para o arquivo de texto
/// @param tipo O tipo da forma
/// @param forma A forma
/// @param idCarregador O id do carregador
void printLCarquivo(FILE* txt, tipoforma tipo,Forma forma,int idCarregador);

/// @brief Imprime o log do aperto de um botao
/// @param txt Ponteiro para o arquivo de texto
/// @param tipo O tipo da forma
/// @param forma A forma
/// @param idDisparador O id do disparador
void printSHFTarquivo(FILE* txt, tipoforma tipo, Forma forma, int idDisparador);

/// @brief Imprime o log do disparo de uma forma
/// @param txt Ponteiro para o arquivo de texto
/// @param tipo O tipo da forma
/// @param forma A forma
/// @param idDisparador O id do disparador
void printDSParquivo(FILE* txt, tipoforma tipo, Forma forma,int  idDisparador);

/// @brief Imprime o log da rajada de disparos
/// @param txt Ponteiro para o arquivo de texto
/// @param tipo O tipo da forma
/// @param forma A forma
/// @param idDisparador O id do disparador
void printRJDarquivo(FILE* txt, tipoforma tipo, Forma forma,int idDisparador);

#endif