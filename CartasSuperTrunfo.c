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
    unsigned long int populacao1, populacao2;   //População alterada para unsigned long int ---
    float area1, area2;
    float PIB1, PIB2;
    int numerosturisticos1, numeroturisticos2;
    float PBC1, PBC2, DP1, DP2; // PIB Per capita e Densidade Populacional

    float superPoder1, superPoder2; //Variáveis para o Super Poder ---

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

        // NIVEL AVANÇADO 
    // Cálculos de Densidade Populacional e PIB per Capita (já existentes)
    DP1 = (float) populacao1 / area1;
    DP2 = (float) populacao2 / area2;
    PBC1 = PIB1 / (float) populacao1;
    PBC2 = PIB2 / (float) populacao2;
        // NIVEL MESTRE
    //Cálculo do Super Poder ---
    
    // Somando todos os atributos numéricos, com conversão de tipo para garantir precisão
    superPoder1 = (float)populacao1 + area1 + PIB1 + (float)numerosturisticos1 + PBC1 + (1.0f / DP1);
    superPoder2 = (float)populacao2 + area2 + PIB2 + (float)numeroturisticos2 + PBC2 + (1.0f / DP2);


    printf("\n\n--- DADOS DAS CARTAS ---\n");
    //Usando %lu para exibir unsigned long int ---
    printf("- Carta 1 -\n Seu Estado é: %s \n Seu código é: %s \n O nome da cidade é: %s \n A população é de: %lu Habitantes \n A área é de: %.2f Km² \n O PIB é de: R$%.2f \n Numero de pontos turísticos é de: %d\n Densidade Populacional é de: %f Hab/Km²\n PIB Per capita é de: R$%.2f", estado1, codigocarta1, nomecidade1, populacao1, area1, PIB1, numerosturisticos1, DP1, PBC1);
    printf("\n- Carta 2 -\n Seu Estado é: %s \n Seu código é: %s \n O nome da cidade é: %s \n A população é de: %lu Habitantes \n A área é de: %.2f Km² \n O PIB é de: R$%.2f \n Numero de pontos turísticos é de: %d\n Densidade Populacional é de: %f Hab/Km²\n PIB Per capita é de: R$%.2f\n", estado2, codigocarta2, nomecidade2, populacao2, area2, PIB2, numeroturisticos2, DP2, PBC2);


    //Comparação e exibição dos resultados da batalha ---
    printf("\n\n--- COMPARAÇÃO DAS CARTAS ---\n");

    // Para cada atributo, a expressão (carta1 > carta2) resulta em 1 se for verdadeiro e 0 se for falso.
    // Usamos o operador ternário (condição ? valor_se_verdadeiro : valor_se_falso) para imprimir o texto correto.

    printf("População: %s (%d)\n", (populacao1 > populacao2) ? "Carta 1 venceu" : "Carta 2 venceu", (populacao1 > populacao2));
    printf("Área: %s (%d)\n", (area1 > area2) ? "Carta 1 venceu" : "Carta 2 venceu", (area1 > area2));
    printf("PIB: %s (%d)\n", (PIB1 > PIB2) ? "Carta 1 venceu" : "Carta 2 venceu", (PIB1 > PIB2));
    printf("Pontos Turísticos: %s (%d)\n", (numerosturisticos1 > numeroturisticos2) ? "Carta 1 venceu" : "Carta 2 venceu", (numerosturisticos1 > numeroturisticos2));

    // Regra especial para Densidade Populacional: o MENOR valor vence.
    printf("Densidade Populacional: %s (%d)\n", (DP1 < DP2) ? "Carta 1 venceu" : "Carta 2 venceu", (DP1 < DP2));

    printf("PIB per Capita: %s (%d)\n", (PBC1 > PBC2) ? "Carta 1 venceu" : "Carta 2 venceu", (PBC1 > PBC2));
    printf("Super Poder: %s (%d)\n", (superPoder1 > superPoder2) ? "Carta 1 venceu" : "Carta 2 venceu", (superPoder1 > superPoder2));


    return 0;
}
