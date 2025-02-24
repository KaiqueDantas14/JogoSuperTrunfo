/*Nivel aventureiro
Nesse nivel criei dois menus utilizando o switch: um principal e um para escolher um atributo como criterio de desempate. 
deixei a saida de dados mais amigavel possivel para o jogador */

#include <stdio.h>

typedef struct SuperTrunfo { // Criando struct para armazenar os dados das cartas
    char estado[3];
    char codigoDaCarta[4];
    char nomeDaCidade[60];
    int pontosTuristicos;
    float area, pib, densidadePopulacional, pIBperCapita, populacao;
} SuperTrunfo;

int main() {
    int opcao;   

    printf("=================================\n");
    printf(" Bem-vindo ao Super Trunfo! 🎴\n");
    printf("=================================\n");
    printf("Prepare-se para desafiar seus oponentes em partidas emocionantes!\n");
    printf("Escolha suas cartas com sabedoria e vença o jogo!\n\n");

    printf("Escolha uma opção: \n");
    printf("1. Jogar \n");
    printf("2. Regras \n");
    printf("3. Sair\n");
    printf("> ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1: {
            struct SuperTrunfo carta1, carta2; 

            printf("\nInsira os dados da primeira carta:\n");

            // Entrada de dados para a primeira carta
            printf("Estado (ex: SP): ");
            scanf("%2s", carta1.estado);
            getchar();

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

            printf("\nInsira os dados da segunda carta:\n");

            // Entrada de dados para a segunda carta
            printf("Estado (ex: SP): ");
            scanf("%2s", carta2.estado);
            getchar();

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
            int desempate1, desempate2;
            char escolha;
        
            printf("\nEscolha um atributo como critério de desempate: \n");
            printf("a. PIB\n");
            printf("b. População\n");
            printf("c. Pontos Turísticos\n");
            printf("d. Área\n");
            printf("> ");
            scanf(" %c", &escolha);

            switch (escolha) {
                case 'a':
                    desempate1 = carta1.pib;
                    desempate2 = carta2.pib;
                    break;
                case 'b':
                    desempate1 = carta1.populacao;
                    desempate2 = carta2.populacao;
                    break;
                case 'c':
                    desempate1 = carta1.pontosTuristicos;
                    desempate2 = carta2.pontosTuristicos;
                    break;
                case 'd':
                    desempate1 = carta1.area;
                    desempate2 = carta2.area;
                    break;
                default:
                    printf("Opção Inválida!\n");
                    return 1;
            }

            printf("\nCritério de desempate escolhido: %c\n", escolha);

            // Comparação das cartas
            printf("\n============================\n");
            printf("       RESULTADO FINAL      \n");
            printf("============================\n");

            if (carta1.densidadePopulacional < carta2.densidadePopulacional) {
                printf("Vencedor: %s (Menor Densidade Populacional: %.2f)\n", 
                       carta1.nomeDaCidade, carta1.densidadePopulacional);
            } else if (carta2.densidadePopulacional < carta1.densidadePopulacional) {
                printf("Vencedor: %s (Menor Densidade Populacional: %.2f)\n", 
                       carta2.nomeDaCidade, carta2.densidadePopulacional);
            } else {
                printf("Empate na Densidade Populacional!\n");
                printf("*** Desempate pelo critério escolhido ***\n");

                if (desempate1 > desempate2) {
                    printf("Vencedor: %s pelo critério de desempate!\n", carta1.nomeDaCidade);
                } else if (desempate2 > desempate1) {
                    printf("Vencedor: %s pelo critério de desempate!\n", carta2.nomeDaCidade);
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
