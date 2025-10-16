#ifndef disparador_h
#define disparador_h

#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "carregador.h"

/*
    Arquivo .h relacionado ao disparador e suas funcoes
*/

typedef void* Disparador;

/// @brief Cria e posiciona um novo disparador e o adiciona a lista de disparadores
/// @param d O id do disparador
/// @param x A coordenada x do disparador
/// @param y A coordenada y do disparador
/// @return Retorna o ponteiro para o disparador criado
Disparador criar_disparador(int d, double x, double y);

/// @brief Compara o id fornecido com o id de um disparador
/// @param d O id do disparador a ser encontrado
/// @return Retorna o ponteiro para o disparador com o id 'd'
int compara_disp(int d, Disparador DispDaLista);

/// @brief Libera a memoria de um disparador
/// @param disp O disparador que sera liberado da memoria
void free_disp(Disparador disp);

/// @brief Encaixa um carregador a um dos lados do disparador
/// @param disp O disparador que tera um carregador encaixado
/// @param c O carregador que sera encaixado ao disparador
/// @param lado O lado do disparador que tera um carregador encaixado
void attach_carregador(Disparador disp, Carregador car, char lado);

/// @brief Pressiona o botao esquerdo ou direito do disparador
/// @param disp O disparador que tera o botao apertado
/// @param lado Qual lado tera o botao apertado
void shift(Disparador disp, char lado);

/// @brief Dispara a forma que esta na posicao de disparo
/// @param disp O disparador que sera disparado
/// @return Retorna um ponteiro para a forma que foi disparada
Forma disparar_forma(Disparador disp);

/// @brief Pega o id de um disparador
/// @param disp O disparador que tera seu id pego
/// @return Retorna o id do disparador
int getIDdisparador(Disparador disp);

/// @brief Pega a coordenada x de um disparador
/// @param disp O disparador que tera sua coordenada x coletada
/// @return Retorna a coordenada x do disparador
double getXdisparador(Disparador disp);

/// @brief Pega a coordenada y de um disparador
/// @param disp O disparador que tera sua coordenada pega
/// @return Retorna o valor da coordenada y do disparador
double getYdisparador(Disparador disp);

/// @brief Identifica qual forma esta na posicao de disparo de um disparador
/// @param disp O disparador que tera sua forma na posicao de disparo pega
/// @return Retorna um ponteiro para a forma que esta na posicao de disparo
Forma getFormaNaMira(Disparador disp);

/// @brief Remove um carregador de um disparador
/// @param disp O disparador que tera o carregador desencaixado
/// @param lado O lado do disparador que tera o carregador desencaixado
/// @return Retorna um ponteiro para o carregador desencaixado
Carregador desencaixa_carregador(Disparador disp, char lado);

#endif