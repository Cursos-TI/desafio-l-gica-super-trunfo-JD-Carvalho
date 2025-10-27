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

// Função para exibir o menu de atributos
void mostrarMenu(int atributoEscolhido) {
    printf("\nEscolha um atributo para comparar:\n");

    if (atributoEscolhido != 1) printf("1 - População\n");
    if (atributoEscolhido != 2) printf("2 - Área\n");
    if (atributoEscolhido != 3) printf("3 - PIB\n");
    if (atributoEscolhido != 4) printf("4 - Pontos turísticos\n");
    if (atributoEscolhido != 5) printf("5 - Densidade demográfica\n");

    printf("Digite sua opção: ");
}

// Função auxiliar para obter o valor de um atributo
float obterValor(Carta c, int atributo) {
    switch (atributo) {
        case 1: return c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return c.pontosTuristicos;
        case 5: return c.densidadeDemografica;
        default: return 0;
    }
}

// Função auxiliar para imprimir o nome do atributo
char* nomeAtributo(int atributo) {
    switch (atributo) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Pontos Turísticos";
        case 5: return "Densidade Demográfica";
        default: return "Desconhecido";
    }
}

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

    int atributo1 = 0, atributo2 = 0;
    float valor1_c1, valor1_c2, valor2_c1, valor2_c2;
    float soma1, soma2;

    printf("===== SUPER TRUNFO - NÍVEL MESTRE =====\n");

    // --- Escolha do primeiro atributo ---
    mostrarMenu(0);
    scanf("%d", &atributo1);

    // Validação do primeiro atributo
    if (atributo1 < 1 || atributo1 > 5) {
        printf("Opção inválida! Encerrando o programa.\n");
        return 0;
    }

    // --- Escolha do segundo atributo (menu dinâmico) ---
    mostrarMenu(atributo1);
    scanf("%d", &atributo2);

    // Validação do segundo atributo
    if (atributo2 < 1 || atributo2 > 5 || atributo2 == atributo1) {
        printf("Opção inválida ou repetida! Encerrando o programa.\n");
        return 0;
    }

    printf("\n=============================================\n");
    printf("Comparação entre %s e %s\n\n", carta1.pais, carta2.pais);

    // --- Obter valores dos atributos escolhidos ---
    valor1_c1 = obterValor(carta1, atributo1);
    valor1_c2 = obterValor(carta2, atributo1);
    valor2_c1 = obterValor(carta1, atributo2);
    valor2_c2 = obterValor(carta2, atributo2);

    // --- Comparar e exibir resultados individuais ---
    printf("Atributo 1: %s\n", nomeAtributo(atributo1));
    printf("%s: %.2f\n", carta1.pais, valor1_c1);
    printf("%s: %.2f\n", carta2.pais, valor1_c2);

    int vencedor1 = 0;
    if (atributo1 == 5) { // Densidade demográfica -> menor vence
        vencedor1 = (valor1_c1 < valor1_c2) ? 1 : (valor1_c1 > valor1_c2 ? 2 : 0);
    } else {
        vencedor1 = (valor1_c1 > valor1_c2) ? 1 : (valor1_c1 < valor1_c2 ? 2 : 0);
    }

    printf("Vencedor do atributo 1: %s\n\n",
           vencedor1 == 1 ? carta1.pais : vencedor1 == 2 ? carta2.pais : "Empate");

    printf("Atributo 2: %s\n", nomeAtributo(atributo2));
    printf("%s: %.2f\n", carta1.pais, valor2_c1);
    printf("%s: %.2f\n", carta2.pais, valor2_c2);

    int vencedor2 = 0;
    if (atributo2 == 5) {
        vencedor2 = (valor2_c1 < valor2_c2) ? 1 : (valor2_c1 > valor2_c2 ? 2 : 0);
    } else {
        vencedor2 = (valor2_c1 > valor2_c2) ? 1 : (valor2_c1 < valor2_c2 ? 2 : 0);
    }

    printf("Vencedor do atributo 2: %s\n\n",
           vencedor2 == 1 ? carta1.pais : vencedor2 == 2 ? carta2.pais : "Empate");

    // --- Calcular soma dos valores (normalizando densidade demográfica invertida) ---
    soma1 = valor1_c1 + valor2_c1;
    soma2 = valor1_c2 + valor2_c2;

    printf("Soma dos valores:\n");
    printf("%s: %.2f\n", carta1.pais, soma1);
    printf("%s: %.2f\n\n", carta2.pais, soma2);

    // --- Determinar vencedor final ---
    int vencedorFinal = (soma1 > soma2) ? 1 : (soma1 < soma2 ? 2 : 0);

    printf("=============================================\n");
    if (vencedorFinal == 1)
        printf("🏆 Resultado Final: %s venceu!\n", carta1.pais);
    else if (vencedorFinal == 2)
        printf("🏆 Resultado Final: %s venceu!\n", carta2.pais);
    else
        printf("🤝 Resultado Final: Empate!\n");

    printf("=============================================\n");

    return 0;
}
