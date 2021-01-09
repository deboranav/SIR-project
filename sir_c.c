#include "sir_h.h"

///Função para calcular o modelo SIR
void sir (SIR j, float *S, float *I, float *R, float i, int t) {

	for (i; i <= j.tsd; i = i + j.h) 
    {
    	S[t] = S[t-1] - (j.h*j.bresult*S[t-1]*I[t-1]); /// Fórmula para o cálculo do número de indivíduos suscetíveis (que ainda não estão contaminados)
   
    	I[t] = I[t-1] + j.h*(j.bresult*S[t-1]*I[t-1]- j.kresult*I[t-1]); /// Fórmula para o cálculo do número de indivíduos infectados (capazes de infectar indivíduos S)
   
    	R[t] = R[t-1] + (j.h*j.kresult*I[t-1]); /// Fórmula para o cálculo do úmero de indivíduos removidos (que se recuperaram, tornaram-se imunes ou faleceram)
    	
    	t++; ///Incremento em 1 da varável para percorrer os vetores
    }
}