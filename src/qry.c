#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "qry.h"
#include "ler_arquivo.h"
#include "disparador.h"
#include "carregador.h"
#include "pilha.h"
#include "fila.h"
#include "circulo.h"
#include "retangulo.h"
#include "linha.h"
#include "texto.h"

#define tamLinha 256

char*  leComandoQRY(char* nomeQry, char* nomeSvg, Fila chao, Fila listaDisp, Fila listaCar, Fila arena){
    FILE* qry = abre_arquivo_leitura(nomeQry);
    if(qry==NULL){
        printf("Erro ao abrir o arquivo qry");
        exit(1);
    }
    char* linhaQry = malloc(sizeof(char)*tamLinha);
    char comando[5];
    int  d, c, cesq, cdir, tipo;
    char lado, svg;
    double x, y, dx, dy, ix, iy;
    int n;
    while (le_linha(qry, linhaQry)!=NULL){
        sscanf(linhaQry, "%s", comando);
        if(strcmp(comando, "pd")==0){
            sscanf(linhaQry, "%*s %d %lf %lf",&d, &x, &y);
            Disparador novodisp = criar_disparador(d, x, y);
            pushFila(listaDisp, novodisp);
        }

        else if(strcmp(comando, "lc")==0){
            sscanf(linhaQry, "%*s %d %d",&c, &n);
            Carregador novocar = cria_carregador(c);
            Pilha pilhacar = getPILHAcarregador(novocar);

            for(int i=0;i<n;i++){
                if(verifica_fila_vazia(chao)==1){
                    printf( "O chao esta sem formas. O carregador %d foi carregado com apenas %d formas", c, i);
                    break;
                }
                Forma formaMovida = get_inicio_fila(chao);
                tipo = getTIPOFORMAfila(chao);
                pushPilha(pilhacar, formaMovida);
                popFila(chao);
            }
            pushFila(listaCar, novocar);
        }

        else if(strcmp(comando, "atch")==0){
            sscanf(linhaQry,"%*s %d %d %d", &d, &cesq, &cdir);

            Disparador procurado = buscar_na_fila(listaDisp, compara_disp, d);
            Carregador esquerdo_procurado = buscar_na_fila(listaCar, compara_car, cesq);
            if(esquerdo_procurado==NULL){
                esquerdo_procurado = cria_carregador(cesq);
                pushFila(listaCar, esquerdo_procurado);
            }
            Carregador direito_procurado = buscar_na_fila(listaCar, compara_car, cdir);
            if(direito_procurado==NULL){
                direito_procurado = cria_carregador(cdir);
                pushFila(listaCar, direito_procurado);
            }

            attach_carregador(procurado, esquerdo_procurado, "e");
            attach_carregador(procurado, direito_procurado, "d");
            removeFilaBuscando(listaCar, esquerdo_procurado);
            removeFilaBuscando(listaCar, direito_procurado);
        }

        else if(strcmp(comando, "shft")==0){
            sscanf(linhaQry,"%*s %d %c %d",&d, &lado, &n );
            Disparador procurado = buscar_na_fila(listaDisp, compara_disp, d);
            if(procurado==NULL){
                printf("Disparador nao encontrado");
                return;
            }
            for(int j=0;j<n;j++){
                shift(procurado, lado);
            }
        }

        else if(strcmp(comando, "dsp")==0){
            sscanf(linhaQry,"%*s %d %lf %lf %c",&d, &dx, &dy, svg);
            Disparador procurado = buscar_na_fila(listaDisp, compara_disp, d);
            Forma disparada = disparar_forma(procurado);
            if(disparada!=NULL){
                double xdisp, ydisp, novox, novoy;
                xdisp = getXdisparador(procurado);
                ydisp = getYdisparador(procurado);
                novox = xdisp + dx;
                novoy = ydisp + dy;
            }
        }

        else if(strcmp(comando, "rjd")==0){
            double xdisp, ydisp, novox, novoy;
            sscanf(linhaQry,"%*s %d %c %lf %lf %lf %lf",&d, &lado, &dx, &dy, &ix, &iy);
            Disparador procurado = buscar_na_fila(listaDisp, compara_disp, d);
            shift(procurado, lado);
            int i = 0;
            xdisp = getXdisparador(procurado);
            ydisp = getYdisparador(procurado);
            do{
                disparar_forma(procurado);
                novox = xdisp + dx+i*ix;
                novoy = ydisp +dy+i*iy;
            }while(shift(procurado, lado)!=0);

        }

        else if(strcmp(comando, "calc")==0){

        }
    }
    
}