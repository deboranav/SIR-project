
#include "sir_h.h" ///Biblioteca para cálculo do modelo
#include "saida_h.h" ///Biblioteca para gerar saída principal
#include "configuracoes.h"///Biblioteca para ler e salvar os dados de entrada

///Função para calcular a facilidade de contágio de um indivíduo (b)
float formulab(SIR x){

	x.bresult = x.bN/(x.bT*x.bs0*x.bi0);///Cálculo de b

	return x.bresult; /// retorna o valor de b
}


///Função para calcular a probabilidade de que um indivíduo se recupere (k)
float formulak(SIR y){

	y.kresult = y.km/(y.kn*y.kt1); //Cálculo de k

	return y.kresult; /// retorna o valor de k
} 


///FUNÇÃO PRINCIPAL

int main () {

    SIR config; ///Struct para as variáveis de entrada
    float  i, TAM; /// parâmetro para o for e tamanho dos vetores 
    float *I; ///Número de indivíduos suscetíveis (que ainda não estão contaminados) a cada incremento de tempo
    float *S; ///Número de indivíduos infectados (capazes de infectar indivíduos S) a cada incremento de tempo
    float *R; ///número de indivíduos removidos (que se recuperaram, tornaram-se imunes oufaleceram) a cada incremento de tempo
    float tempo; ///Tempo de início dos cenários adicionais 
    float reserva; ///Variável para salvar o valor de config.bresult 
    int t, cenario;///Marcador de tempo e cenário escolhido pelo usuário
    
    ///Leitura dos dados de entrada
    configuracoess (&config);

    ///ATRIBUIÇÃO DOS VALORES FIXOS b E k
    
    config.bresult = formulab(config); ///Atribuição do valor calculado pela função à parte result da variável b
    
    
    config.kresult = formulak (config); ///Atribuição do valor calculado pela função à parte result da varável k
    

    /// Cálculo do tempo total em horas

    config.tsd = config.tsd*24; ///Multiplicação do tempo total em dias por 24, para descobrir quantas horas serão simuladas e facilitar o incremento de h
    TAM = config.tsd/config.h; ///Tamanho dos vetores de acordo com a qauntidade de incrementos que serão feitos
    
    /// DEFINIÇÃO DO TAMANHO DOS VETORES QUE ARMAZENARÃO OS VALORES DE S(t), I(t) E R(t), E IMPRESSÃO DOS VALORES INICIAIS NO ARQUIVO

    S = (float* )malloc(TAM * sizeof(float));
    S[0] = config.S0;///Definição do valor S0 de entrada como primeira posição do vetos dos S(t)
    
    I = (float* )malloc(TAM * sizeof(float));
    I[0] = config.I0;///Definição do valor I0 de entrada como primeira posição do vetos dos I(t)

    R = (float* )malloc(TAM * sizeof(float));
    R[0] = config.R0;///Definição do valor R0 de entrada como primeira posição do vetos dos R(t)

    ///Definição dos parâmetros para a função sir
    i = config.h;
    t = 1;

    ///CÁLCULO DO MODELO SIR PRINCIPAL
    sir(config, S, I, R, i, t);

    ///Geração de saída .csv do modelo principal
    saida(S, I, R, config);

    ///SOLICITAÇÃO DE CENÁRIO EXTRA
    printf("Com qual cenário extra trabalharemos?\n Cenário 1: digite 1, Cenário 2: digite 2, Cenários 1 e 2: digite 3, nenhum cenário extra: digite 0\n");
    scanf("%i", &cenario);

    ///Caso o cenário 1 seja escolhido 
    if(cenario == 1){

        FILE *cenario1; ///vetor cenario1 para a variável de tipo FILE que irá ser o arquivo de saída do cenário 1
        cenario1 = fopen("cenário1.csv", "w");

        ///Solicitação dos dados necessários para o cálculo do modelo
        printf("Digite quanto tempo (em horas) depois do contágio se iniciou o cenário:\n");
        scanf("%f", &tempo);

        printf("Digite o novo T:\n");
        scanf("%f", &config.bT);

        ///Alteração da variável b
        config.bresult = formulab(config);

        t = 0;

        ///Impressão das nomenclaturas das variáveis no arquivo
        fprintf (cenario1, "S(t),");
        fprintf (cenario1, "I(t),");
        fprintf (cenario1, "R(t),");
        fprintf (cenario1, "t\n");

        ///Impressão dos dados que não foram alterados
        for (i = 0; i <= tempo; i = i + config.h){
            fprintf (cenario1, "%.2f,", S[t]);
            fprintf (cenario1, "%.2f,", I[t]);
            fprintf (cenario1, "%.2f,", R[t]);
            fprintf (cenario1, "%f\n", i);

           t++;

         }

        ///Cálculo do novo modelo com a alteração de cenário
        sir(config, S, I, R, i, t);

        ///Impressão do restante dos dados
        for (t; t <= TAM; t++){

            fprintf (cenario1, "%.2f,", S[t]);
            fprintf (cenario1, "%.2f,", I[t]);
            fprintf (cenario1, "%.2f,", R[t]);
            fprintf (cenario1, "%f\n", i);

            i = i + config.h;

        }

        fclose(cenario1);

        printf("Sua simulação foi gerada! :)\n");
   
    }

    ///Caso o cenário 2 seja escolhido
    if(cenario == 2){

        FILE *cenario2; ///vetor cenario2 para a variável de tipo FILE que irá ser o arquivo de saída do modelo
        cenario2 = fopen("cenário2.csv", "w");

        ///Solicitação dos dados necessários para o cálculo do modelo
        printf("Digite quanto tempo (em horas) depois do contágio se iniciou o cenário:\n");
        scanf("%f", &tempo);

        printf("Digite o novo T':\n");
        scanf("%f", &config.kt1);

        ///Alteração da variável k
        config.kresult = formulak (config);

        t = 0;

        ///Impressão das nomenclaturas das variáveis no arquivo
        fprintf (cenario2, "S(t),");
        fprintf (cenario2, "I(t),");
        fprintf (cenario2, "R(t),");
        fprintf (cenario2, "t\n");

        ///Impressão dos dados que não foram alterados
        for (i = 0; i <= tempo; i = i+config.h){
            fprintf (cenario2, "%.2f,", S[t]);
            fprintf (cenario2, "%.2f,", I[t]);
            fprintf (cenario2, "%.2f,", R[t]);
            fprintf (cenario2, "%f\n", i);

           t++;

         }

        ///Cálculo do novo modelo com a alteração de cenário
        sir(config, S, I, R, i, t);

        ///Impressão do restante dos dados
        for (t; t <= TAM; t++){

            fprintf (cenario2, "%.2f,", S[t]);
            fprintf (cenario2, "%.2f,", I[t]);
            fprintf (cenario2, "%.2f,", R[t]);
            fprintf (cenario2, "%f\n", i);

            i = i + config.h;

        }

        fclose(cenario2); 

        printf("Sua simulação foi gerada! :)\n"); 

    }

    ///Caso seja solicitado para que se calcule os dois cenários
    if (cenario == 3){

        FILE *cenario1; ///vetor cenario1 para a variável de tipo FILE que irá ser o arquivo de saída do modelo
        cenario1 = fopen("cenário1.csv", "w");

        FILE *cenario2; ///vetor cenario2 para a variável de tipo FILE que irá ser o arquivo de saída do modelo
        cenario2 = fopen("cenário2.csv", "w");

        ///Solicitação dos dados necessários para o cálculo do modelo (cenário 1)
        printf("Digite quanto tempo (em horas) depois do contágio se iniciou o cenário 1:\n");
        scanf("%f", &tempo);

        printf("Digite o novo T:\n");
        scanf("%f", &config.bT);

        ///Salvando a variável b em uma variável de reserva, para utilizar o valor futuramente
        reserva = config.bresult;

        ///Cálculo do novo valor de b
        config.bresult = formulab(config);

        t = 0;

        ///Impressão das nomenclaturas das variáveis no arquivo
        fprintf (cenario1, "S(t),");
        fprintf (cenario1, "I(t),");
        fprintf (cenario1, "R(t),");
        fprintf (cenario1, "t\n");

        ///Impressão dos dados que não foram alterados
        for (i = 0; i <= tempo; i = i+config.h){
            fprintf (cenario1, "%.2f,", S[t]);
            fprintf (cenario1, "%.2f,", I[t]);
            fprintf (cenario1, "%.2f,", R[t]);
            fprintf (cenario1, "%f\n", i);

           t++;

         }

        ///Cálculo do novo modelo com a alteração de cenário 1
        sir(config, S, I, R, i, t);

        ///Impressão do restante dos dados
        for (t; t <= TAM; t++){

            fprintf (cenario1, "%.2f,", S[t]);
            fprintf (cenario1, "%.2f,", I[t]);
            fprintf (cenario1, "%.2f,", R[t]);
            fprintf (cenario1, "%f\n", i);

            i = i + config.h;

        }

        fclose(cenario1);

        ///Solicitação dos dados necessários para o cálculo do modelo (cenário 2)
        printf("Digite quanto tempo (em horas) depois do contágio se iniciou o cenário 2:\n");
        scanf("%f", &tempo);

        printf("Digite o novo T':\n");
        scanf("%f", &config.kt1);

        ///Atribuição do antigo valor de b à variável b
        config.bresult = reserva;

        ///Cálculo do novo valor de k
        config.kresult = formulak (config);

        t = 0;

        ///Impressão das nomenclaturas das variáveis no arquivo
        fprintf (cenario2, "S(t),");
        fprintf (cenario2, "I(t),");
        fprintf (cenario2, "R(t),");
        fprintf (cenario2, "t\n");

        ///Impressão dos dados que não foram alterados
        for (i = 0; i <= tempo; i = i+config.h){
            fprintf (cenario2, "%.2f,", S[t]);
            fprintf (cenario2, "%.2f,", I[t]);
            fprintf (cenario2, "%.2f,", R[t]);
            fprintf (cenario2, "%f\n", i);

           t++;

         }

        ///Cálculo do novo modelo com a alteração de cenário 2
        sir(config, S, I, R, i, t);

        ///Impressão do restante dos dados
        for (t; t <= TAM; t++){

            fprintf (cenario2, "%.2f,", S[t]);
            fprintf (cenario2, "%.2f,", I[t]);
            fprintf (cenario2, "%.2f,", R[t]);
            fprintf (cenario2, "%f\n", i);

            i = i + config.h;

        }

        fclose(cenario2);  

        printf("Sua simulação foi gerada! :)\n");

    }

    if (cenario == 0){

        printf("Sua simulação foi gerada! :)\n");
    }


    ///Limpando os espaços de memória
    free (S);
    free (I);
    free (R);
    
return 0;
}