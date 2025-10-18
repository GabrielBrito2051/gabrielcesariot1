#ifndef formas_h
#define formas_h

#include "geo.h"

typedef enum{
    tipo_circulo,
    tipo_retangulo,
    tipo_linha,
    tipo_texto
}tipoforma;

typedef struct  pacote* Pacote;
typedef void* Forma;

/// @brief Cria um 'pacote' contendo a forma e o seu tipo
/// @return Retorna o pacote criado
Pacote criarPacote();

/// @brief Pega o tipo de uma da forma no pacote
/// @param forma A forma generica que tera seu tipo pego
/// @return Retorna o tipo da forma
tipoforma getTipoForma(Forma forma);

/// @brief Pega a forma contida no pacote
/// @param pacote O pacote que sera lido
/// @return Retorna a forma do pacote
Forma getFORMApacote(Pacote pacote);

/// @brief Obtem as coordenadas do segmento de linha para as formas linha e texto
/// @param f A forma
/// @param x1 Ponteiro para armazenar a coordenada x1 da forma
/// @param y1 Ponteiro para armazenar a coordenada y1 da forma
/// @param x2 Ponteiro para armazenar a coordenada x2 da forma
/// @param y2 Ponteiro para armazenar a coordenada y2 da forma
void getSegmentoLinha(Forma f, double* x1, double*y1, double *x2, double* y2);

/// @brief Libera memoria do pacote
/// @param pac O pacote que sera liberado
void freePACOTE(Pacote pac);

#endif