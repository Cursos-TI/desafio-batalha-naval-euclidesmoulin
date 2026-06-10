#define LINHA 10
#define COLUNA 10

#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Nível Novato + Nível Aventureiro + Nível Mestre

int main() {
    // Tabuleiro 10x10 (0 = água, 3 = navio)
    int CampodeBatalha[LINHA][COLUNA] = {0};
    
    // ===== POSICIONAMENTO DOS NAVIOS =====
    
    // 1. Navio horizontal na linha 2 (índice 1), colunas 1 a 3
    for(int col = 0; col < 3; col++) {
        CampodeBatalha[1][col] = 3;
    }
    
    // 2. Navio vertical na coluna 4 (índice 3), linhas 3 a 5
    for(int linha = 2; linha < 5; linha++) {
        CampodeBatalha[linha][3] = 3;
    }
       
    // 3. Navio diagonal principal (linha e coluna aumentam juntas)
    // Posição: (4,4) até (6,6) - tamanho 3
    for(int i = 0; i < 3; i++) {
        CampodeBatalha[4 + i][4 + i] = 3;
    }
    
    // 4. Navio diagonal secundária (linha aumenta, coluna diminui)
    // Posição: (2,7) até (4,5) - tamanho 3
    for(int i = 0; i < 3; i++) {
        CampodeBatalha[2 + i][7 - i] = 3;
    }
    
    // ===== HABILIDADES ESPECIAIS =====
    
    // Matrizes para armazenar as áreas afetadas por cada habilidade
    int habilidadeCone[LINHA][COLUNA] = {0};
    int habilidadeOctaedro[LINHA][COLUNA] = {0};
    int habilidadeCruz[LINHA][COLUNA] = {0};
    
    // Definindo o ponto central onde as habilidades serão aplicadas (linha 5, coluna 5)
    int centroLinha = 5;
    int centroColuna = 5;
    
    // 1. HABILIDADE EM CONE (apontando para baixo)
    // Padrão 5x5:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    printf("\n=== CRIANDO HABILIDADE EM CONE ===\n");
    for(int i = -2; i <= 2; i++) {
        for(int j = -2; j <= 2; j++) {
            int linha = centroLinha + i;
            int coluna = centroColuna + j;
            
            // Verifica se está dentro dos limites do tabuleiro
            if(linha >= 0 && linha < LINHA && coluna >= 0 && coluna < COLUNA) {
                // Padrão do cone: |i| + |j| <= 2 e i >= 0 (parte inferior)
                if(i >= 0 && (i + abs(j)) <= 2) {
                    habilidadeCone[linha][coluna] = 1;
                }
            }
        }
    }
    
    // 2. HABILIDADE EM OCTAEDRO (diamante/ losango)
    // Padrão 5x5:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0
    printf("\n=== CRIANDO HABILIDADE EM OCTAEDRO ===\n");
    for(int i = -2; i <= 2; i++) {
        for(int j = -2; j <= 2; j++) {
            int linha = centroLinha + i;
            int coluna = centroColuna + j;
            
            // Verifica se está dentro dos limites do tabuleiro
            if(linha >= 0 && linha < LINHA && coluna >= 0 && coluna < COLUNA) {
                // Padrão do octaedro: |i| + |j| <= 2 e (|i| + |j|) % 2 == 0 (alternado)
                if((abs(i) + abs(j)) <= 2 && (abs(i) + abs(j)) % 2 == 0) {
                    habilidadeOctaedro[linha][coluna] = 1;
                }
            }
        }
    }
    
    // 3. HABILIDADE EM CRUZ
    // Padrão 5x5:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0
    printf("\n=== CRIANDO HABILIDADE EM CRUZ ===\n");
    for(int i = -2; i <= 2; i++) {
        for(int j = -2; j <= 2; j++) {
            int linha = centroLinha + i;
            int coluna = centroColuna + j;
            
            // Verifica se está dentro dos limites do tabuleiro
            if(linha >= 0 && linha < LINHA && coluna >= 0 && coluna < COLUNA) {
                // Padrão da cruz: mesma linha OU mesma coluna
                if(i == 0 || j == 0) {
                    habilidadeCruz[linha][coluna] = 1;
                }
            }
        }
    }
    
    // ===== EXIBIÇÃO DAS COORDENADAS DOS NAVIOS =====
    
    printf("\n=== COORDENADAS DOS NAVIOS ===\n\n");
    
    printf("Navio Horizontal (linha 2, colunas A a C):\n");
    for(int col = 0; col < 3; col++) {
        printf("  (1, %c)\n", 'A' + col);
    }
    
    printf("\nNavio Vertical (coluna D, linhas 3 a 5):\n");
    for(int linha = 2; linha < 5; linha++) {
        printf("  (%d, D)\n", linha);
    }
    
    printf("\nNavio Diagonal Principal (linha e coluna aumentam juntas):\n");
    for(int i = 0; i < 3; i++) {
        printf("  (%d, %c)\n", 4 + i, 'A' + 4 + i);
    }
    
    printf("\nNavio Diagonal Secundária (linha aumenta, coluna diminui):\n");
    for(int i = 0; i < 3; i++) {
        printf("  (%d, %c)\n", 2 + i, 'A' + 7 - i);
    }
    
    // ===== EXIBIÇÃO DO TABULEIRO COM NAVIOS =====
    
    printf("\n=== TABULEIRO COMPLETO COM NAVIOS (%dx%d) ===\n", LINHA, COLUNA);
    printf("     ");
    for(int j = 0; j < COLUNA; j++) {
        printf(" %c ", 'A' + j);
    }
    printf("\n     ");
    for(int j = 0; j < COLUNA; j++) {
        printf("---");
    }
    printf("\n");
    
    for(int i = 0; i < LINHA; i++) {
        printf("  %d  |", i);
        for(int j = 0; j < COLUNA; j++) {
            if(CampodeBatalha[i][j] == 3) {
                printf(" 3 ");
            } else {
                printf(" 0 ");
            }
        }
        printf("\n");
    }
    
    // ===== EXIBIÇÃO DAS HABILIDADES =====
    
    printf("\n=== HABILIDADE: CONE (centro na linha %d, coluna %c) ===\n", centroLinha, 'A' + centroColuna);
    printf("     ");
    for(int j = 0; j < COLUNA; j++) {
        printf(" %c ", 'A' + j);
    }
    printf("\n     ");
    for(int j = 0; j < COLUNA; j++) {
        printf("---");
    }
    printf("\n");
    
    for(int i = 0; i < LINHA; i++) {
        printf("  %d  |", i);
        for(int j = 0; j < COLUNA; j++) {
            printf(" %d ", habilidadeCone[i][j]);
        }
        printf("\n");
    }
    
    printf("\n=== HABILIDADE: OCTAEDRO (centro na linha %d, coluna %c) ===\n", centroLinha, 'A' + centroColuna);
    printf("     ");
    for(int j = 0; j < COLUNA; j++) {
        printf(" %c ", 'A' + j);
    }
    printf("\n     ");
    for(int j = 0; j < COLUNA; j++) {
        printf("---");
    }
    printf("\n");
    
    for(int i = 0; i < LINHA; i++) {
        printf("  %d  |", i);
        for(int j = 0; j < COLUNA; j++) {
            printf(" %d ", habilidadeOctaedro[i][j]);
        }
        printf("\n");
    }
    
    printf("\n=== HABILIDADE: CRUZ (centro na linha %d, coluna %c) ===\n", centroLinha, 'A' + centroColuna);
    printf("     ");
    for(int j = 0; j < COLUNA; j++) {
        printf(" %c ", 'A' + j);
    }
    printf("\n     ");
    for(int j = 0; j < COLUNA; j++) {
        printf("---");
    }
    printf("\n");
    
    for(int i = 0; i < LINHA; i++) {
        printf("  %d  |", i);
        for(int j = 0; j < COLUNA; j++) {
            printf(" %d ", habilidadeCruz[i][j]);
        }
        printf("\n");
    }
    
    // ===== SIMULAÇÃO DE ATAQUE COMBINADO =====
    
    printf("\n=== SIMULAÇÃO: TABULEIRO APÓS ATAQUE COM HABILIDADE CRUZ ===\n");
    printf("(Áreas afetadas: 1 | Navios atingidos: 3 | Água: 0)\n");
    printf("     ");
    for(int j = 0; j < COLUNA; j++) {
        printf(" %c ", 'A' + j);
    }
    printf("\n     ");
    for(int j = 0; j < COLUNA; j++) {
        printf("---");
    }
    printf("\n");
    
    for(int i = 0; i < LINHA; i++) {
        printf("  %d  |", i);
        for(int j = 0; j < COLUNA; j++) {
            if(CampodeBatalha[i][j] == 3 && habilidadeCruz[i][j] == 1) {
                printf(" X "); // Navio atingido
            } else if(CampodeBatalha[i][j] == 3) {
                printf(" 3 "); // Navio não atingido
            } else if(habilidadeCruz[i][j] == 1) {
                printf(" ~ "); // Água afetada
            } else {
                printf(" 0 "); // Água não afetada
            }
        }
        printf("\n");
    }
    
    // ===== LEGENDA =====
    printf("\n=== LEGENDA ===\n");
    printf("0 = Água / Posição vazia\n");
    printf("3 = Navio\n");
    printf("1 = Área afetada pela habilidade (no tabuleiro de habilidades)\n");
    printf("X = Navio atingido (simulação)\n");
    printf("~ = Água afetada (simulação)\n");
    printf("\nColunas: ");
    for(int j = 0; j < COLUNA; j++) {
        printf("%c=%d ", 'A' + j, j);
        if(j < COLUNA - 1) printf("| ");
    }
    printf("\n");
    printf("\nCentro das habilidades: Linha %d, Coluna %c (%d)\n", centroLinha, 'A' + centroColuna, centroColuna);
    
    return 0;
}

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