#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "geo.h"
#include "ler_arquivo.h"
#include "formas.h"
#include "circulo.h"
#include "retangulo.h"
#include "linha.h"
#include "texto.h"
#include "fila.h"
#include "criarSvg.h"

#define tamLinha 256
#define max_cor 8
#define max_font 64
#define max_text 1024

void leGeo(FILE* geo, FILE* svgGeo, int* nformas, Estilo ts, Fila chao){
    char* linhaGeo = malloc(sizeof(char) * tamLinha);
    int i, extra =0;
    double x, x2, y, y2, r, h, w;
    char corb[max_cor], corp[max_cor], cor[max_cor];
    char font[max_font], size[max_font], weight[max_font];
    char txto[max_text], tipo[3], a;
    while(le_linha(geo, linhaGeo)!=NULL){
        sscanf(linhaGeo, "%s",tipo);
        if(tipo[0]=='c'){
            Pacote pac = criarPacote();
            sscanf(linhaGeo, "%*s %d %lf %lf %lf %7s %7s", &i, &x, &y, &r, corb, corp);
            Circulo circulo = criar_circulo(i, x, y, r, corb, corp);
            setTipoForma(pac, tipo[0]);
            setFormaPacote(pac, circulo);
            pushFila(chao, pac);
            insere_circulo_svg(svgGeo, circulo);
        }
        else if(tipo[0]=='r'){
            Pacote pac = criarPacote(); 
            sscanf(linhaGeo, "%*s %d %lf %lf %lf %lf %7s %7s", &i, &x, &y, &w, &h, corb, corp);
            Retangulo retangulo = criar_retangulo(i, x, y, w, h, corb, corp);
            setTipoForma(pac, tipo[0]);
            setFormaPacote(pac, retangulo);
            pushFila(chao, pac);
            insere_retangulo_svg(svgGeo, retangulo);
        }
        else if(tipo[0]=='l'){
            Pacote pac = criarPacote();
            sscanf(linhaGeo, "%*c %d %lf %lf %lf %lf %7s", &i, &x, &y, &x2, &y2, cor);
            Linha linha = criar_linha(i, x, y, x2, y2, cor);
            setTipoForma(pac, tipo[0]);
            setFormaPacote(pac, linha);
            pushFila(chao, pac);
            insere_linha_svg(svgGeo, linha);
        }
        else if(tipo[0]=='t'){
            Pacote pac = criarPacote();
            sscanf(linhaGeo, "%*s %d %lf %lf %7s %7s %c %[^\n] ", &i, &x, &y, corb, corp, &a, txto);
            Texto texto = criar_texto(i, x, y, corb, corp, a, txto);
            setTipoForma(pac, tipo[0]);
            setFormaPacote(pac, texto);
            pushFila(chao, pac);
            insere_texto_svg(svgGeo, texto, ts);
        }
        else if(tipo[0]=='t' && tipo[1]== 's'){
            sscanf(linhaGeo,"%*s %255s %1s %255s", font, weight, size);
            setFAMILY(ts, font);
            setWEIGHT(ts, weight);
            setSIZE(ts, size);
        }
        if(extra==0){
            extra = i;
        }
    }

    *nformas = getTAMANHOfila(chao) + i;
    free(linhaGeo);
}