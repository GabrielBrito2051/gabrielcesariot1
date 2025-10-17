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

/// @brief Libera memoria do pacote
/// @param pac O pacote que sera liberado
void freePACOTE(Pacote pac);

#endif