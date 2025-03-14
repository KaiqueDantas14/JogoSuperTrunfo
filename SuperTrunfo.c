/*Nivel Mestre*/
/*Nesse nivel, foi feita a logica para que o usuario escolha quais atributos ele quer usar como criterio de desempate, implementei também a logica para que o usuário não consiga utilizar o mesmo atributo duas vezes
foram feitas melhorias na legibilidade, deixando tanto a saida de dados quanto o codigo melhor para se ler */
#include <stdio.h>

typedef struct SuperTrunfo {
    char pais[50];
    char codigoDaCarta[4];
    char nomeDaCidade[60];
    int pontosTuristicos;
    float area, pib, densidadePopulacional, pIBperCapita, populacao;
} SuperTrunfo;

int main() {

    printf("=================================\n");
    printf(" Bem-vindo ao Super Trunfo! 🎴\n");
    printf("=================================\n");
    printf("Prepare-se para desafiar seus oponentes em partidas emocionantes!\n");
    printf("Escolha suas cartas com sabedoria e vença o jogo!\n\n");

    int opcao;
    printf("Escolha uma opção: \n");
    printf("1. Jogar \n");
    printf("2. Regras \n");
    printf("3. Sair\n");
    printf("> ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1: {
            struct SuperTrunfo carta1, carta2;

            // Primeira carta
            printf("\nInsira os dados da primeira carta:\n");

            printf("País: ");
            getchar(); // Limpa o buffer antes de ler o país
            fgets(carta1.pais, sizeof(carta1.pais), stdin);

            printf("Nome da Cidade: ");
            fgets(carta1.nomeDaCidade, sizeof(carta1.nomeDaCidade), stdin);

            printf("Código da carta (ex: A01): ");
            scanf("%3s", carta1.codigoDaCarta);

            printf("População (ex: 406.123): ");
            scanf("%f", &carta1.populacao);

            printf("Área (ex: 1521.202): ");
            scanf("%f", &carta1.area);

            printf("PIB (ex: 1234567.89): ");
            scanf("%f", &carta1.pib);

            printf("Número de pontos turísticos: ");
            scanf("%d", &carta1.pontosTuristicos);

            // Cálculos da carta 1
            carta1.densidadePopulacional = carta1.populacao / carta1.area;
            carta1.pIBperCapita = carta1.pib / carta1.populacao;

            // Segunda carta
            printf("\nInsira os dados da segunda carta:\n");

            printf("País: ");
            getchar(); // Limpa o buffer antes de ler o país
            fgets(carta2.pais, sizeof(carta2.pais), stdin);

            printf("Nome da Cidade: ");
            fgets(carta2.nomeDaCidade, sizeof(carta2.nomeDaCidade), stdin);

            printf("Código da carta (ex: A01): ");
            scanf("%3s", carta2.codigoDaCarta);

            printf("População (ex: 406.123): ");
            scanf("%f", &carta2.populacao);

            printf("Área (ex: 1521.202): ");
            scanf("%f", &carta2.area);

            printf("PIB (ex: 1234567.89): ");
            scanf("%f", &carta2.pib);

            printf("Número de pontos turísticos: ");
            scanf("%d", &carta2.pontosTuristicos);

            // Cálculos da carta 2
            carta2.densidadePopulacional = carta2.populacao / carta2.area;
            carta2.pIBperCapita = carta2.pib / carta2.populacao;

            // Escolha do critério de desempate
            float desempate1, desempate2, desempate11, desempate22;
            char escolha, escolha2;

            printf("\nEscolha o primeiro atributo como critério de desempate: \n");
            printf("a. PIB\n");
            printf("b. População\n");
            printf("c. Pontos Turísticos\n");
            printf("d. Área\n");
            printf("> ");
            getchar(); // Limpa o buffer antes de ler o critério
            scanf("%c", &escolha);

            switch (escolha) {
                case 'a':
                    desempate1 = carta1.pib;
                    desempate2 = carta2.pib;
                    printf("Atributo PIB escolhido\n");
                    break;
                case 'b':
                    desempate1 = carta1.populacao;
                    desempate2 = carta2.populacao;
                    printf("Atributo população escolhido\n");
                    break;
                case 'c':
                    desempate1 = carta1.pontosTuristicos;
                    desempate2 = carta2.pontosTuristicos;
                    printf("Atributo Pontos Turisticos escolhido\n");
                    break;
                case 'd':
                    desempate1 = carta1.area;
                    desempate2 = carta2.area;
                    printf("Atributo área escolhido\n");
                    break;
                default:
                    printf("Opção Inválida!\n");
                    return 1;
            }

            while(1) {
                printf("\nEscolha o segundo atributo como critério de desempate: \n");
                printf("a. PIB\n");
                printf("b. População\n");
                printf("c. Pontos Turísticos\n");
                printf("d. Área\n");
                printf("> ");
                getchar(); // Limpa o buffer antes de ler o critério
                scanf("%c", &escolha2);

                if (escolha2 == escolha) {
                    printf("Você já escolheu esse atributo! Tente novamente.\n");
                    continue;
                }

                switch (escolha2) {
                    case 'a':
                        desempate11 = carta1.pib;
                        desempate22 = carta2.pib;
                        printf("Atributo PIB escolhido\n");
                        break;
                    case 'b':
                        desempate11 = carta1.populacao;
                        desempate22 = carta2.populacao;
                        printf("Atributo população escolhido\n");
                        break;
                    case 'c':
                        desempate11 = carta1.pontosTuristicos;
                        desempate22 = carta2.pontosTuristicos;
                        printf("Atributo Pontos Turisticos escolhido\n");
                        break;
                    case 'd':
                        desempate11 = carta1.area;
                        desempate22 = carta2.area;
                        printf("Atributo área escolhido\n");
                        break;
                    default:
                        printf("Opção Inválida! Tente novamente.\n");
                        continue;
                }
                break;
            }

            // Soma dos atributos escolhidos
            float SomaTotal1 = desempate1 + desempate11;
            float SomaTotal2 = desempate2 + desempate22;

            // Comparação das cartas
            printf("\n============================\n");
            printf("       RESULTADO FINAL      \n");
            printf("============================\n");

            if (carta1.densidadePopulacional < carta2.densidadePopulacional) {
                printf("Vencedor: %s do País %s (Menor Densidade Populacional: %.2f)\n", carta1.nomeDaCidade, carta1.pais, carta1.densidadePopulacional);
            } else if (carta2.densidadePopulacional < carta1.densidadePopulacional) {
                printf("Vencedor: %s do País %s (Menor Densidade Populacional: %.2f)\n", carta2.nomeDaCidade, carta2.pais, carta2.densidadePopulacional);
            } else {
                printf("Empate na Densidade Populacional!\n");
                printf("*** Desempate pelo critério escolhido ***\n");

                if (SomaTotal1 > SomaTotal2) {
                    printf("Vencedor: %s  do País %s pela soma total dos atributos!\n", carta1.nomeDaCidade, carta1.pais);
                    printf("Soma total: %.3f\n", SomaTotal1);
                } else if (SomaTotal2 > SomaTotal1) {
                    printf("Vencedor: %s do País %s pela soma total dos atributos!\n", carta2.nomeDaCidade, carta2.pais);
                    printf("Soma total: %.3f\n", SomaTotal2);
                } else {
                    printf("Empate total entre as duas cartas!\n");
                }
            }
            break;
        }

        case 2:
            printf("\n***** REGRAS *****\n");
            printf("- Cada jogador cadastra duas cartas com dados de cidades.\n");
            printf("- A carta com menor densidade populacional vence.\n");
            printf("- Em caso de empate, o desempate ocorre pelo critério escolhido!\n");
            break;

        case 3:
            printf("\nObrigado por jogar! 😉\n");
            break;

        default:
            printf("\nOpção inválida!\n");
    }

    return 0;
}
