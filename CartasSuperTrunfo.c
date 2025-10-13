//-----------------------------------------------------------------------------------------//
#include <stdio.h>
#include <string.h> // Biblioteca para a função strcpy e strcspn
#include <stdlib.h> // Biblioteca para a função exit()
//-----------------------------------------------------------------------------------------//

// Função para limpar o buffer de entrada.
// Essencial ao misturar scanf com fgets.
void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    // --- Variáveis das Cartas ---
    char estado1[50], estado2[50];
    char codigocarta1[5], codigocarta2[5];
    char nomecidade1[50], nomecidade2[50];
    unsigned long int populacao1, populacao2;
    float area1, area2;
    float PIB1, PIB2;
    int numerosturisticos1, numeroturisticos2;
    float DP1, DP2; // Densidade Populacional

    // --- Variáveis para a Lógica do Jogo ---
    int escolha1 = 0, escolha2 = 0; // Armazena a escolha dos atributos
    char nome_atributo1[50], nome_atributo2[50]; // Armazena o nome dos atributos escolhidos
    float valor_attr1_carta1 = 0, valor_attr1_carta2 = 0; // Valores do 1º atributo
    float valor_attr2_carta1 = 0, valor_attr2_carta2 = 0; // Valores do 2º atributo
    float soma_carta1, soma_carta2; // Soma dos atributos para cada carta

    // --- Bloco de Cadastro das Cartas (pode ser substituído por valores fixos) ---
    printf("--- Preenchendo a Carta 1 ---\n");
    printf("Digite o 1º país que deseja: ");
    fgets(estado1, 50, stdin);
    estado1[strcspn(estado1, "\n")] = 0;

    printf("Digite a 1º População total: ");
    scanf("%lu", &populacao1);
    limpar_buffer();

    printf("Digite a Área da 1º Carta (em Km²): ");
    scanf("%f", &area1);
    limpar_buffer();

    printf("Digite o PIB da 1º Carta: ");
    scanf("%f", &PIB1);
    limpar_buffer();

    printf("Digite a quantidade de pontos turísticos da 1º carta: ");
    scanf("%d", &numerosturisticos1);
    limpar_buffer();

    printf("\n--- Preenchendo a Carta 2 ---\n");
    printf("Digite o 2º país que deseja: ");
    fgets(estado2, 50, stdin);
    estado2[strcspn(estado2, "\n")] = 0;

    printf("Digite a 2º População total: ");
    scanf("%lu", &populacao2);
    limpar_buffer();

    printf("Digite a Área da 2º Carta (em Km²): ");
    scanf("%f", &area2);
    limpar_buffer();

    printf("Digite o PIB da 2º Carta: ");
    scanf("%f", &PIB2);
    limpar_buffer();

    printf("Digite a quantidade de pontos turísticos da 2º carta: ");
    scanf("%d", &numeroturisticos2);
    limpar_buffer();
    // ------------------------------------------------------------------------------------

    // --- Cálculos ---
    // Evita divisão por zero se a área for 0
    DP1 = (area1 > 0) ? ((float)populacao1 / area1) : 0;
    DP2 = (area2 > 0) ? ((float)populacao2 / area2) : 0;

    // --- Exibição dos Dados das Cartas ---
    printf("\n\n--- DADOS DAS CARTAS ---\n");
    printf("- Carta 1 (%s) -\n População: %lu\n Área: %.2f Km²\n PIB: R$%.2f\n Pontos turísticos: %d\n Densidade: %.2f Hab/Km²\n", estado1, populacao1, area1, PIB1, numerosturisticos1, DP1);
    printf("\n- Carta 2 (%s) -\n População: %lu\n Área: %.2f Km²\n PIB: R$%.2f\n Pontos turísticos: %d\n Densidade: %.2f Hab/Km²\n", estado2, populacao2, area2, PIB2, numeroturisticos2, DP2);

