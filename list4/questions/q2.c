#include <stdio.h>
#include <string.h>

#define MAX 105

/* L� a matriz da parede */
void ler_matriz(int m, int n, char parede[MAX][MAX]) {
    for (int i = 0; i < m; i++) {
        scanf("%s", parede[i]);
    }
}

/* Imprime a matriz da parede */
void imprimir_matriz(int m, char parede[MAX][MAX]) {
    for (int i = 0; i < m; i++) {
        printf("%s\n", parede[i]);
    }
}

/* Declara��o antecipada (necess�ria por recurs�o m�tua) */
void simular_agua(int m, int n, char parede[MAX][MAX], int linha, int col);

/*
 * Desliza a �gua horizontalmente sobre uma linha at� atingir
 * a borda da prateleira, marcando 'o' no caminho, e ent�o chama
 * simular_agua a partir da c�lula al�m da borda.
 *
 * sentido: -1 = esquerda, +1 = direita
 */
void deslizar(int m, int n, char parede[MAX][MAX], int linha, int col, int sentido) {
    int c = col;
    while (c >= 0 && c < n) {
        if (parede[linha][c] == '.') parede[linha][c] = 'o';

        /* Verifica se a pr�xima c�lula na mesma dire��o ainda tem prateleira abaixo */
        int prox = c + sentido;
        if (prox < 0 || prox >= n || parede[linha + 1][prox] != '#') {
            /* Chegou � borda da prateleira; cai daqui */
            simular_agua(m, n, parede, linha, prox);
            return;
        }
        c = prox;
    }
}

/*
 * Simula a queda da �gua a partir de (linha, col).
 * A �gua cai verticalmente. Ao encontrar uma prateleira abaixo,
 * desliza para AMBOS os lados da prateleira e cai pelas duas extremidades.
 */
void simular_agua(int m, int n, char parede[MAX][MAX], int linha, int col) {
    /* Fora dos limites horizontais: para */
    if (col < 0 || col >= n) return;

    /* Marca posi��o atual */
    if (parede[linha][col] == '.') parede[linha][col] = 'o';

    /* Chegou ao ch�o */
    if (linha + 1 >= m) return;

    char abaixo = parede[linha + 1][col];

    if (abaixo == '.' || abaixo == 'o') {
        /* Continua caindo livremente */
        simular_agua(m, n, parede, linha + 1, col);
    } else if (abaixo == '#') {
        /*
         * Encontrou prateleira: desliza para a esquerda E para a direita
         * a partir da linha atual, caindo em ambas as extremidades.
         */
        deslizar(m, n, parede, linha, col, -1); /* esquerda */
        deslizar(m, n, parede, linha, col, +1); /* direita  */
    }
}

int main(void) {
    int m, n;
    char parede[MAX][MAX];

    scanf("%d %d", &m, &n);
    ler_matriz(m, n, parede);

    /* Encontra a gota inicial (aceita 'o' ou 'O') */
    int col_inicial = -1, linha_inicial = -1;
    for (int i = 0; i < m && linha_inicial == -1; i++) {
        for (int j = 0; j < n; j++) {
            if (parede[i][j] == 'O') parede[i][j] = 'o';
            if (parede[i][j] == 'o' && linha_inicial == -1) {
                linha_inicial = i;
                col_inicial   = j;
            }
        }
    }

    if (linha_inicial != -1)
        simular_agua(m, n, parede, linha_inicial, col_inicial);

    imprimir_matriz(m, parede);
    return 0;
}