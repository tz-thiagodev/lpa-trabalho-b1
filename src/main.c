#include <stdio.h>

int main() {
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

    do {
        printf("\n===== ENTREGA =====\n\n");

        //dados======================

        do {
        
            printf("Digite a distancia da entrega (em Km): ");
            scanf("%f", &distancia);

            if (distancia <= 0) {
                printf("\nOpcao invalida! Digite novamente.\n");
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

        //processamento======================

        //distancia
        if (distancia > 0 && distancia <= 5) {
            baseDistancia = 8;

        } else if (distancia > 5 && distancia <= 15) {
            baseDistancia = 12;
            
        } else if (distancia > 15 && distancia <= 30) {
            baseDistancia = 18;
            
        } else if (distancia > 30) {
            baseDistancia = 25;
        }

        subtotalInicial = baseDistancia + (distancia * 1.20);

        //peso
        if (peso > 0 && peso <= 2) {
            adicionalPeso = 0;

        } else if (peso > 2 && peso <= 5) {
            adicionalPeso = subtotalInicial * 0.05;

        } else if (peso > 5 && peso <= 10) {
            adicionalPeso = subtotalInicial * 0.10;

        } else if (peso > 10) {
            adicionalPeso = subtotalInicial * 0.20;
        }  

        //modalidade
        if (modalidade == 1) {
            adicionalModalidade = 0;
        } else if (modalidade == 2) {
            adicionalModalidade = subtotalInicial * 0.15;
        } else if (modalidade == 3) {
            adicionalModalidade = subtotalInicial * 0.3;
        }

        //protecao
        if (servicoProtecao == 0) {
            adicionalProtecao = 0;
        } else if (servicoProtecao == 1) {
            adicionalProtecao = 7.50;
        }

        //tentativas
        if (tentativasEntrega == 0) {
            adicionalTentativas = 0;
        } else if (tentativasEntrega >= 1) {
            adicionalTentativas = (tentativasEntrega * 4);
        }

        subtotal = subtotalInicial + adicionalModalidade + adicionalPeso + adicionalProtecao + adicionalTentativas; 
        printf("%.2f", subtotal);
        
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