//-----------------------------------------------------------------------------------------//

    // --- Menu para Escolha do PRIMEIRO Atributo ---
    printf("\n\n--- ESCOLHA O PRIMEIRO ATRIBUTO PARA COMPARAR ---\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Número de Pontos Turísticos\n");
    printf("5. Densidade Demográfica (menor valor vence na comparação individual)\n");
    printf("Digite sua escolha (1-5): ");
    scanf("%d", &escolha1);
    limpar_buffer();

    // Processa a primeira escolha
    switch (escolha1) {
        case 1: strcpy(nome_atributo1, "População"); valor_attr1_carta1 = (float)populacao1; valor_attr1_carta2 = (float)populacao2; break;
        case 2: strcpy(nome_atributo1, "Área"); valor_attr1_carta1 = area1; valor_attr1_carta2 = area2; break;
        case 3: strcpy(nome_atributo1, "PIB"); valor_attr1_carta1 = PIB1; valor_attr1_carta2 = PIB2; break;
        case 4: strcpy(nome_atributo1, "Pontos Turísticos"); valor_attr1_carta1 = (float)numerosturisticos1; valor_attr1_carta2 = (float)numeroturisticos2; break;
        case 5: strcpy(nome_atributo1, "Densidade Demográfica"); valor_attr1_carta1 = DP1; valor_attr1_carta2 = DP2; break;
        default: printf("\nErro: Opção inválida! Encerrando o programa.\n"); return 1; // Encerra se a opção for inválida
    }

    // --- Menu para Escolha do SEGUNDO Atributo ---
    printf("\n\n--- ESCOLHA O SEGUNDO ATRIBUTO (DIFERENTE DO PRIMEIRO) ---\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Número de Pontos Turísticos\n");
    printf("5. Densidade Demográfica (menor valor vence na comparação individual)\n");
    printf("Digite sua escolha (1-5): ");
    scanf("%d", &escolha2);
    limpar_buffer();

    // Validação para garantir que o segundo atributo é diferente do primeiro
    if (escolha1 == escolha2) {
        printf("\nErro: Você não pode escolher o mesmo atributo duas vezes! Encerrando o programa.\n");
        return 1; // Encerra o programa
    }

    // Processa a segunda escolha
    switch (escolha2) {
        case 1: strcpy(nome_atributo2, "População"); valor_attr2_carta1 = (float)populacao1; valor_attr2_carta2 = (float)populacao2; break;
        case 2: strcpy(nome_atributo2, "Área"); valor_attr2_carta1 = area1; valor_attr2_carta2 = area2; break;
        case 3: strcpy(nome_atributo2, "PIB"); valor_attr2_carta1 = PIB1; valor_attr2_carta2 = PIB2; break;
        case 4: strcpy(nome_atributo2, "Pontos Turísticos"); valor_attr2_carta1 = (float)numerosturisticos1; valor_attr2_carta2 = (float)numeroturisticos2; break;
        case 5: strcpy(nome_atributo2, "Densidade Demográfica"); valor_attr2_carta1 = DP1; valor_attr2_carta2 = DP2; break;
        default: printf("\nErro: Opção inválida! Encerrando o programa.\n"); return 1; // Encerra se a opção for inválida
    }

    // --- Cálculo da Soma dos Atributos ---
    soma_carta1 = valor_attr1_carta1 + valor_attr2_carta1;
    soma_carta2 = valor_attr1_carta2 + valor_attr2_carta2;

    // --- Exibição Clara do Resultado ---
    printf("\n\n================ RESULTADO DA RODADA ================\n");
    printf("Países em disputa: %s vs %s\n", estado1, estado2);
    printf("--------------------------------------------------\n");
    printf("Atributos escolhidos: %s e %s\n\n", nome_atributo1, nome_atributo2);

    // Detalhes da comparação individual
    printf("Comparação Individual:\n");
    printf("-> %s:\n   - Carta 1 (%s): %.2f\n   - Carta 2 (%s): %.2f\n", nome_atributo1, estado1, valor_attr1_carta1, estado2, valor_attr1_carta2);
    printf("-> %s:\n   - Carta 1 (%s): %.2f\n   - Carta 2 (%s): %.2f\n", nome_atributo2, estado1, valor_attr2_carta1, estado2, valor_attr2_carta2);
    printf("--------------------------------------------------\n");

    // Soma e resultado final
    printf("Cálculo Final (Soma dos Atributos):\n");
    printf("-> Soma Carta 1 (%s): %.2f\n", estado1, soma_carta1);
    printf("-> Soma Carta 2 (%s): %.2f\n\n", estado2, soma_carta2);

    // Lógica para determinar o vencedor com base na soma
    if (soma_carta1 > soma_carta2) {
        printf("VENCEDOR: Carta 1 (%s) vence com a maior soma!\n", estado1);
    } else if (soma_carta2 > soma_carta1) {
        printf("VENCEDOR: Carta 2 (%s) vence com a maior soma!\n", estado2);
    } else {
        printf("RESULTADO: Empate! As somas são iguais.\n");
    }
    printf("===================================================\n");
//-----------------------------------------------------------------------------------------//
// --- FIM DA SEÇÃO NOVA ---
//-----------------------------------------------------------------------------------------//

    return 0;
}
