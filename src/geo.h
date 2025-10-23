#ifndef geo_h
#define geo_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ler_arquivo.h"
#include "circulo.h"
#include "retangulo.h"
#include "linha.h"
#include "texto.h"
#include "fila.h"

typedef void* Chao;

/*
Arquivo .h relacionado a leitura do arquivo geo
*/

/// @brief Abre o arquivo .geo no modo leitura e processa as todas as informacoes nele contidas, e assim adiciona-as em uma fila chamada chao
/// @param nomeGeo Nome do arquivo .geo que sera processado
/// @param nomeSvg Nome do arquivo svg onde serao printadas as formas do chao
/// @param nformas Valor passado por referencia que guarda a quantidade total de formas no chao inicial
/// @param ts O estilo do texto
/// @return retorna um ponteiro para a fila 'chao'
void leGeo(FILE* geo, FILE* svgGeo, int* nformas, Estilo ts, Fila chao);

#endif