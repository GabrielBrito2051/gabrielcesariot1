#ifndef retangulo_h
#define retangulo_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void* retangulo;

/// @brief Cria um novo retangulo com os valores dos parmetros
/// @param i O valor do identificador do retangulo
/// @param x O valor da coordenada x da ancora do retangulo
/// @param y O valor da coordenada y da ancora do retangulo
/// @param w O valor da largura do retangulo
/// @param h O valor da altura do retangulo
/// @param corb O valor hexadeimal da cor da borda do retangulo
/// @param corp O valor hexadecimal da cor do preenchimento do retangulo
/// @return Retorna um ponteiro para o retangulo criado
retangulo criar_retangulo(int i, double x, double y, double w, double h, char* corb, char* corp);

/// @brief Pega o valor do identificador do retangulo r
/// @param r O retangulo no qual tera seu identificador lido
/// @return Retorna o valor do identificador do retangulo r
int getIretangulo(retangulo r);

/// @brief Pega o valor da coordenada x da ancora do retangulo r
/// @param r O retangulo no qual tera sua coordenada x lida
/// @return Retorna o valor da coordenada x da ancora do retangulo r
double getXretangulo(retangulo r);

/// @brief Pega o valor da coordenada y da ancora do retangulo r
/// @param r O retangulo no qual tera sua coordenada y lida
/// @return Retorna o valor da coordenada y da ancora do retangulo r
double getYretangulo(retangulo r);

/// @brief Pega o valor da largura do retangulo r
/// @param r O retangulo que tera sua largura lida
/// @return Retorna o valor da largura dp retangulo r
double getWretangulo(retangulo r);

/// @brief Pega o valor da altura do retangulo r
/// @param r O retangulo que tera sua altura lida
/// @return Retorna o valor da altura do retangulo r
double getHretangulo(retangulo r);

/// @brief Pega o valor hexadecimal da cor da borda do retangulo r
/// @param r O retangulo que tera a cor de borda lida
/// @return Retorna um array de caracteres com o valor hexadecimal da cor de borda do retangulo r
char* getCORBretangulo(retangulo r);

/// @brief Pega o valor hexadecimal da cor do preenchimento do retangulo r
/// @param r O retangulo que tera a cor de preenchimento lida
/// @return Retorna um array de caracteres com o valor hexadecimal da cor do preenchimento do retangulo r
char* getCORPretangulo(retangulo r);

/// @brief Define o identificador do retangulo r
/// @param r O retangulo que tera seu identificador definido
/// @param i O valor do identificador do retangulo
void setIretangulo(retangulo r, int i);

/// @brief Define o valor da coordenada x da ancora do retangulo r
/// @param r O retangulo que tera sua coordenada x da ancora definida
/// @param x O valor da coordenada x da ancora do retangulo
void setXretangulo(retangulo r, double x);

/// @brief Define o valor da coordenada y da ancora do retangulo r
/// @param r O retangulo no qual tera sua coordenada y da ancora deinida
/// @param y O valor da coordenada da ancora do retangulo
void setYretangulo(retangulo r, double y);

/// @brief Define o valor da largura do retangulo r
/// @param r O retangulo no qual tera sua largura definida
/// @param w O valor da largura do retangulo
void setWretangulo(retangulo r, double w);

/// @brief DEfine o valor da altura do retangulo r
/// @param r O retangulo no qual tera sua altura definida
/// @param h O valor da altura do retangulo
void setHretangulo(retangulo r, double h);

/// @brief Define o valor da cor da borda do retangulo r
/// @param r O retangulo no qual tera sua cor de borda definida
/// @param corb O valor hexadecimal da cor de borda do retangulo
void setCORBretangulo(retangulo r, char* corb);

/// @brief Define o valor da cor do preenchimento do retangulo r
/// @param r O retangulo que tera sua cor de preenchimento definida
/// @param corp O valor da cor do preenchimento do retangulo
void setCORPretangulo(retangulo r, char* corp);

/// @brief Calcula e retorna a area do retangulo r
/// @param r O retangulo que tera a area calculada
/// @return O valor da area do retangulo r
double calcula_area_retangulo(retangulo r);

#endif