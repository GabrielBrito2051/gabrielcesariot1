#include <stdio.h>
#include <stdlib.h>
#include "geo.h"
#include "ler_arquivo.h"
#include "circulo.h"
#include "retangulo.h"
#include "linha.h"
#include "texto.h"
#include "fila.h"

#define tamLinha 256
#define max_cor 8
#define max_font 64
#define max_text 1024

Chao leGeo(char* nomeGeo){
    FILE* geo = abre_arquivo_leitura(nomeGeo);
    char* linhaGeo = malloc(sizeof(char) * tamLinha);
    Chao* chao = criar_fila();
    int i;
    double x, x2, y, y2, r, h, w;
    char corb[max_cor], corp[max_cor], cor[max_cor], corcompl[max_cor];
    char font[max_font], size[max_font], weight[max_font];
    char txto[max_text], tipo[3], a[2];
    while(le_linha(geo, linhaGeo)!=NULL){
        sscanf(linhaGeo, "%2s",tipo);
        if(tipo[0]=="c"){
            sscanf(linhaGeo, "%2s %d %lf %lf %lf %7s %7s",tipo, &i, &x, &y, &r, corb, corp);
            pushFila(chao, criar_circulo(i, x, y, r, *corb, *corp));
        }
        else if(tipo[0]=="r"){
            sscanf(linhaGeo, "%2s %d %lf %lf %lf %lf %7s %7s", tipo, &i, &x, &y, &w, &h, corb, corp);
            pushFila(chao, criar_retangulo(i, x, y, w, h, corb, corp));
        }
        else if(tipo[0]=="l"){
            sscanf(linhaGeo, "%2s %d %lf %lf %lf %lf %7s", tipo, &i, &x, &y, &x2, &y2, cor);
            pushFila(chao, criar_linha(i, x, y, x2, y2, cor));
        }
        else if(tipo[0]=="t" && tipo[1]==" "){
            sscanf(linhaGeo, "%2s %d %lf %lf %7s %7s %1s %1023 [^\n] ", tipo, &i, &x, &y, corb, corp, a, txto);
            pushFila(chao, criar_texto(i, x, y, corp, corb, a, txto));
        }
        else if(tipo[0]=="t" && tipo[1]== "s"){
            sscanf(linhaGeo,"%2s %255s %1s %255s", tipo, font, weight, size);
            setFAMILY(ts, font);
            setWEIGHT(ts, weight);
            setSIZE(ts, size);
        }
    }
}