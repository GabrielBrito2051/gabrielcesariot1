#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sobreposicao.h"
#include "geo.h"
#include "criarSvg.h"
#include "ler_arquivo.h"
#include "qry.h"
#include "fila.h"
#include "pilha.h"
#include "disparador.h"
#include "carregador.h"

#define PATH_LEN 512
#define FILE_NAME_LEN 256

int main(int argc, char* argv[])
{
    char dirEntrada[PATH_LEN] = "";
    char dirSaida[PATH_LEN] = "";
    char nomeArquivoGeo[FILE_NAME_LEN] = "";
    char nomeArquivoQry[FILE_NAME_LEN] = "";
    char onlyQry[FILE_NAME_LEN] = "";
    int hasGeo = 0, hasSaida = 0;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-e") == 0 && i + 1 < argc) {
            strcpy(dirEntrada, argv[++i]);
        } else if (strcmp(argv[i], "-o") == 0 && i + 1 < argc) {
            strcpy(dirSaida, argv[++i]);
            hasSaida = 1;
        } else if (strcmp(argv[i], "-f") == 0 && i + 1 < argc) {
            strcpy(nomeArquivoGeo, argv[++i]);
            hasGeo = 1;
        } else if (strcmp(argv[i], "-q") == 0 && i + 1 < argc) {
            strcpy(nomeArquivoQry, argv[++i]);
            char *p = strrchr(argv[i], '/');
            strcpy(onlyQry, p ? p + 1 : argv[i]);
        } else {
            fprintf(stderr, "Parametro desconhecido ou invalido: %s\n", argv[i]);
            return EXIT_FAILURE;
        }
    }

    if (!hasGeo || !hasSaida) {
        fprintf(stderr, "Erro: parametros obrigatorios -f (geo) e -o (saida) nao fornecidos.\n");
        return EXIT_FAILURE;
    }

    char fullPathGeo[PATH_LEN + FILE_NAME_LEN];
    snprintf(fullPathGeo, sizeof(fullPathGeo), "%s/%s", dirEntrada, nomeArquivoGeo);

    char fullPathQry[PATH_LEN + FILE_NAME_LEN];
    if (strlen(nomeArquivoQry) > 0) {
        snprintf(fullPathQry, sizeof(fullPathQry), "%s/%s", dirEntrada, nomeArquivoQry);
    }

    char arquivoSaidaSvgGeo[PATH_LEN + FILE_NAME_LEN];
    snprintf(arquivoSaidaSvgGeo, sizeof(arquivoSaidaSvgGeo), "%s/%s.svg", dirSaida, nomeArquivoGeo);

    char arquivoSaidaSvgQry[PATH_LEN + FILE_NAME_LEN];
    if (strlen(nomeArquivoQry) > 0) {
        snprintf(arquivoSaidaSvgQry, sizeof(arquivoSaidaSvgQry), "%s/%s.svg", dirSaida, onlyQry);
    }

    char arquivoSaidaTxt[PATH_LEN + FILE_NAME_LEN];
    if (strlen(nomeArquivoQry) > 0) {
        snprintf(arquivoSaidaTxt, sizeof(arquivoSaidaTxt), "%s/%s.txt", dirSaida, onlyQry);
    }

    FILE* geo = NULL;
    FILE* qry = NULL;
    FILE* txt = NULL;
    FILE* svgGeo = NULL;
    FILE* svgQry = NULL;

    geo = abre_arquivo_leitura(fullPathGeo);
    if(strlen(nomeArquivoQry) > 0){
        qry = abre_arquivo_leitura(fullPathQry);
        txt = abre_arquivo_escrita(arquivoSaidaTxt);
        svgQry = abre_arquivo_escrita(arquivoSaidaSvgQry);
        startSVG(svgQry);
    }
    svgGeo = abre_arquivo_escrita(arquivoSaidaSvgGeo);
    startSVG(svgGeo);

    Fila listaDisp = criar_fila();
    Fila listaCar = criar_fila();
    Fila arena = criar_fila();
    Fila chao = criar_fila();
    int nformas = 0;
    double total = 0;
    Estilo ts = criar_estilo("sans", "n", "12");

   chao =  leGeo(geo, svgGeo, &nformas, &ts);
   fechasvg(svgGeo);

   svgQry = abre_arquivo_escrita(arquivoSaidaSvgQry);
   startSVG(svgQry);

   leComandoQRY(qry, txt, svgQry, chao, listaDisp, listaCar, arena, &total, &nformas, ts);
   fechasvg(svgQry);

   fecha_arquivo(svgGeo);
   fecha_arquivo(svgQry);
   fecha_arquivo(txt);
   fecha_arquivo(geo);
   fecha_arquivo(qry);

 return 0;
}