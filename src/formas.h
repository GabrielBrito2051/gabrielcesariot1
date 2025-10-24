#ifndef formas_h
#define formas_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "geo.h"
#include "criarSvg.h"

typedef enum{
    tipo_circulo,
    tipo_retangulo,
    tipo_linha,
    tipo_texto
}tipoforma;

typedef struct  pacote* Pacote;
typedef void* Forma;

/*
    Arquivo .h relacionado as formas genericas, com funcoes de get, set, calcular area, clonar e trocar cor, destruir e printar em arquivos
*/

/// @brief Cria um 'pacote' contendo a forma e o seu tipo
/// @return Retorna o pacote criado
Pacote criarPacote();

/// @brief Pega o tipo de uma da forma no pacote
/// @param Pacote O pacote que tera seu tipo pego
/// @return Retorna o tipo da forma
tipoforma getTipoForma(Pacote pac);

/// @brief Pega a forma contida no pacote
/// @param pacote O pacote que sera lido
/// @return Retorna a forma do pacote
Forma getFORMApacote(Pacote pacote);

/// @brief Obtem as coordenadas do segmento de linha para as formas linha e texto
/// @param f O pacote da forma
/// @param x1 Ponteiro para armazenar a coordenada x1 da forma
/// @param y1 Ponteiro para armazenar a coordenada y1 da forma
/// @param x2 Ponteiro para armazenar a coordenada x2 da forma
/// @param y2 Ponteiro para armazenar a coordenada y2 da forma
void getSegmentoLinha(Pacote f, double* x1, double*y1, double *x2, double* y2);

/// @brief Pega o id de uma forma de acordo com seu tipo
/// @param f A forma
/// @param tipo Seu tipo
/// @return Retorna o id da forma
int getIDforma(Forma f, tipoforma tipo);

/// @brief Define o tipo da forma dentro do pacote pac
/// @param pac O pacote da forma
/// @param tipo O tipo da forma
void setTipoForma(Pacote p, char tipo);

/// @brief Insere um forma dentro de um pacote
/// @param pac O pacote
/// @param forma A forma que sera inserida no pacote
void setFormaPacote(Pacote pac, Forma forma);

/// @brief Calcula a area de uma forma dependendo de seu tipo
/// @param f A forma
/// @param tipo Seu tipo
/// @return Retorna o valor da area da forma
double calculaAreaForma(Forma f, tipoforma tipo);

/// @brief Faz a clonagem de um forma
/// @param f A forma que sera clonada
/// @param tipo O tipo da forma
/// @param nformas Valor passado por referencia que indica a quantidade total de formas no chao inicial
Pacote clonarForma(Forma f, tipoforma tipo, int* nformas);

/// @brief Troca as cores de duas formas
/// @param pac1 O pacote da primeira forma
/// @param pac2 O pacote da segunda forma
void trocaCor(Pacote pac1, Pacote pac2);

/// @brief Pega a coordenada x da ancora da forma
/// @param f A forma
/// @param tipo O tipo da forma
/// @return Retorna o valor da coordenada x da ancora da forma
double getXANCORAforma(Forma f, tipoforma tipo);

/// @brief Pega a coordenada y da ancora da forma
/// @param f A forma
/// @param tipo O tipo da forma
/// @return Retorna o valor da cordnada y da ancora da forma
double getYANCORAforma(Forma f, tipoforma tipo);

/// @brief Insere a tag de uma forma no arquivo svg
/// @param svg Ponteiro para o arquivo 
/// @param tipo O tipo da forma
/// @param f A forma
/// @param ts O estilo do texto
void printSVGforma(FILE* svg, tipoforma tipo, Forma f,Estilo ts);

/// @brief Libera a memoria de uma forma dentro do pacote
/// @param pac O pacote
void destruirFormaPacote(Pacote pac);

/// @brief Libera memoria do pacote
/// @param pac O pacote que sera liberado
void freePacote(Pacote pac);

#endif