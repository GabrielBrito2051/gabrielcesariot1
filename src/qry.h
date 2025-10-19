#ifndef qry_h
#define qry_h

#include <stdio.h>
#include <stdlib.h>
#include "ler_arquivo.h"
#include "disparador.h"
#include "carregador.h"
#include "fila.h"

/*
    Arquivo relacionado a leitura e processamento do arquivo qry
*/

/// @brief Abre o arquivo qry no modo leitura e faz a leitura e execucao dos comandos, linha por linha. Tambem faz imprime o log de acoes no arquivo txt e imprime no arquivo svg
/// @param nomeQry O nome do arquivo qry
/// @param nomeTxt O nome do arquivo txt
/// @param nomeSvg O nome do arquivo svg
/// @param chao O chao
/// @param listaDisp A lista de disparadores
/// @param listaCar A lista de carregadores
/// @param arena A arena
/// @param total Ponteiro para a variavel que guarda a pontuacao total do jogo
void  leComandoQRY(char*nomeQry,char* nomeTxt, char* nomeSvg, Fila chao, Fila listaDisp, Fila listaCar, Fila arena, double* total, int* nformas);

#endif