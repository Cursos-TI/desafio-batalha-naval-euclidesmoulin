#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Campo de batalha 5x5 (0 = água, 3 = navio)
    int CampodeBatalha[5][5] = {0};
    
    // Posicionar navio horizontal na linha 2 (índice 1), colunas 1 a 3
    // Navio de tamanho 3
    for(int col = 0; col < 3; col++) {
        CampodeBatalha[1][col] = 3;
    }
    
    // Posiciona o navio vertical na coluna 4 (índice 3), linhas 3 a 5
    // Navio de tamanho 3
    for(int linha = 2; linha < 5; linha++) {
        CampodeBatalha[linha][3] = 3;
    }
    
    // Exibindo as coordenadas de cada parte dos navios
    printf("Coordenadas do Navio Horizontal (linha 2, colunas 1 a 3):\n");
    for(int col = 0; col < 3; col++) {
        printf("  (1, %d)\n", col);
    }
    
    printf("\nCoordenadas do Navio Vertical (coluna 4, linhas 3 a 5):\n");
    for(int linha = 2; linha < 5; linha++) {
        printf("  (%d, 3)\n", linha);
    }
    
    // Exibir o campo de batalha completo (3 = navio, 0 = água)
    printf("\nCampo de Batalha completo:\n");
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            printf("%d ", CampodeBatalha[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
 
    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

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