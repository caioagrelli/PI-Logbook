#include <stdio.h>

#define TAM 4
#define MOVIMENTOS 20

/* Inicializa a matriz com zeros */
void inicializar_matriz(int matriz[TAM][TAM]) {
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            matriz[i][j] = 0;
}

/* Imprime a matriz (�til para depura��o) */
void imprimir_matriz(int matriz[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++)
            printf("%d ", matriz[i][j]);
        printf("\n");
    }
}

/* Aplica um movimento e atualiza a posi��o de Pedro */
void mover(char direcao, int *linha, int *col) {
    if (direcao == 'c' && *linha - 1 >= 0)  (*linha)--;
    if (direcao == 'b' && *linha + 1 < TAM) (*linha)++;
    if (direcao == 'e' && *col  - 1 >= 0)  (*col)--;
    if (direcao == 'd' && *col  + 1 < TAM) (*col)++;
}

/* Encontra a c�lula mais visitada e retorna suas coordenadas */
void encontrar_mais_visitada(int matriz[TAM][TAM], int *res_linha, int *res_col) {
    int max = 0;
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (matriz[i][j] > max) {
                max = matriz[i][j];
                *res_linha = i;
                *res_col   = j;
            }
        }
    }
}

int main(void) {
    int matriz[TAM][TAM];
    inicializar_matriz(matriz);

    int linha = 0, col = 0;
    char direcao;

    /* Conta a posi��o inicial */
    matriz[linha][col]++;

    /* L� e processa os 20 movimentos */
    for (int i = 0; i < MOVIMENTOS; i++) {
        scanf(" %c", &direcao);
        mover(direcao, &linha, &col);
        matriz[linha][col]++;
    }

    /* Encontra a c�lula mais visitada */
    int res_linha = 0, res_col = 0;
    encontrar_mais_visitada(matriz, &res_linha, &res_col);

    /* X = coluna, Y = linha (conforme enunciado) */
    printf("Coordenada X:%d, Y:%d\n", res_col, res_linha);

    return 0;
}