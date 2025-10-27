#include <stdio.h>
#include <string.h>

// Estrutura que representa uma carta do Super Trunfo
typedef struct {
    char pais[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadeDemografica;
} Carta;

int main() {
    // --- Cadastro das cartas ---
    Carta carta1, carta2;

    // Carta 1 - Brasil
    strcpy(carta1.pais, "Brasil");
    carta1.populacao = 214000000;
    carta1.area = 8516000.0;
    carta1.pib = 2400000000000.0;
    carta1.pontosTuristicos = 35;
    carta1.densidadeDemografica = carta1.populacao / carta1.area;

    // Carta 2 - Argentina
    strcpy(carta2.pais, "Argentina");
    carta2.populacao = 46000000;
    carta2.area = 2780000.0;
    carta2.pib = 630000000000.0;
    carta2.pontosTuristicos = 25;
    carta2.densidadeDemografica = carta2.populacao / carta2.area;

    int opcao;

    // --- Menu interativo ---
    printf("===== SUPER TRUNFO - COMPARAÇÃO DE CARTAS =====\n\n");
    printf("Escolha o atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Número de pontos turísticos\n");
    printf("5 - Densidade demográfica\n");
    printf("Digite sua opção: ");
    scanf("%d", &opcao);

    printf("\n==============================================\n");

    // --- Lógica de comparação com switch ---
    switch (opcao) {
        case 1:
            printf("Atributo escolhido: População\n\n");
            printf("%s: %d habitantes\n", carta1.pais, carta1.populacao);
            printf("%s: %d habitantes\n\n", carta2.pais, carta2.populacao);

            if (carta1.populacao > carta2.populacao) {
                printf("Resultado: %s venceu!\n", carta1.pais);
            } else if (carta1.populacao < carta2.populacao) {
                printf("Resultado: %s venceu!\n", carta2.pais);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 2:
            printf("Atributo escolhido: Área\n\n");
            printf("%s: %.2f km²\n", carta1.pais, carta1.area);
            printf("%s: %.2f km²\n\n", carta2.pais, carta2.area);

            if (carta1.area > carta2.area) {
                printf("Resultado: %s venceu!\n", carta1.pais);
            } else if (carta1.area < carta2.area) {
                printf("Resultado: %s venceu!\n", carta2.pais);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 3:
            printf("Atributo escolhido: PIB\n\n");
            printf("%s: R$ %.2f trilhões\n", carta1.pais, carta1.pib / 1e12);
            printf("%s: R$ %.2f trilhões\n\n", carta2.pais, carta2.pib / 1e12);

            if (carta1.pib > carta2.pib) {
                printf("Resultado: %s venceu!\n", carta1.pais);
            } else if (carta1.pib < carta2.pib) {
                printf("Resultado: %s venceu!\n", carta2.pais);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 4:
            printf("Atributo escolhido: Pontos turísticos\n\n");
            printf("%s: %d pontos turísticos\n", carta1.pais, carta1.pontosTuristicos);
            printf("%s: %d pontos turísticos\n\n", carta2.pais, carta2.pontosTuristicos);

            if (carta1.pontosTuristicos > carta2.pontosTuristicos) {
                printf("Resultado: %s venceu!\n", carta1.pais);
            } else if (carta1.pontosTuristicos < carta2.pontosTuristicos) {
                printf("Resultado: %s venceu!\n", carta2.pais);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 5:
            printf("Atributo escolhido: Densidade demográfica\n\n");
            printf("%s: %.2f hab/km²\n", carta1.pais, carta1.densidadeDemografica);
            printf("%s: %.2f hab/km²\n\n", carta2.pais, carta2.densidadeDemografica);

            // Aqui a regra se inverte: menor valor vence
            if (carta1.densidadeDemografica < carta2.densidadeDemografica) {
                printf("Resultado: %s venceu!\n", carta1.pais);
            } else if (carta1.densidadeDemografica > carta2.densidadeDemografica) {
                printf("Resultado: %s venceu!\n", carta2.pais);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        default:
            printf("Opção inválida! Por favor, escolha uma opção de 1 a 5.\n");
            break;
    }

    printf("==============================================\n");

    return 0;
}
