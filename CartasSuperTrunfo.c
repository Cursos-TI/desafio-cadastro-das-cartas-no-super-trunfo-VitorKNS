//-----------------------------------------------------------------------------------------//
#include <stdio.h>
#include <string.h> // Biblioteca para a função strcspn
//-----------------------------------------------------------------------------------------//
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
    unsigned long int populacao1, populacao2;   //População alterada para unsigned long int ---
    float area1, area2;
    float PIB1, PIB2;
    int numerosturisticos1, numeroturisticos2;
    float PBC1, PBC2, DP1, DP2; // PIB Per capita e Densidade Populacional

    printf("--- Preenchendo a Carta 1 ---\n");
    printf("Digite o 1º estado que deseja: ");
    fgets(estado1, 50, stdin);
    estado1[strcspn(estado1, "\n")] = 0;

    printf("Digite o 1º código da carta (ex: A01, B03): ");
    scanf("%s", codigocarta1);
    limpar_buffer();

    printf("Digite o 1º nome da cidade: ");
    fgets(nomecidade1, 50, stdin);
    nomecidade1[strcspn(nomecidade1, "\n")] = 0;

    printf("Digite a 1º População total: ");
    scanf("%lu", &populacao1); //Usando %lu para ler unsigned long int ---
    limpar_buffer();

    printf("Digite a Área da 1º Carta: ");
    scanf("%f", &area1);
    limpar_buffer();

    printf("Digite o PIB da 1º Carta: ");
    scanf("%f", &PIB1);
    limpar_buffer();

    printf("Digite a quantidade de pontos turísticos da 1º carta: ");
    scanf("%d", &numerosturisticos1);
    limpar_buffer();

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
    scanf("%lu", &populacao2); //Usando %lu para ler unsigned long int ---
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
//-----------------------------------------------------------------------------------------//
    // Cálculos de Densidade Populacional e PIB per Capita
    DP1 = (float) populacao1 / area1;
    DP2 = (float) populacao2 / area2;
    PBC1 = PIB1 / (float) populacao1;
    PBC2 = PIB2 / (float) populacao2;
//-----------------------------------------------------------------------------------------//
    printf("\n\n--- DADOS DAS CARTAS ---\n");
    //Usando %lu para exibir unsigned long int ---
    printf("- Carta 1 -\n Seu Estado é: %s \n Seu código é: %s \n O nome da cidade é: %s \n A população é de: %lu Habitantes \n A área é de: %.2f Km² \n O PIB é de: R$%.2f \n Numero de pontos turísticos é de: %d\n Densidade Populacional é de: %.2f Hab/Km²\n PIB Per capita é de: R$%.2f\n", estado1, codigocarta1, nomecidade1, populacao1, area1, PIB1, numerosturisticos1, DP1, PBC1);
    printf("\n- Carta 2 -\n Seu Estado é: %s \n Seu código é: %s \n O nome da cidade é: %s \n A população é de: %lu Habitantes \n A área é de: %.2f Km² \n O PIB é de: R$%.2f \n Numero de pontos turísticos é de: %d\n Densidade Populacional é de: %.2f Hab/Km²\n PIB Per capita é de: R$%.2f\n", estado2, codigocarta2, nomecidade2, populacao2, area2, PIB2, numeroturisticos2, DP2, PBC2);


//-----------------------------------------------------------------------------------------//
    printf("\n\n--- Comparação de cartas (Atributo: População) ---\n");

    // 2. Exibição dos valores que serão comparados
    printf("Carta 1 - %s (%s): %lu\n", nomecidade1, estado1, populacao1);
    printf("Carta 2 - %s (%s): %lu\n", nomecidade2, estado2, populacao2);

    if (populacao1 > populacao2) {
        printf("Resultado: Carta 1 (%s) venceu!\n", nomecidade1);
    } else if (populacao2 > populacao1) {
        printf("Resultado: Carta 2 (%s) venceu!\n", nomecidade2);
    } else {
        printf("Resultado: Empate!\n");
    }
//-----------------------------------------------------------------------------------------//

    return 0;
}
