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

/// @brief Abre o arquivo.qry no modo leitura e faz a leitura dos comandos que serao executados  nos TADs do carregador e disparador
/// @param nomeQry O nome do arquivo que sera lido
/// @param chao O chao
/// @param listaDisp A lista de disparadores
/// @param listaCar A lista de carregadores
void  leComandoQRY(char*nomeQry, char* nomeSvg, Fila chao, Fila listaDisp, Fila listaCar, Fila arena);

#endif