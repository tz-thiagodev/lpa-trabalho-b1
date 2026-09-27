#include <stdio.h>

float calcularValorBase(float distancia) {
    float valorBase;

    if (distancia > 0 && distancia <= 5) {
        valorBase = 8;
    } else if (distancia > 5 && distancia <= 15) {
        valorBase = 12;
    } else if (distancia > 15 && distancia <= 30) {
        valorBase = 18;
    } else {
        valorBase = 25;
    }

    return valorBase;
}

float calcularAdicionalPeso(float peso,  float subtotalInicial) {
    float adicionalPeso;

    if (peso > 0 && peso <= 2) {
        adicionalPeso = 0;

    } else if (peso > 2 && peso <= 5) {
        adicionalPeso = subtotalInicial * 0.05;

    } else if (peso > 5 && peso <= 10) {
        adicionalPeso = subtotalInicial * 0.10;

    } else if (peso > 10) {
        adicionalPeso = subtotalInicial * 0.20;
    }  

    return adicionalPeso;
}

float calcularAdicionalModalidade(int modalidade,  float subtotalInicial) {
    float adicionalModalidade;

    if (modalidade == 1) {
        adicionalModalidade = 0;
    } else if (modalidade == 2) {
        adicionalModalidade = subtotalInicial * 0.15;
    } else if (modalidade == 3) {
        adicionalModalidade = subtotalInicial * 0.3;
    }

    return adicionalModalidade;
}

float calcularAdicionalProtecao(int servicoProtecao) {
    float adicionalProtecao;

    if (servicoProtecao == 0) {
        adicionalProtecao = 0;
    } else if (servicoProtecao == 1) {
        adicionalProtecao = 7.50;
    }

    return adicionalProtecao;
}

float calcularAdicionalTentativas(int tentativasEntrega) {
    float adicionalTentativas;

        if (tentativasEntrega == 0) {
            adicionalTentativas = 0;
        } else if (tentativasEntrega >= 1) {
            adicionalTentativas = (tentativasEntrega * 4);
        }

    return adicionalTentativas;
}


//FUNCAO PRINCIPAL====================================================

int main(void) {
    int continuarLoop;
    int modalidade;
    int tentativasEntrega;
    int servicoProtecao;
    float peso;
    float distancia;
    float baseDistancia;
    float subtotalInicial;
    float adicionalPeso;
    float adicionalModalidade;
    float adicionalProtecao;
    float adicionalTentativas;
    float subtotal;
    int totalEntregas = 0;
    float valorTotalSessao = 0;
    int qtdEconomica = 0, qtdExpressa = 0, qtdPrioritaria = 0;
    float maiorValor = 0, menorValor = 0;

    do {
        printf("\n===== ENTREGA =====\n\n");

        //dados======================

        do {
            printf("Digite a distancia da entrega (em Km): ");
            scanf("%f", &distancia);

            if (distancia <= 0) {
                printf("\nOpcao invalida! Digite novamente.\n\n");
            }

        } while (distancia <= 0);

        do {
        
            printf("\nDigite o peso da entrega (em Kg): ");
            scanf("%f", &peso);

            if (peso <= 0) {
                printf("\nOpcao invalida! Digite novamente.\n");
            }

        } while (peso <= 0);

        do {
        
            printf("\nQual a modalidade da entrega?\n");
            printf("1 - Economica\n");
            printf("2 - Expressa\n");
            printf("3 - Prioritaria\n");
            printf("Digite sua opcao: ");
            scanf("%d", &modalidade);

            if (modalidade != 1 && modalidade != 2 && modalidade != 3) {
                printf("\nOpcao invalida! Digite novamente.\n");
            }

        } while (modalidade != 1 && modalidade != 2 && modalidade != 3);

        do {
        
            printf("\nQuer um servico adicional de protecao?\n");
            printf("0 - Nao\n");
            printf("1 - Sim\n");
            printf("Digite sua opcao: ");
            scanf("%d", &servicoProtecao);

            if (servicoProtecao != 0 && servicoProtecao != 1) {
                printf("\nOpcao invalida! Digite novamente.\n");
            }

        } while (servicoProtecao != 0 && servicoProtecao != 1);

        do {
            
            printf("\nDigite a quantidades de tentativas de entrega: ");
            scanf("%d", &tentativasEntrega);

            if (tentativasEntrega < 0) {
                printf("Opcao invalida! Digite novamente.\n");
            }

        } while (tentativasEntrega < 0);

        //processamento================================================================

        baseDistancia = calcularValorBase(distancia);

        subtotalInicial = baseDistancia + (distancia * 1.20);

        adicionalPeso = calcularAdicionalPeso(peso, subtotalInicial);

        adicionalModalidade = calcularAdicionalModalidade(modalidade, subtotalInicial);

        adicionalProtecao = calcularAdicionalProtecao(servicoProtecao);

        adicionalTentativas = calcularAdicionalTentativas(tentativasEntrega);

        subtotal = subtotalInicial + adicionalModalidade + adicionalPeso + adicionalProtecao + adicionalTentativas; 

        totalEntregas++;
        valorTotalSessao += subtotal;

        if (modalidade == 1) qtdEconomica++;
        else if (modalidade == 2) qtdExpressa++;
        else if (modalidade == 3) qtdPrioritaria++;

        if (totalEntregas == 1) {
            maiorValor = subtotal;
            menorValor = subtotal;

        } else if (subtotal > maiorValor) {
            maiorValor = subtotal;

        } else if (subtotal < menorValor) {
            menorValor = subtotal;
        }

        printf("\n\n===============================");
        printf("\n\nValor desta entrega: R$ %.2f\n", subtotal);
        printf("\n===============================");
        
        do {
            
            printf("\n\nQuer continuar com o loop?\n0 - Nao\n1 - Sim\n\nDigite sua opcao: ");
            scanf("%d", &continuarLoop);

            if (continuarLoop != 0 && continuarLoop != 1) {
                printf("Opcao invalida! Digite novamente.\n\n");
            }

        } while (continuarLoop != 0 && continuarLoop != 1);

    } while (continuarLoop == 1); 


    printf("\n===== RESUMO DA SESSAO =====\n\n");
    printf("Total de entregas: %d\n", totalEntregas);
    printf("Valor total: R$ %.2f\n", valorTotalSessao);
    printf("Valor medio: R$ %.2f\n", valorTotalSessao / totalEntregas);
    printf("Entregas Economicas: %d\n", qtdEconomica);
    printf("Entregas Expressas: %d\n", qtdExpressa);
    printf("Entregas Prioritarias: %d\n", qtdPrioritaria);
    printf("Maior valor: R$ %.2f\n", maiorValor);
    printf("Menor valor: R$ %.2f\n", menorValor);


    return 0;
}