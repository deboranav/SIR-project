# SIR-project
Esse é um pequeno projeto em C, apenas para praticar. Nele, desenvolvi um modelo computacional epidemiológico do tipo SIR (Suscetível-Infectado-Removido).
## Modelo computacional epidemiológico (MEC) - SIR
Os MEC são utilizados para compreender o funcionamento de uma epidemia ou afim, portanto, de extrema importância para a determinação de políticas públicas para combate e prevenção de doenças. 
Um modelo bastante utilizado é o do tipo SIR (Suscetível-Infectado-Removido), que considera as seguintes populações:
* S: número de indivíduos suscetíveis (que ainda não estão contaminados);
* I: número de indivíduos infectados (capazes de infectar indivíduos S);
* R: número de indivíduos removidos (que se recuperaram, tornaram-se imunes ou
faleceram).
Neste tipo, um indivíduo da população S pode permanecer em S ou ir para a população I, caso seja infectado. Um indivíduo de I pode, então, se recuperar ou falecer. Indivíduos que pertençam a R não mudam de população. A interação entre essas populações pode ser descrita pelas equações abaixo:

S(t) = S(t − 1) − h.b.S(t − 1).I(t − 1)

I(t) = I(t − 1) + h.[b.S(t − 1).I(t − 1) − k.I(t − 1)]

R(t) = R(t − 1) + h.k.I(t − 1)

tempo(t) = tempo(t − 1) + h

Em que:
* h: pequeno intervalo de tempo (em horas);
* b: facilidade de contágio de um indivíduo;
* k: probabilidade que um indivíduo se recupere;
* tempo: instantes de tempo nos quais o modelo é simulado (em horas).

Para estimar o parâmetro b, pode-se observar, durante um intervalo de tempo T, quantos indivíduos N se infectaram, considerando-se o número de pessoas suscetíveis e o número de
pessoas infectadas no início da observação. A equação abaixo resume o cálculo:

b = N/TS*I0*0

Em que:
* N: número de pessoas suscetíveis que se infectaram em um intervalo de tempo T
* S : número de pessoas suscetíveis no início da observação 0
* I : número de pessoas infectadas no início da observação 0

Para se estimar o parâmetro k, pode-se observar, durante um intervalo de tempo T’, quantos indivíduos m se recuperaram de um total de n indivíduos. A equação abaixo resume o
cálculo:

k = m/nT′

## Cenários extra

A partir do cenário definido pelos parâmetros de entrada do simulador (Cenário 0), serão executados outros cenário com diferentes estratégias de contenção:
1. Cenário 1: Distanciamento/uso de máscaras
Esta estratégia refere-se à facilidade/dificuldade de contágio na população, influenciando assim a variável b da equação. Para este cenário, suponha que o tempo de contaminação agora passa a ser maior (maior valor de T, embora os mais continuam constantes), como esta ação só ocorre depois da percepção do contágio, suponha que este cenário só começa a partir de um determinado tempo.

2. Cenário 2: Melhoria nos protocolos de atendimento
Esta estratégia refere-se à capacidade de recuperação de pessoas já infectadas, influenciando assim a variável k da equação. Podemos simular esta modificação simplesmente reduzindo o tempo que leva para o paciente melhorar (menor valor de T’). Da mesma forma que o cenário 1 este cenário só passa a ser válido depois de um determinado tempo.

## O programa

O programa lê um arquivo de entrada .txt (descrito futuramente) e implementa o modelo SIR, tendo como saída um arquivo .csv (“saída.csv”), cujo conteúdo são quatro colunas referentes, respectivamente, a: S(t), I(t), R(t) e t. Além disso, o usuário pode solicitar a implementação dos cenários 1 e 2, essa implementação gera as saídas “cenário1.csv” e/ou “cenário2.csv”.

### Como criar o .txt de entrada
O arquivo .txt de entradas para o programa deve ser escrito separando os valores de entrada por vírgulas e deve haver um espaço entre o número e a vírgula que o antecede, de forma que não haja nada antes do primeiro valor. Além de seguir a ordem subsequente: S (0), I(0), R(0), h, N , T , S(0) , I(0) , m, n, T ′ e o tempo de simulação em dias. Segue abaixo um exemplo de entrada: 
                   68, 2, 0, 01, 12, 24, 10, 50, 6, 22, 24, 21
O arquivo deve ser nomeado como “entradas.txt” e deve ser salvo no mesmo diretório que o programa.

### Como solicitar a implementação dos cenários 1 e 2
Logo após a solicitação da execução do programa aparecerá uma mensagem solicitando para que seja informado qual cenário extra o usuário deseja simular (sendo as opções cenário 1, cenário 2, cenários 1 e 2, e nenhum cenário extra). Caso o usuário escolha algum cenário extra, os dados para a modificação serão solicitados (tempo de início do cenário e novo T e/ou novo T’. Após inserir os dados, o usuário receberá a informação de que a simulação foi gerada.

