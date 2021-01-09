#include "configuracoes.h"

///Função para ler os dados de entrada
void configuracoess (SIR *config){

    FILE *entrada;
	entrada = fopen("entradas.txt", "r");
	///Leitura dos dados de entrada

	fscanf(entrada, "%f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %i", &config->S0, &config->I0, &config->R0, &config->h, &config->bN, &config->bT, &config->bs0, &config->bi0, &config->km, &config->kn, &config->kt1, &config->tsd);
    ///Salvando os dados na variável do tipo SIR

    fclose(entrada);
    
}