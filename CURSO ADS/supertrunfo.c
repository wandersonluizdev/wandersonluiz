#include <stdio.h>

int main(){

    // CRIANDO CIDADE 01

    char estado1[3], codigocarta1[4], nomecidade1[50]; // char do modo string - %c ou %s 
    int populacao1, pontosturisticos1; // variaveis inteiras - %d
    float area1, pib1; // flutuante - %f

    // Cadastrando Cartas Cidade 01

    printf("Código da Carta: ");
    scanf("%s", codigocarta1);  

    printf("Estado: ");
    scanf("%s", estado1);    

    printf("Nome da Cidade: ");
    scanf("%s" , nomecidade1);

    printf("Populacao: ");
    scanf("%d", &populacao1);

    printf("Area: ");
    scanf("%f", area1);

    printf("PIB: ");
    scanf("%f", pib1);

    printf("Pontos Turisticos: ");
    scanf("%d", pontosturisticos1);

    // EXIBIÇÃO DAS CARTAS 01

    
    printf("Código da Carta: %s\n", codigocarta1);
    printf("Estado: %s\n", estado1);
    printf("Nome da Cidade: %s\n", nomecidade1);
    printf("Populacao: %d\n", populacao1);
    printf("Area: %.2f\n", area1);
    printf("PIB: %.2f\n", pib1);
    printf("Pontos Turisticos: %d\n", pontosturisticos1);



 // CRIANDO CIDADE 02

    char estado2[3], codigocarta2[4], nomecidade2[50]; // char do modo string - %c ou %s 
    int populacao2, pontosturisticos2; // variaveis inteiras - %d
    float area2, pib2; // flutuante - %f

 // Cadastrando Cartas Cidade 02

    printf("Código da Carta: ");
    scanf("%s", codigocarta2);  

    printf("Estado: ");
    scanf("%s", estado2);    

    printf("Nome da Cidade: ");
    scanf("%s" , nomecidade2);

    printf("Populacao: ");
    scanf("%d", populacao2);

    printf("Area: ");
    scanf("%f", area2);

    printf("PIB: ");
    scanf("%f", pib2);

    printf("Pontos Turisticos: ");
    scanf("%d", pontosturisticos2);

// EXIBIÇÃO DAS CARTAS 02

    printf("Código da Carta: %s\n", codigocarta2);
    printf("Estado: %s\n", estado2);
    printf("Nome da Cidade: %s\n", nomecidade2);
    printf("Populacao: %d\n", populacao2);
    printf("Area: %.2f\n", area2);
    printf("PIB: %.2f\n", pib2);
    printf("Pontos Turisticos: %d\n", pontosturisticos2);

    return 0;
}