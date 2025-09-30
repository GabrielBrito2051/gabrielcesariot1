#ifndef linha_h
#define linha_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef void* linha;

/// @brief Cria uma linha com os valores dos parametros especificados
/// @param i O valor do identificador da linha
/// @param x1 O valor da coordenada x do inicio da linha
/// @param y1 O valor da coordenada y do inicio da linha
/// @param x2 O valor da coordenada x do fim da linha
/// @param y2 O valor da coordenada y do fim da linha
/// @param cor O valor haxadecimal da cor da linha
/// @return Retorna um ponteiro para a linha criada
linha criar_linha(int i, double x1, double y1, double x2, double y2, char* cor);

/// @brief Pega o valor do identificador da linha l
/// @param l A linha que tera seu identificador lido
/// @return Retorna o valor do identificador da linha l
int getIlinha(linha l);

/// @brief Pega o valor da coordenada x do inicio da linha l
/// @param l A linha que tera sua coordenada x de inicio lida
/// @return Retorna o valor da coordenada x do inicio da linha l
double getX1linha(linha l);

/// @brief Pega o valor da coordenada y do inicio da linha l
/// @param l A linha que tera sua coordenada y do inicio lida
/// @return Retorna o valor da coordenada y do inicio da linha l
double getY1linha(linha l);

/// @brief Pega o valor da coordenada x do fim da linha l
/// @param l A linha que tera sua coordenada x do fim lida
/// @return Retorna o valor da coordenada x do fim da linha l
double getX2linha(linha l);

/// @brief Pega o valor da coordenada y do fim da linha l
/// @param l A linha que tera sua coordenada y do fim lida
/// @return Retorna o valor da coordenada y do fim da linha l
double getY2linha(linha l);

/// @brief Pega o valor hexadecimal da cor da linha l
/// @param l A linha que tera sua cor lida
/// @return Retorna um array de caracteres com o valor hexadecimal da cor da linha l
char* getCORlinha(linha l);

/// @brief Pega o valor hexadecimal da cor complementar da linha l
/// @param l A linha que tera sua cor lida
/// @return Retorna um array de caracteres com o valor hexadecimal da cor complementar da linha
char* getCORCOMPLlinha(linha l);

/// @brief Define o valor do identificador da linha l
/// @param l A linha que tera seu identificador definido
/// @param i O valor do identificador da linha
void setIlinha(linha l,int i);

/// @brief Define o valor da coordenada x de inicio da linha l
/// @param l A linha que tera sua coordenada x de incio definida
/// @param X1 O valor da coordenada x de inicio da linha
void setX1linha(linha l,double X1);

/// @brief Define o valor da coordenada y de inicio da linha l
/// @param l A linha que tera sua coordenada y de inicio lida
/// @param Y1 O valor da coordenada y de incio
void setY1linha(linha l, double Y1);

/// @brief Define o valor da coordenada x do fim da linha l
/// @param l A linha que tera sua coordenada x de fim lida
/// @param X2 O valor da coordenada x do fim da linha
void setX2linha(linha l, double X2);

/// @brief Define o valor da coordenada y do fim da linha l
/// @param l A linha que tera sua coordenada y de fim lida
/// @param Y2 O valor da coordenada y de fim da linha
void setY2linha(linha l, double Y2);

/// @brief Deifne o valor da cor hexadecimal da linha
/// @param l A linha que tera sua cor definida
/// @param cor O valor hexadecimal da cor da linha
void setCORlinha(linha l, char* cor);

/// @brief Calcula e define o valor hexadecimal da cor complementar da linha l
/// @param l A linha que tera sua cor lida
void setCORCOMPLlinha(linha l);

/// @brief Calcula e retorna a area da linha l
/// @param l A linha na qual tera sua area calculada
/// @param x1 O valor da coordenada x do inicio da linha l
/// @param y1 O valor da coordenada y do inicio da linha l
/// @param x2 O valor da coordenada x do fim da linha l
/// @param y2 O valor da coordenada y do fim da linha l
/// @return Retorna a area da linha
double calcula_area_linha(linha l, double x1, double y1, double x2, double y2);

#endif