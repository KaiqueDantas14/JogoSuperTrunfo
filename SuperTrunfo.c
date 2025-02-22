#include <stdio.h>

typedef struct SuperTrunfo // Criando struct para armazenar os dados das cartas
{
    char estado[3];
    char codigoDaCarta[4];
    char nomeDaCidade[60];
    int pontosTuristicos;
    float area, pib, densidadePopulacional, pIBperCapita, populacao;
}SuperTrunfo;

int main() {

    struct SuperTrunfo carta1, carta2; /*Permite acessar os dados da struct
    e crio duas variáveis*/

    printf("Insira os dados da primeira carta:\n");

    // Entrada de dados para a primeira carta
    printf("Estado (ex: SP): ");
    scanf("%2s", carta1.estado); // Leitura do estado
    getchar();  // Limpeza do buffer

    printf("Nome da Cidade: ");
    fgets(carta1.nomeDaCidade, sizeof(carta1.nomeDaCidade), stdin); // Leitura do nome da cidade

    printf("Codigo da carta (ex: A01): ");
    scanf("%3s", carta1.codigoDaCarta);

    printf("População (ex: 406.123): ");
    scanf("%f", &carta1.populacao); // Leitura da população

    printf("Área (ex: 1521.202): ");
    scanf("%f", &carta1.area); // Leitura da área

    printf("PIB (ex: 1234567.89): ");
    scanf("%f", &carta1.pib); // Leitura do PIB

    printf("Numero de pontos turísticos: ");
    scanf("%d", &carta1.pontosTuristicos); // Leitura dos pontos turísticos

    // Cálculos da carta 1
    carta1.densidadePopulacional = carta1.populacao / carta1.area;
    carta1.pIBperCapita = carta1.pib / carta1.populacao; 

    printf("Insira os dados da segunda carta:\n");

    // Entrada de dados para a segunda carta
    printf("Estado (ex: SP): ");
    scanf("%2s", carta2.estado); // Leitura do estado
    getchar();  // Limpeza do buffer

    printf("Nome da Cidade: ");
    fgets(carta2.nomeDaCidade, sizeof(carta2.nomeDaCidade), stdin); // Leitura do nome da cidade

    printf("Codigo da carta (ex: A01): ");
    scanf("%3s", carta2.codigoDaCarta);

    printf("População (ex: 406.123): ");
    scanf("%f", &carta2.populacao); // Leitura da população

    printf("Área (ex: 1521.202): ");
    scanf("%f", &carta2.area); // Leitura da área

    printf("PIB (ex: 1234567.89): ");
    scanf("%f", &carta2.pib); // Leitura do PIB

    printf("Numero de pontos turísticos: ");
    scanf("%d", &carta2.pontosTuristicos); // Leitura dos pontos turísticos

    // Cálculos da carta 2
    carta2.densidadePopulacional = carta2.populacao / carta2.area;
    carta2.pIBperCapita = carta2.pib / carta2.populacao; 

   // Saída de dados das cartas
printf("\nPrimeiro, vence a cidade menos densamente povoada. Se houver empate, ganha a cidade com maior área.\n");

// Exibição da Carta 1
printf("\nCarta 1:\n");
printf("| Estado: %s\n", carta1.estado);
printf("| Cidade: %s\n", carta1.nomeDaCidade);
printf("| PIB: %.2f\n", carta1.pib);
printf("| População: %.2f\n", carta1.populacao);
printf("| Área: %.2f\n", carta1.area);
printf("| Densidade: %.2f\n", carta1.densidadePopulacional);
printf("| PIB per Capita: %.2f\n", carta1.pIBperCapita);
printf("| Pontos Turisticos: %d\n", carta1.pontosTuristicos);

// Exibição da Carta 2
printf("\nCarta 2:\n");
printf("| Estado: %s\n", carta2.estado);
printf("| Cidade: %s\n", carta2.nomeDaCidade);
printf("| PIB: %.2f\n", carta2.pib);
printf("| População: %.2f\n", carta2.populacao);
printf("| Área: %.2f\n", carta2.area);
printf("| Densidade: %.2f\n", carta2.densidadePopulacional);
printf("| PIB per Capita: %.2f\n", carta2.pIBperCapita);
printf("| Pontos Turisticos: %d\n", carta2.pontosTuristicos);

// Comparação das cartas
if (carta1.densidadePopulacional < carta2.densidadePopulacional) {
    printf("\nVencedor: %s com menor Densidade Populacional: %.2f\n", carta1.nomeDaCidade, carta1.densidadePopulacional);
    printf("\nCarta 1 - %s(%s): Densidade Populacional %.2f\n", carta1.nomeDaCidade, carta1.estado, carta1.densidadePopulacional);
    printf("Carta 2 - %s(%s): Densidade Populacional %.2f\n", carta2.nomeDaCidade, carta2.estado, carta2.densidadePopulacional);
} else if (carta2.densidadePopulacional < carta1.densidadePopulacional) {
    printf("\nVencedor: %s com Menor Densidade Populacional: %.2f\n", carta2.nomeDaCidade, carta2.densidadePopulacional);
    printf("\nCarta 1 - %s(%s): Densidade Populacional %.2f\n", carta1.nomeDaCidade, carta1.estado, carta1.densidadePopulacional);
    printf("Carta 2 - %s(%s): Densidade Populacional %.2f\n", carta2.nomeDaCidade, carta2.estado, carta2.densidadePopulacional);
} else {
    // Caso de empate na densidade populacional
    printf("\nEmpate na Densidade Populacional!\n");
    printf("***Desempate por Área***\n");

    if (carta1.area > carta2.area) {
        printf("\nVencedor: %s com Maior Área: %.2f km²\n", carta1.nomeDaCidade, carta1.area);
        printf("\nCarta 1 - %s: Área %.2f km²\n", carta1.nomeDaCidade, carta1.area);
        printf("\nCarta 2 - %s: Área %.2f km²\n", carta2.nomeDaCidade, carta2.area);
    } else if (carta2.area > carta1.area) {
        printf("\nVencedor: %s com Maior Área: %.2f km²\n", carta2.nomeDaCidade, carta2.area);
        printf("\nCarta 1 - %s: Área %.2f km²\n", carta1.nomeDaCidade, carta1.area);
        printf("\nCarta 2 - %s: Área %.2f km²\n", carta2.nomeDaCidade, carta2.area);
    } else {
        printf("Empate total entre as duas cartas!\n");
    }
}


    return 0;
}
