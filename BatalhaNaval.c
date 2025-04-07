#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define MAR 0
#define NAVIO 3

// Função para inicializar o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = MAR;
        }
    }
}

// Função para exibir o tabuleiro na tela
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("   ");
    for (int col = 0; col < TAMANHO_TABULEIRO; col++) {
        printf("%2d ", col);
    }
    printf("\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d ", i);
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para verificar se é possível posicionar um navio horizontalmente
int podeColocarHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) return 0;

    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha][coluna + i] != MAR) return 0;
    }

    return 1;
}

// Função para verificar se é possível posicionar um navio verticalmente
int podeColocarVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO) return 0;

    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna] != MAR) return 0;
    }

    return 1;
}

// Função para posicionar o navio horizontalmente
void posicionarNavioHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha][coluna + i] = NAVIO;
    }
}

// Função para posicionar o navio verticalmente
void posicionarNavioVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna] = NAVIO;
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializa o tabuleiro com 0s (água)
    inicializarTabuleiro(tabuleiro);

    // Coordenadas iniciais definidas no código
    int linhaHorizontal = 2;
    int colunaHorizontal = 4;

    int linhaVertical = 5;
    int colunaVertical = 1;

    // Verifica se os navios podem ser posicionados nas coordenadas especificadas
    if (podeColocarHorizontal(tabuleiro, linhaHorizontal, colunaHorizontal)) {
        posicionarNavioHorizontal(tabuleiro, linhaHorizontal, colunaHorizontal);
    } else {
        printf("Erro ao posicionar navio horizontal!\n");
    }

    if (podeColocarVertical(tabuleiro, linhaVertical, colunaVertical)) {
        posicionarNavioVertical(tabuleiro, linhaVertical, colunaVertical);
    } else {
        printf("Erro ao posicionar navio vertical!\n");
    }

    // Exibe o tabuleiro
    printf("\nTabuleiro de Batalha Naval:\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}
