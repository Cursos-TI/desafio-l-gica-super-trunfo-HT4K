#include <stdio.h>
#include <string.h>

// Estrutura representando uma carta do Super Trunfo
struct Carta {
    char estado[30];
    char codigo[10];
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade;
    float pib_per_capita;
};

// Função que calcula dados derivados: densidade e PIB per capita
void calcularDados(struct Carta *c) {
    c->densidade = c->populacao / c->area;
    c->pib_per_capita = (c->pib * 1e9) / c->populacao; // PIB em reais por pessoa
}

// Função para imprimir os dados de uma carta
void exibirCarta(struct Carta c) {
    printf("Cidade: %s (%s)\n", c.nome, c.estado);
    printf("População: %d\n", c.populacao);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: R$ %.2f bilhões\n", c.pib);
    printf("Pontos turísticos: %d\n", c.pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km²\n", c.densidade);
    printf("PIB per capita: R$ %.2f\n", c.pib_per_capita);
    printf("-----------------------------\n");
}

int main() {
    // Cadastro fixo de duas cartas
    struct Carta carta1 = {"SP", "C001", "São Paulo", 12300000, 1521.0, 750.0, 20};
    struct Carta carta2 = {"RJ", "C002", "Rio de Janeiro", 6718903, 1182.3, 360.0, 15};

    // Cálculo dos dados derivados
    calcularDados(&carta1);
    calcularDados(&carta2);

    // Exibir cartas cadastradas
    printf("=== CARTA 1 ===\n");
    exibirCarta(carta1);
    printf("=== CARTA 2 ===\n");
    exibirCarta(carta2);

    // ESCOLHA DO ATRIBUTO PARA COMPARAÇÃO (modifique conforme necessário)
    // Atributo: População
    printf("\nComparação de cartas (Atributo: População):\n\n");
    printf("Carta 1 - %s (%s): %d\n", carta1.nome, carta1.estado, carta1.populacao);
    printf("Carta 2 - %s (%s): %d\n", carta2.nome, carta2.estado, carta2.populacao);

    // Comparação usando if
    if (carta1.populacao > carta2.populacao) {
        printf("\nResultado: Carta 1 (%s) venceu!\n", carta1.nome);
    } else if (carta1.populacao < carta2.populacao) {
        printf("\nResultado: Carta 2 (%s) venceu!\n", carta2.nome);
    } else {
        printf("\nResultado: Empate!\n");
    }

    return 0;
}
