#include <stdio.h>
#include <string.h> // Biblioteca para a função strcspn

//função para limpar o buffer de entrada.
// Essencial ao misturar scanf com fgets.
void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    // Variaveis para o código funcionar
    char estado1[50], estado2[50];
    char codigocarta1[5], codigocarta2[5]; // Em char pois ira conter letras e numeros
    char nomecidade1[50], nomecidade2[50];
    int populacao1, populacao2;
    float area1, area2;
    float PIB1, PIB2;
    int numerosturisticos1, numeroturisticos2;

    printf("--- Preenchendo a Carta 1 ---\n");

    printf("Digite o 1º estado que deseja: ");
    // Usando fgets para ler a linha inteira, incluindo espaços
    fgets(estado1, 50, stdin);
    // fgets guarda o '\n' (Enter) no final, por isso colocar a função abaixo para subistituir \n por 0
    estado1[strcspn(estado1, "\n")] = 0;

    printf("Digite o 1º código da carta (ex: A01, B03): ");
    scanf("%s", codigocarta1);
    limpar_buffer(); // Limpa o '\n' deixado pelo scanf

    printf("Digite o 1º nome da cidade: ");
    fgets(nomecidade1, 50, stdin);
    nomecidade1[strcspn(nomecidade1, "\n")] = 0;

    printf("Digite a 1º População total: ");
    scanf("%d", &populacao1);
    limpar_buffer(); // Limpa o '\n'

    printf("Digite a Área da 1º Carta: ");
    scanf("%f", &area1);
    limpar_buffer(); // Limpa o '\n'

    printf("Digite o PIB da 1º Carta: ");
    scanf("%f", &PIB1);
    limpar_buffer(); // Limpa o '\n'

    printf("Digite a quantidade de pontos turísticos da 1º carta: ");
    scanf("%d", &numerosturisticos1);
    limpar_buffer(); // Limpa o '\n'

    printf("\n--- Preenchendo a Carta 2 ---\n");

    printf("Digite o 2º estado que deseja: ");
    fgets(estado2, 50, stdin);
    estado2[strcspn(estado2, "\n")] = 0;

    printf("Digite o 2º código da carta (ex: A01, B03): ");
    scanf("%s", codigocarta2);
    limpar_buffer();

    printf("Digite o 2º nome da cidade: ");
    fgets(nomecidade2, 50, stdin);
    nomecidade2[strcspn(nomecidade2, "\n")] = 0;

    printf("Digite a 2º População total: ");
    scanf("%d", &populacao2);
    limpar_buffer();

    printf("Digite a Área da 2º Carta: ");
    scanf("%f", &area2);
    limpar_buffer();

    printf("Digite o PIB da 2º Carta: ");
    scanf("%f", &PIB2);
    limpar_buffer();

    printf("Digite a quantidade de pontos turísticos da 2º carta: ");
    scanf("%d", &numeroturisticos2);
    limpar_buffer();

    printf("\n\n--- DADOS DAS CARTAS ---\n");
    printf("- Carta 1 -\n Seu Estado é: %s \n Seu código é: %s \n O nome da cidade é: %s \n A população é de: %d Habitantes \n A área é de: %.2f m² \n O PIB é de: R$%.2f \n Numero de pontos turísticos é de: %d\n", estado1, codigocarta1, nomecidade1, populacao1, area1, PIB1, numerosturisticos1); // Retorna a mensagem confirmando os dados da 1º carta
    printf("\n- Carta 2 -\n Seu Estado é: %s \n Seu código é: %s \n O nome da cidade é: %s \n A população é de: %d Habitantes \n A área é de: %.2f m² \n O PIB é de: R$%.2f \n Numero de pontos turísticos é de: %d\n", estado2, codigocarta2, nomecidade2, populacao2, area2, PIB2, numeroturisticos2); // Retorna a mensagem confirmando os dados da 2º carta

    return 0;
}
