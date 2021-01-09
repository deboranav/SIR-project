#include <stdio.h>
#ifndef defstructs_h
#define defstructs_h

//Definição do tipo de variável SIR, que contém todas as variáveis de entrada para a simulação
typedef struct 
      {
      	
         float bN, bT, bs0, bi0, bresult;///Valores necessários para o cáculo de b
         float km, kn, kt1, kresult; ///Valores necessários para o cáculo de k
         int tsd;///Tempo de Simulação em Dias 
         float h;///E pequeno intervalo de tempo (em horas);
         float S0, I0, R0; ///Valores iniciais

      } SIR;

#endif