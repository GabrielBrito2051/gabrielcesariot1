#ifndef circulo_h
#define circulo_h

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef void* circulo;

/// @brief Cria um circulo com os valores dos parametros
/// @param i Identificador do circulo
/// @param x Coordenada horizontal do centro circulo
/// @param y Coordenada vertical do centro circulo
/// @param r Tamanho do raio do circulo
/// @param corb Cor da borda do circulo, no padrao hexadecimal
/// @param corp Cor do preenchimento do circulo, no padra hexadecimal
/// @return Retorna um ponteiro para o circulo com os parametros especificados
circulo criar_circulo(int i, double x, double y, double r, char* corb, char* corp);

/// @brief Coleta o valor do identificador do circulo c
/// @param c O circulo que tera seu identificador lido
/// @return Retorna o identificador do circulo c
int getIcirculo(circulo c);

/// @brief Coleta o valor da coordenada x do centro do circulo c
/// @param c O circulo que tera sua coordenada x lida
/// @return Retorna o valor da coordenada x do centro do circulo c
double getXcirculo(circulo c);

/// @brief Coleta o valor da coordenada y do centro do circulo c
/// @param c O circulo que tera sua coordenada y lida
/// @return Retorna o valor da coordenada y do centro do circulo c
double getYcirculo(circulo c);

/// @brief Coleta o valor do raio do circulo c
/// @param c O circulo no qual tera o tamanho do seu raio lido
/// @return Retorna o valor do raio do circulo c
double getRcirculo(circulo c);

/// @brief Coleta o valor hexadecimal da cor da borda do circulo c
/// @param c O circulo no qual tera sua cor de borda lida
/// @return Retorna um array de caracteres com o valor hexadecimal da cor de borda do circulo c
char* getCORBcirculo(circulo c);

/// @brief Coleta o valor hexadecimal da cor do preenchimento do circulo c
/// @param c O circulo que tera sua cor de preenchimento lida
/// @return Retorna um array de caracteres com o valor hexadecimal da cor de preenchimento do circulo c
char* getCORPcirculo(circulo c);

/// @brief Define o identificador do circulo c
/// @param c O circulo no qual tera seu identificador definido
/// @param i O valor do identificador do circulo c
void setIcirculo(circulo c, int i);

/// @brief Define o valor da coordenada x do centro do circulo c
/// @param c O circulo no qual tera sua coordenada x definida
/// @param x O valor da coordenada x do centro do circulo c
void setXcirculo(circulo c, double x);

/// @brief Define o valor da coordenada y do centro do circulo c
/// @param c O circulo que tera sua coordenada y definida
/// @param y O valor da coordenada y do centro do circulo c
void setYcirculo(circulo c, double y);

/// @brief Define o valor do raio do circulo c
/// @param c O circulo que tera seu raio definido
/// @param r O valor do raio do circulo c
void setRcirculo(circulo c, double r);

/// @brief Define o valor da cor da borda do circulo c
/// @param c O circulo que tera sua cor de borda definida
/// @param corb O valor hexadecimal da cor da borda do circulo c
void setCORBcirculo(circulo c, char corb);

/// @brief Define o valor da cor do preenchimento do circulo c
/// @param c O circulo que tera sua cor de preenchimento definida
/// @param corp O valor hexadecimal da cor de preenchimento do circulo c
void setCORPcirculo(circulo c, char* corp);

/// @brief Calcula e retorna a area do circulo
/// @param c O circulo que tera sua area calculada
/// @return O valor da area do circulo c
double calcula_area_circulo(circulo c);

#endif