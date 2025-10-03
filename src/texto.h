#ifndef texto_h
#define texto_h

typedef void* Texto;

/// @brief Cria um texto com os valores dos parametros especificados
/// @param i Valor do identificador do texto
/// @param x Valor da coordenada x da ancora do texto 
/// @param y Valor da coordenada y da ancora do texto
/// @param cor Valor hexadecimal da cor do texto
/// @param a Valor que indica a posicao da ancora do texto, sendo i = inicio, m= meio e f = fim
/// @param txto Array de caracteres que compoe o texto
/// @return Retorna
Texto criar_texto(int i, double x, double y, char* cor, char a, char* txto);

/// @brief Pega o valor do identificador do texto t
/// @param t O texto que tera o identificadro lido
/// @return Retorna o valor do identificador do texto
int getItexto(Texto t);

/// @brief Pega o valor da coordenada x da ancora do texto t
/// @param t O texto no qual tera a coordenada x da ancora lida
/// @return Retorna o valor da coordenada x da ancora do texto
double getXtexto(Texto t);

/// @brief Pega o valor da coordenada y da ancora do texto t
/// @param t O texto que tera a coordenada y da ancora lida
/// @return Retorna o valor da coordenada y da ancora do texto
double getYtexto(Texto t);

/// @brief Pega o valor hexadecimal da cor do texto t
/// @param t O texto que tera a cor lida
/// @return Retorna um array de caracteres com o valor hexadecimal da cor do texto
char* getCORtexto(Texto t);

/// @brief Pega o valor hexadecimal da cor complementar do texto t
/// @param t O texto que tera a cor complementar lida
/// @return Retorna um array de caracteres com o valor hexadecimal da cor complementar do texto
char* getCORCOMPLtexto(Texto t);

/// @brief Pega o valor que indica a posicao da ancora do texto
/// @param t O texto no qual tera a posicao da ancora lida
/// @return Retorna o valor que indica a posicao da ancora do texto
char getAtexto(Texto t);

/// @brief Pega o array de caracteres que compoe o texto
/// @param t O texto no qual o array de caracteres sera lido
/// @return Retorna o array de caracteres que compoe o texto
char* getTXTOtexto(Texto t);

/// @brief Pega a quantidade de caracteres contida no texto t
/// @param t O texto que tera seu tamanho lido
/// @return Retorna a quantidade de caracteres do texto
int getTAMANHOtexto(Texto t);

/// @brief Define o valor do identificador do texto t
/// @param t O texto que tera seu identificador definido
/// @param i O valor do identificadro do texto
void setItexto(Texto t, int i);

/// @brief Define o valor da coordenada x da ancora do texto t
/// @param t O texto que tera sua coordeada x definida
/// @param x O valor da coordenada x da ancora do texto
void setXtexto(Texto t, double x);

/// @brief Define o valor da coordenada y da ancora do texto t
/// @param t O texto que tera sua coordenada y da ancora lida
/// @param y O valor da coordenada y da ancora do texto
void setYtexto(Texto t, double y);

/// @brief Define o valor hexadecimal da cor do texto t
/// @param t O texto no qual tera sua cor definida
/// @param cor O valor hexadecimal da cor do texto
void setCORtexto(Texto t, char* cor);

/// @brief Calcula e define o valor hexadecimal da cor complementar do texto t
/// @param t O texto no qual tera sua cor complementar lida
/// @param corcompl O valor da cor complementar do texto
void setCORCOMPLtexto(Texto t, char* corcompl);

/// @brief Define a posicao da ancora do texto t
/// @param t O texto no qual tera a posicao de sua ancora definida
/// @param a O caracter que informa a posicao da ancora do texto
void setAtexto(Texto t, char a);

/// @brief Define a mensagem contida no texto t
/// @param t O texto que tera sua mensagem definida
/// @param txto O array de caracteres que compoe a mensagem
void setTXTOtexto(Texto t, char* txto);

/// @brief Calcula e retorna a area do texto t
/// @param t O texto que tera sua area calculada
/// @param tamanho A quantia de caracteres presentes no texto t
/// @return Retorna a area do texto t
double calcula_area_texto(Texto t, int tamanho);

#endif