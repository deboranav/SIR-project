#include "saida_h.h"

///Função para gerar a saída da simulação sem nenhum cenário extra
void saida (float *S, float *I, float *R, SIR g){
	float i; 
	int t;
	t = 1; 

	FILE *saida; ///vetor saida para a variável de tipo FILE que irá ser o arquivo de saída do programa
    saida = fopen("saída.csv", "w"); ///criação do arqivo saída em formato csv, com o objetivo de escrever neste
    
    ///Impressão das nomenclaturas das variáveis no arquivo
    fprintf (saida, "S(t),");
    fprintf (saida, "I(t),");
    fprintf (saida, "R(t),");
    fprintf (saida, "t\n");

    ///Impressão dos valores iniciais
    fprintf (saida, "%.2f,",S[0] );
    fprintf (saida, "%.2f,",I[0] );
    fprintf (saida, "%.2f,",R[0] );
    fprintf (saida, "0\n");

    ///Impressão dos valores calculados
    for (i = g.h; i <= g.tsd; i = i + g.h){
    	fprintf(saida, "%.2f,", S[t]);
    	fprintf(saida, "%.2f,", I[t]);
    	fprintf(saida, "%.2f,", R[t]);
    	fprintf(saida, "%f\n", i);

    	t++;

    }

    fclose(saida);
}