#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.


    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Nível Novato + Nível Aventureiro

int main() {
    // Tabuleiro 10x10 (0 = água, 3 = navio)
    int CampodeBatalha[10][10] = {0};
    
    // 1. Navio horizontal na linha 2 (índice 1), colunas 1 a 3
    for(int col = 0; col < 3; col++) {
        CampodeBatalha[1][col] = 3;
    }
    
    // 2. Navio vertical na coluna 4 (índice 3), linhas 3 a 5
    for(int linha = 2; linha < 5; linha++) {
        CampodeBatalha[linha][3] = 3;
    }
       
    // 3. Navio diagonal principal (linha e coluna aumentam juntas)
    // Posição: (4,4) até (7,7) - tamanho 3
    for(int i = 0; i < 3; i++) {
        CampodeBatalha[4 + i][4 + i] = 3;
    }
    
    // 4. Navio diagonal secundária (linha aumenta, coluna diminui)
    // Posição: (2,7) até (5,4) - tamanho 3
    for(int i = 0; i < 3; i++) {
        CampodeBatalha[2 + i][7 - i] = 3;
    }
    
    // ===== EXIBIÇÃO DAS COORDENADAS =====
    
    printf("=== COORDENADAS DOS NAVIOS ===\n\n");
    
    // Navio Horizontal
    printf("Navio Horizontal (linha 2, colunas A a C):\n");
    for(int col = 0; col < 3; col++) {
        printf("  (1, %c)\n", 'A' + col);
    }
    
    // Navio Vertical
    printf("\nNavio Vertical (coluna D, linhas 3 a 5):\n");
    for(int linha = 2; linha < 5; linha++) {
        printf("  (%d, D)\n", linha);
    }
    
    // Navio Diagonal Principal
    printf("\nNavio Diagonal Principal (linha e coluna aumentam juntas):\n");
    for(int i = 0; i < 3; i++) {
        printf("  (%d, %c)\n", 4 + i, 'A' + 4 + i);
    }
    
    // Navio Diagonal Secundária
    printf("\nNavio Diagonal Secundária (linha aumenta, coluna diminui):\n");
    for(int i = 0; i < 3; i++) {
        printf("  (%d, %c)\n", 2 + i, 'A' + 7 - i);
    }
    
    // ===== EXIBIÇÃO DO TABULEIRO COMPLETO =====
    
    printf("\n=== TABULEIRO 10x10 ===\n");
    printf("     ");
    for(int j = 0; j < 10; j++) {
        printf(" %c ", 'A' + j);
    }
    printf("\n     ");
    for(int j = 0; j < 10; j++) {
        printf("---");
    }
    printf("\n");
    
    for(int i = 0; i < 10; i++) {
        printf("  %d  |", i);
        for(int j = 0; j < 10; j++) {
            printf("%2d ", CampodeBatalha[i][j]);
        }
        printf("\n");
    }
    
    // ===== LEGENDA =====
    printf("\n=== LEGENDA ===\n");
    printf("0 = Água / Posição vazia\n");
    printf("3 = Navio\n");
    printf("\nColunas: A=0, B=1, C=2, D=3, E=4, F=5, G=6, H=7, I=8, J=9\n");
    
    return 0;
}

     // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0