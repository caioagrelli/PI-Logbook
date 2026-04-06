#include <stdio.h>

#define MAX 105

void ler_matriz(int m, int n, char mat[MAX][MAX]) {
    for (int i = 0; i < m; i++)
        scanf("%s", mat[i]);
}

void imprimir_matriz(int m, char mat[MAX][MAX]) {
    for (int i = 0; i < m; i++)
        printf("%s\n", mat[i]);
}

/* Tenta marcar a posi��o (i,j) com o caractere c, respeitando as regras */
void marcar(int m, int n, char mat[MAX][MAX], int i, int j, char c) {
    /* Fora dos limites ou � um poste: ignora */
    if (i < 0 || i >= m || j < 0 || j >= n) return;
    if (mat[i][j] == 'P') return;

    /* '+' tem prioridade sobre 'x' */
    if (mat[i][j] == '+') return;          /* j� tem '+', n�o muda */
    if (c == '+') mat[i][j] = '+';        /* '+' sempre sobrescreve '-' e 'x' */
    else if (mat[i][j] == '-') mat[i][j] = c; /* 'x' s� entra em posi��o vazia */
}

/* Aplica os enfeites de todos os postes */
void aplicar_enfeites(int m, int n, char mat[MAX][MAX]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 'P') {
                /* Ortogonais: '+' */
                marcar(m, n, mat, i-1, j,   '+');
                marcar(m, n, mat, i+1, j,   '+');
                marcar(m, n, mat, i,   j-1, '+');
                marcar(m, n, mat, i,   j+1, '+');
                /* Diagonais: 'x' */
                marcar(m, n, mat, i-1, j-1, 'x');
                marcar(m, n, mat, i-1, j+1, 'x');
                marcar(m, n, mat, i+1, j-1, 'x');
                marcar(m, n, mat, i+1, j+1, 'x');
            }
        }
    }
}

int main(void) {
    int m, n;
    char mat[MAX][MAX];

    scanf("%d %d", &m, &n);
    ler_matriz(m, n, mat);
    aplicar_enfeites(m, n, mat);
    imprimir_matriz(m, mat);

    return 0;
}