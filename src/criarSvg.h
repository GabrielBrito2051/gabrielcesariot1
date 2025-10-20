#ifndef criarSvg_h
#define criarSvg_h

#include <stdio.h>
#include <stdlib.h>
#include "formas.h"
#include "circulo.h"
#include "retangulo.h"
#include "linha.h"
#include "texto.h"

typedef void* Forma;

/*
    Arquivo que gerencia a criacao do arquivo svg
*/

/// @brief Adiciona a tag inicial do arquivo svg
/// @param svg Poneitro para o arquivo svg
void startSVG(FILE* svg);

/// @brief Adiciona a tag circulo do arquivo svg
/// @param svg Ponteiro para o arquivo svg
/// @param c Forma do circulo
void insere_circulo_svg(FILE *svg, Circulo c);

/// @brief Adiciona a tag retangulo do arquivo svg
/// @param svg Ponteiro para o arquivo svg
/// @param r Forma do retangulo
void insere_retangulo_svg(FILE *svg, Retangulo r);

/// @brief Adiciona a tag linha do arquivo svg
/// @param svg Ponteiro para o arquivo svg
/// @param l Forma da linha
void insere_linha_svg(FILE* svg, void* l);

/// @brief Adiciona a tag texto do arquivo svg
/// @param svg Ponteiro para o arquivo svg
/// @param t Forma do texto
void insere_texto_svg(FILE* svg, Texto t, Estilo ts);

/// @brief Adiciona a tag das dimensoes do disparo no svg
/// @param svg Ponteiro para o aqruivo svg
/// @param xdisp Coordenada x do disparador
/// @param ydisp Coordenada y do disparador
/// @param dx Variacao da coordenada x
/// @param dy Variacao da coordenada y
void insere_dimensoes_disparo(FILE* svg, double xdisp, double ydisp, double dx, double dy);

/// @brief Adiciona a tag de um asterisco no local da forma destruida no svg
/// @param arq Ponteiro para o arquivo svg
/// @param xDestruida Coordenada x da forma destruida
/// @param yDestruida Coordenada y da forma destruida
void insere_asterisco(FILE* arq, double xDestruida, double yDestruida);

/// @brief Adiciona a tag final do arquivo svg
/// @param svg Ponteiro para o arquivo svg
void fechasvg(FILE* svg);

#endif