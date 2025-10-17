#include <stdio.h>
#include <stdlib.h>
#include "formas.h"
#include "circulo.h"
#include "retangulo.h"
#include "linha.h"
#include "texto.h"

void abrirSVG(FILE** svg, char* nome){
    *svg = fopen(svg, "w");
    if(*svg == NULL){
        printf("Erro ao alocar memoria para o svg");
        exit(1);
    }
}

void startSVG(FILE* svg){
    fprintf(svg,"<svg xmlns:svg=\"http://www.w3.org/2000/svg\" xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\">\n");
}

void insere_circulo_svg(FILE* svg, Circulo c){
    fprintf(svg,"<circle id=\"%d\" style=\"fill:%s;fill-opacity:0.5;stroke:%s\" r=\"%lf\" cy=\"%lf\" cx=\"%lf\" />\n", getIcirculo(c), getCORPcirculo(c), getCORBcirculo(c), getRcirculo(c), getYCirculo(c), getXCirculo(c));
    }

void insere_retangulo_svg(FILE *svg, Retangulo r){
    fprintf(svg, "<rect id=\"%d\" style=\"fill:%s;fill-opacity:0.5;stroke:%s\" height=\"%lf\" width=\"%lf\" y=\"%lf\" x=\"%lf\" />\n", getIretangulo(r),getCORPretangulo(r), getCORBretangulo(r), getHretangulo(r), getWretangulo(r), getYretangulo(r), getXretangulo(r));
}

void insere_linha_svg(FILE* svg, Linha l){
    fprintf(svg, "<line id=\"%d\" x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" stroke=\"%s\" stroke-width=\"2\" />\n", getIlinha(l), getX1linha(l), getY1linha(l), getX2linha(l), getY2linha(l), getCORlinha(l));
}

void insere_texto_svg(FILE* svg, Texto t, Estilo ts){
    fprintf(svg, "<text id=\"%d\" style=\"font-size:%s;line-height:%s;fill:%s\" font-size=\"5\" y=\"%lf\" x=\"%lf\"> %s </text>\n", getItexto(t), getSIZE(ts), getFAMILY(ts), getYTexto(t), getXTexto(t), getTXTOtexto(t));
}

void fechasvg(FILE* svg){
    fprintf(svg,"</svg>\n");
}