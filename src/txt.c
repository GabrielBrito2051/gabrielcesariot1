#include <stdio.h>
#include <stdlib.h>
#include "txt.h"
#include "formas.h"
#include "carregador.h"
#include "disparador.h"

void printLCarquivo(FILE* txt, tipoforma tipo, Forma forma,int idCarregador){
    if(tipo==tipo_circulo){
       Circulo* c = (Circulo*) forma;
        fprintf(txt, "  > Carregador %d: Carregado com [CIRCULO] id %d, (%.1f,%.1f), r=%.1f, borda= %s, preench= %s\n",
                idCarregador,
                getIcirculo(c), 
                getXcirculo(c),
                getYcirculo(c),
                getRcirculo(c),
                getCORBcirculo(c),
                getCORPcirculo(c));
    }
    else if(tipo==tipo_retangulo){
        Retangulo* r = (Retangulo*) forma;
        fprintf(txt, "  > Carregador %d: Carregado com [RETANGULO] id %d, (%.1f,%.1f), w=%.1f, h=%.1f, borda= %s, preench= %s\n",
                idCarregador,
                getIretangulo(r),
                getXretangulo(r),
                getYretangulo(r),
                getWretangulo(r),
                getHretangulo(r),
                getCORBretangulo(r),
                getCORPretangulo(r));
}
    else if(tipo==tipo_linha){
        Linha* l = (Linha*)forma;
        fprintf(txt, "  > Carregador %d: Carregado com [LINHA] id %d, (%.1f,%.1f) -> (%.1f,%.1f), cor= %s\n",
                idCarregador,
                getIlinha(l),
                getX1linha(l),
                getY1linha(l),
                getX2linha(l),
                getY2linha(l),
                getCORlinha(l));
    }
    else if(tipo==tipo_texto){
       Texto* t = (Texto*) forma;
        fprintf(txt, "  > Carregador %d: Carregado com [TEXTO] id %d, (%.1f,%.1f),borda= %s, preench= %s ancora=%c, texto=\"%s\"\n",
                idCarregador,
                getItexto(t),
                getXtexto(t),
                getYtexto(t),
                getCORBtexto(t),
                getCORPtexto(t),
                getAtexto(t),
                getTXTOtexto(t));
    }
}

void printSHFTarquivo(FILE* txt, tipoforma tipo, Forma forma, int idDisparador){
    if(tipo==tipo_circulo){
        Circulo* c = (Circulo*) forma;
        fprintf(txt, "  > Disparador %d: [CIRCULO] id %d, r=%.1f, borda= %s, preench= %s esta na mira.\n",
                idDisparador, getIcirculo(c), getRcirculo(c), getCORBcirculo(c), getCORPcirculo(c)); 
    }
    else if(tipo==tipo_retangulo){
        Retangulo* r = (Retangulo*) forma;
        fprintf(txt, "  > Disparador %d: [RETANGULO] id %d, w=%.1f, h=%.1f, borda= %s, preench= %s esta na mira.\n",
                idDisparador, getIretangulo(r), getWretangulo(r), getHretangulo(r), getCORBretangulo(r), getCORPretangulo(r));
    }
    else if(tipo==tipo_linha){
        Linha* l = (Linha*) forma;
        fprintf(txt, "  > Disparador %d: [LINHA] id %d, cor= %s esta na mira.\n",
                idDisparador, getIlinha(l), getCORlinha(l));
    }
    else if(tipo==tipo_texto){
        Texto* t = (Texto*) forma;
        fprintf(txt, "  > Disparador %d: [TEXTO] id %d, (%lf,%lf), borda= %s, preench= %s, ancora=%c esta na mira.\n",
                idDisparador, getItexto(t), getXtexto(t), getYtexto(t), getCORBtexto(t), getCORPtexto(t), getAtexto(t));
    }
}

void printDSParquivo(FILE* txt, tipoforma tipo, Forma forma,int  idDisparador){
    if(tipo==tipo_circulo){
        Circulo* c = (Circulo*) forma;
        fprintf(txt, "  > Disparador %d: DISPAROU [CIRCULO] id %d.\n",
                idDisparador, getIcirculo(c));
        fprintf(txt, " > Nova posicao: (%lf,%lf)\n",getXcirculo(c),getYcirculo(c));
    }
    else if(tipo==tipo_retangulo){
        Retangulo* r = (Retangulo*) forma;
        fprintf(txt, "  > Disparador %d: DISPAROU [RETANGULO] id %d.\n",
                idDisparador, getIretangulo(r));
                fprintf(txt," > Nova posicao: (%lf, %lf)\n",getXretangulo(r),getYretangulo(r));
    }
    else if(tipo==tipo_linha){
        Linha* l = (Linha*) forma;
        fprintf(txt, "  > Disparador %d: DISPAROU [LINHA] id %d.\n",
                idDisparador, getIlinha(l));
                fprintf(txt," > Nova posicao: (%lf, %lf)\n",getX1linha(l),getY1linha(l));
    }
    else if(tipo==tipo_texto){
        Texto* t = (Texto*) forma;
        fprintf(txt, "  > Disparador %d: DISPAROU [TEXTO] id %d.\n",
                idDisparador, getItexto(t));
                fprintf(txt," > Nova posicao: (%lf, %lf)\n",getXtexto(t),getYtexto(t));
    }
}

void printRJDarquivo(FILE* txt, tipoforma tipo, Forma forma,int idDisparador){
    if(tipo==tipo_circulo){
        Circulo* c = (Circulo*) forma;
        fprintf(txt, "  > Disparador %d: Disparou um [CIRCULO] id %d, (%.1f,%.1f), r=%.1f, borda= %s, preench= %s\n",
                idDisparador,
                getIcirculo(c), 
                getXcirculo(c),
                getYcirculo(c),
                getRcirculo(c),
                getCORBcirculo(c),
                getCORPcirculo(c));
    }
    else if(tipo==tipo_retangulo){
       Retangulo* r = (Retangulo*) forma;
        fprintf(txt, "  > Disparador %d: Disparou um [RETANGULO] id %d, (%.1f,%.1f), w=%.1f, h=%.1f, borda= %s, preench= %s\n",
                idDisparador,
                getIretangulo(r),
                getXretangulo(r),
                getYretangulo(r),
                getWretangulo(r),
                getHretangulo(r),
                getCORBretangulo(r),
                getCORPretangulo(r));
    }
    else if(tipo==tipo_linha){
       Linha* l = (Linha*)forma;
        fprintf(txt, "  > Disparador %d: Disparou um [LINHA] id %d, (%.1f,%.1f) -> (%.1f,%.1f), cor= %s\n",
                idDisparador,
                getIlinha(l),
                getX1linha(l),
                getY1linha(l),
                getX2linha(l),
                getY2linha(l),
                getCORlinha(l));
    }
    else if(tipo==tipo_texto){
        Texto* t = (Texto*) forma;
        fprintf(txt, "  > Disparador %d: Disparou um [TEXTO] id %d, (%.1f,%.1f), ancora=%c, texto=\"%s\"\n",
                idDisparador,
                getItexto(t),
                getXtexto(t),
                getYtexto(t),
                getAtexto(t),
                getTXTOtexto(t));
    }
}