#include <stdio.h>

int main() {
    int continuarLoop;
    int modalidade;
    int tentativasEntrega;
    int servicoProtecao;
    float distancia, peso;

    do {
        printf("\n===== ENTREGA =====\n\n");

            //dados======================

            printf("Digite a distancia da entrega (em Km): ");
            scanf("%f", &distancia);

            printf("\nDigite o peso da entrega (em Kg): ");
            scanf("%f", &peso);

            printf("\nQual a modalidade da entrega?\n");
            printf("1 - Economica\n");
            printf("2 - Expressa\n");
            printf("3 - Prioritaria\n");
            printf("Digite sua opcao: ");
            scanf("%d", &modalidade);

            printf("\nQuer um servico adicional de protecao?\n");
            printf("0 - Nao\n");
            printf("1 - Sim\n");
            printf("Digite sua opcao: ");
            scanf("%d", &servicoProtecao);

            printf("\nDigite a quantidades de tentativas de entrega: ");
            scanf("%d", &tentativasEntrega);

        do {
            
            printf("\nQuer continuar com o loop? 1 - Sim ; 0 - Nao: ");
            scanf("%d", &continuarLoop);

            if (continuarLoop != 0 && continuarLoop != 1) {
                printf("Opcao invalida! Digite novamente.\n");
            }

        } while (continuarLoop != 0 && continuarLoop != 1);

    } while (continuarLoop == 1); 

    printf("Fim");

    return 0;
}