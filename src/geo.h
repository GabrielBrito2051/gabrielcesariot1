#ifndef geo_h
#define geo_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ler_arquivo.h"

typedef void* Chao;

/*
Arquivo .h relacionado a leitura do arquivo geo
*/

/// @brief Abre o arquivo .geo no modo leitura e processa as todas as informacoes nele contidas, e assim adiciona-as em uma fila chamada chao
/// @param nomeGeo Nome do arquivo .geo que sera processado
/// @return retorna um ponteiro para a fila 'chao'
Chao leGeo(char* nomeGeo);

#endif