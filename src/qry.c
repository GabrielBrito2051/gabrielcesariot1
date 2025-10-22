#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "qry.h"
#include "sobreposicao.h"
#include "ler_arquivo.h"
#include "disparador.h"
#include "carregador.h"
#include "pilha.h"
#include "fila.h"
#include "formas.h"
#include "circulo.h"
#include "retangulo.h"
#include "linha.h"
#include "texto.h"
#include "txt.h"
#include "criarSvg.h"

#define tamLinha 256

void  leComandoQRY(FILE* qry,FILE* txt, FILE* svgQry, Fila chao, Fila listaDisp, Fila listaCar, Fila arena, double* total, int* nformas, Estilo ts){
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
                   fprintf(txt, "O chao esta sem formas. O carregador %d foi carregado com apenas %d formas", c, i);
                    break;
                }
                Pacote pacFormaMovida = get_inicio_fila(chao);
                Forma movida = getFORMApacote(pacFormaMovida);
                tipo = getTipoForma(pacFormaMovida);
                pushPilha(pilhacar, pacFormaMovida);
                popFila(chao);
                printLCarquivo(txt,tipo, movida, getIDcarregador(novocar));
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

            attach_carregador(procurado, esquerdo_procurado, 'e');
            attach_carregador(procurado, direito_procurado, 'd');
            removeDaFila(listaCar, esquerdo_procurado);
            removeDaFila(listaCar, direito_procurado);
        }

        else if(strcmp(comando, "shft")==0){
            sscanf(linhaQry,"%*s %d %c %d",&d, &lado, &n );
            Disparador procurado = buscar_na_fila(listaDisp, compara_disp, d);
            if(procurado==NULL){
                fprintf(txt,"Disparador nao encontrado");
                return;
            }
            for(int j=0;j<n;j++){
                shift(procurado, lado);
            }
            Pacote pac = getFormaNaMira(procurado);
            tipo = getTipoForma(pac);
            Forma forma = getFORMApacote(pac);
            printSHFTarquivo(txt, tipo, forma, getIDdisparador(procurado));
        }

        else if(strcmp(comando, "dsp")==0){
            sscanf(linhaQry,"%*s %d %lf %lf %c",&d, &dx, &dy, &svg);
            Disparador procurado = buscar_na_fila(listaDisp, compara_disp, d);
            Pacote disparado = disparar_forma(procurado);
            if(disparado!=NULL){
                double xdisp, ydisp;
                xdisp = getXdisparador(procurado);
                ydisp = getYdisparador(procurado);
                tipo = getTipoForma(disparado);
                Forma disparada = getFORMApacote(disparado);
                if(tipo==tipo_circulo){
                    setXcirculo(disparada, xdisp+dx);
                    setYcirculo(disparada, ydisp+dy);
                }

                else if(tipo==tipo_retangulo){
                    setXretangulo(disparada,xdisp+dx);
                    setYretangulo(disparada,ydisp+dy);
                }

                else if(tipo==tipo_linha){
                    double dxl, dyl;
                    dxl = getX2linha(disparada) - getX1linha(disparada);
                    dyl = getY2linha(disparada) - getY1linha(disparada);
                    setX1linha(disparada, xdisp+dx);
                    setX2linha(disparada,ydisp+dy);
                    setY1linha(disparada, xdisp + dxl+dx);
                    setY2linha(disparada, ydisp+dyl+dy); 
                }

                else if(tipo==tipo_texto){
                    setXtexto(disparada, xdisp+dx);
                    setYtexto(disparada, ydisp+dy);
                }
                printDSParquivo(txt, tipo, disparada,getIDdisparador(procurado));
                if(svg=='v'){
                    insere_dimensoes_disparo(svgQry, xdisp, ydisp, dx, dy);
                }
                pushFila(arena,disparado);
            }else{
                fprintf(txt," > Disparador %d: Nenhuma forma foi disparada\n",getIDdisparador(procurado));
            }
        }

        else if(strcmp(comando, "rjd")==0){
            double xdisp, ydisp;
            sscanf(linhaQry,"%*s %d %c %lf %lf %lf %lf",&d, &lado, &dx, &dy, &ix, &iy);
            Disparador procurado = buscar_na_fila(listaDisp, compara_disp, d);
            shift(procurado, lado);
            int i = 0;
            xdisp = getXdisparador(procurado);
            ydisp = getYdisparador(procurado);
            do{
                Pacote disparado = disparar_forma(procurado);
                Forma formadisparada = getFORMApacote(disparado);
                tipo = getTipoForma(disparado);
                if(tipo==tipo_circulo){
                    setXcirculo(formadisparada, xdisp+dx+i*ix);
                    setYcirculo(formadisparada, ydisp+dy + i*iy);
                }

                else if(tipo==tipo_retangulo){
                    setXretangulo(formadisparada,xdisp +dx + i*ix);
                    setYretangulo(formadisparada, ydisp +dy+i*iy);
                }

                else if(tipo==tipo_linha){
                    double dxl, dyl;
                    dxl = getX2linha(formadisparada) - getX1linha(formadisparada);
                    dyl = getY2linha(formadisparada) - getY1linha(formadisparada);
                    setX1linha(formadisparada, xdisp+dx+i*ix);
                    setX2linha(formadisparada,ydisp+dy+i*iy);
                    setY1linha(formadisparada, (xdisp + dxl+dx) + i*ix);
                    setY2linha(formadisparada, (ydisp+dyl+dy)+i*iy); 
                }

                else if(tipo==tipo_texto){
                    setXtexto(formadisparada,xdisp+dx+i*ix);
                    setYtexto(formadisparada,ydisp+dx+i*ix);
                }
                pushFila(arena,disparado);
                printRJDarquivo(txt, tipo, formadisparada, getIDdisparador(procurado));
                i++;
            }while(shift(procurado, lado)!=0);
        }

        else if(strcmp(comando, "calc")==0){
            double rodada = 0;
            while(getTAMANHOfila(arena)>=2){
                Pacote pacote1 = get_inicio_fila(arena);
                popFila(arena);
                Pacote pacote2 = get_inicio_fila(arena);
                popFila(arena);
                Forma forma_i = getFORMApacote(pacote1), forma_j = getFORMApacote(pacote2);
                if(verifica_sobreposicao(forma_i,forma_j)==1){  //se ocorrer sobreposciao
                    tipoforma tipo_i, tipo_j;
                    int id, jd;
                    double area_i, area_j;
                    tipo_i = getTipoForma(pacote1);
                    tipo_j = getTipoForma(pacote2);
                    area_i = calculaAreaForma(forma_i, tipo_i);
                    area_j = calculaAreaForma(forma_j,tipo_j);
                    id = getIDforma(forma_i, tipo_i);
                    jd = getIDforma(forma_j, tipo_j);
                    fprintf(txt,"SOBREPOSICAO: Houve sobreposicao entre as formas %d e %d\n",id, jd);
                    if(area_i<area_j){ //se ocorrer sobreposicao e i<j
                        rodada += area_i;
                        fprintf(txt,"RESULTADO: Forma %d esmagada. Nova pontuacao: %2lf\n",id, rodada);
                        pushFila(chao, pacote2);
                        printSVGforma(svgQry, tipo_j, forma_j, ts);
                        double xAncora = getXANCORAforma(forma_i, tipo);
                        double yAncora = getYANCORAforma(forma_i, tipo);
                        insere_asterisco(svgQry, xAncora, yAncora);
                        destruirFormaPacote(pacote1);
                    }else{ //se ocorrer sobreposicao e i>=j
                        fprintf(txt,"RESULTADO: Troca de cores e clonagem da forma %d\n",id);
                        trocaCor(pacote1,pacote2);
                        Pacote pacClone = clonarForma(forma_i, tipo_i, nformas);
                        tipoforma tipo_clone = getTipoForma(pacClone);
                        Forma clone = getFORMApacote(pacClone);
                        pushFila(chao, pacClone);
                        printSVGforma(svgQry, tipo_i, forma_i, ts);
                        printSVGforma(svgQry, tipo_j, forma_j, ts);
                        printSVGforma(svgQry, tipo_clone, clone, ts);
                    }
                }else{ // se nao ocorrer sobreposicao
                    tipoforma tipo_i = getTipoForma(pacote1), tipo_j = getTipoForma(pacote2);
                    int id = getIDforma(forma_i, tipo_i), jd = getIDforma(forma_j, tipo_j);
                    fprintf(txt,"SEM SOBREPOSICAO: Formas %d e %d voltam para o chao\n",id , jd);
                    pushFila(chao, pacote1);
                    pushFila(chao, pacote2);
                }
            }
            if(getTAMANHOfila(arena)==1){
                Pacote pac = get_inicio_fila(arena);
                popFila(arena);
                Forma sozinha = getFORMApacote(pac);
                tipoforma tipos = getTipoForma(pac);
                int ids = getIDforma(sozinha,tipos );
                fprintf(txt,"A forma %d era a ultima da arena, voltou para o chao sem ser comparada\n",ids);
                pushFila(chao, pac);
            }
            *total += rodada;
            fprintf(txt,"----------- FIM DA RODADA -----------\n");
            fprintf(txt,"Pontuacao da Rodada: %2lf\n",rodada);
            fprintf(txt,"Pontuacao Total: %2lf\n\n",*total);
        }
    }
    free(linhaQry);
}