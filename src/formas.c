#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "formas.h"

typedef struct pacote{
    Forma forma;
    tipoforma tipo;
};

Pacote criarPacote(){
    Pacote pac = malloc(sizeof(Pacote));
    return pac;
}

tipoforma getTipoForma(Pacote pac){
   return  pac->tipo;
}

Forma getFORMApacote(Pacote pac){
    return pac->forma;
}

void getSegmentoLinha(Forma f, double* x1, double*y1, double *x2, double* y2){
    tipoforma tipo = getTipoForma(f);
    if(tipo == tipo_linha){
        *x1 = getX1linha(f);
        *y1 = getY1linha(f);
        *x2 = getX2linha(f);
        *y2 = getY2linha(f);
    }else{
        double xt = getXtexto(f);
        double yt = getYtexto(f);
        char ancora = getAtexto(f);
        const char* conteudo = getTXTOtexto(f);
        int tamanho = strlen(conteudo);

        *y1 = yt;
        *y2 = yt;

        if(ancora == 'i'){
            *x1 = xt;
            *x2 = xt + 10.0 * tamanho;
        }
        
        else if(ancora == 'f'){
            *x1 = xt - 10.0 * tamanho;
            *x2 = xt;
        }

        else if(ancora == 'm'){
            *x1 = xt - 5*tamanho;
            *x2 = xt + 5*tamanho;
        }
    }
}

int getIDforma(Forma f, tipoforma tipo){
    if(tipo==tipo_circulo){
        return getIcirculo(f);
    }
    else if(tipo==tipo_retangulo){
        return getIretangulo(f);
    }
    else if(tipo==tipo_linha){
        return getIlinha(f);
    }
    else if(tipo==tipo_texto){
        return getItexto(f);
    }
}

void setTipoForma(Pacote p, char tipo){
    if(tipo=='c'){
        p->tipo = tipo_circulo;
    }
    else if(tipo=='r'){
        p->tipo = tipo_retangulo;
    }
    else if(tipo=='l'){
        p->tipo = tipo_linha;
    }
    else if(tipo=='t'){
        p->tipo = tipo_texto;
    }
}

void setFormaPacote(Pacote pac, Forma forma){
    pac->forma = forma;
}

double calculaAreaForma(Forma f, tipoforma tipo){
    if(tipo==tipo_circulo){
        return calcula_area_circulo(f);
    }
    else if(tipo==tipo_retangulo){
       return  calcula_area_retangulo(f);
    }
    else if(tipo==tipo_linha){
       return  calcula_area_linha(f);
    }
    else if(tipo==tipo_texto){
       return  calcula_area_texto(f);
    }
}

Pacote clonarForma(Forma f, tipoforma tipo, int* nformas){
    int id = *nformas +1;
    double x, y;
    char* corb, *corp;
    Forma clone;
    if(tipo==tipo_circulo){
        x = getXcirculo(f);
        y = getYcirculo(f);
        double r = getRcirculo(f);
        corb = getCORBcirculo(f);
        corp = getCORPcirculo(f);
        clone = criar_circulo(id, x, y, r, corb, corp);
    }
    else if(tipo==tipo_retangulo){
        x = getXretangulo(f);
        y = getYretangulo(f);
        double w = getWretangulo(f), h = getHretangulo(f);
        corb = getCORBretangulo(f);
        corp = getCORPretangulo(f);
        clone = criar_retangulo(id, x, y, w, h, corb, corp);
    }
    else if(tipo==tipo_linha){
        x = getX1linha(f);
        y = getY1linha(f);
        double x2 = getX2linha(f), y2 = getY2linha(f);
        corb = getCORlinha(f);
        clone = criar_linha(id, x, y, x2, y2, corb);
    }
    else if(tipo==tipo_texto){
        x = getXtexto(f);
        y = getYtexto(f);
        corb = getCORtexto(f);
        corp = getCORPtexto(f);
        char a = getAtexto(f);
        char* txto = getTXTOtexto(f);
        clone = criar_texto(id, x, y, corb, corp, a, txto);
    }
    *nformas += 1;
    Pacote pacote = criarPacote();
    setTipoForma(pacote, tipo);
    setFormaPacote(pacote, clone);
    return pacote;
}

void trocaCor(Forma f1, Forma f2){
    int t1, t2;
    char *corb1, *corp1, *corb2, *corp2;
    t1 = getTipoForma(f1);
    t2 = getTipoForma(f2);
    if(t1==tipo_circulo){
        corb1 = getCORBcirculo(f1);
        corp1 = getCORPcirculo(f1);
    }
    else if(t1==tipo_retangulo){
        corb1 = getCORBretangulo(f1);
        corp1 = getCORPretangulo(f1);
    }
    else if(t1==tipo_linha){
        corb1 = getCORlinha(f1);
        corp1 = getCORCOMPLlinha(f1);
    }
    else if(t1==tipo_linha){
        corb1 = getCORtexto(f1);
        corp1 = getCORPtexto(f1);
    }

    if(t2==tipo_circulo){
        corb2 = getCORBcirculo(f2);
        corp2 = getCORPcirculo(f2);
    }
    else if(t2==tipo_retangulo){
        corb2 = getCORBretangulo(f2);
        corp2 = getCORPretangulo(f2);
    }
    else if(t2==tipo_linha){
        corb2 = getCORlinha(f2);
        corp2 = getCORCOMPLlinha(f2);
    }
    else if(t2==tipo_linha){
        corb2 = getCORtexto(f2);
        corp2 = getCORPtexto(f2);
    }
    char* extra;
    extra = corb1;
    corb1 = corb2;
    corb2 = extra;

    extra = corp1;
    corp1 = corp2;
    corp2 = extra;
}

void freePACOTE(Pacote pac){
    free(pac);
}