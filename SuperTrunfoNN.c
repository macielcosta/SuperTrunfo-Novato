#include <stdio.h>
#include <locale.h>
#include <string.h>

#define MAX 100

// Estrutura para armazenar os dados da carta
typedef struct {
    char estado;
    char codigo[5]; // Ex: "A01"
    char nomeCidade[MAX];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
} Carta;

void lerCarta(Carta *carta, int numero) {
    printf("\n--- Inserindo dados da Carta %d ---\n", numero);

    printf("Estado (eSCOLHA UMA LETRA ENTRE A e H): ");
    scanf(" %c", &carta->estado); // espaço antes do %c para ignorar caracteres de quebra de linha

    printf("Código da Carta (ex: A01): ");
    scanf("%s", carta->codigo);

    printf("Nome da Cidade: ");
    getchar(); // Limpa o buffer do teclado
    fgets(carta->nomeCidade, MAX, stdin);
    // Remover o caractere de nova linha ao final
    carta->nomeCidade[strcspn(carta->nomeCidade, "\n")] = '\0';

    printf("População: ");
    scanf("%d", &carta->populacao);

    printf("Área (em km²): ");
    scanf("%f", &carta->area);

    printf("PIB (em bilhões de reais): ");
    scanf("%f", &carta->pib);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta->pontosTuristicos);
}

void imprimirCarta(Carta carta, int numero) {
    printf("\n--- Carta %d ---\n", numero);
    printf("Estado: %c\n", carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("Nome da Cidade: %s\n", carta.nomeCidade);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões de reais\n", carta.pib);
    printf("Número de Pontos Turísticos: %d\n", carta.pontosTuristicos);
}

int main() {
    setlocale(LC_ALL, ""); // Configura o uso de acentuação com base no sistema

    Carta carta1, carta2;

    lerCarta(&carta1, 1);
    lerCarta(&carta2, 2);

    imprimirCarta(carta1, 1);
    imprimirCarta(carta2, 2);

    return 0;
}
