#include <stdio.h>
#include <string.h>

#define MAX 1005

char grid[MAX][MAX];
int visited[MAX][MAX];
int dist[MAX][MAX];
int rows, cols;
int sx, sy, ex, ey;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int qx[MAX * MAX];
int qy[MAX * MAX];

void ler_mapa() {
    char dim[20];
    scanf("%s", dim);
    sscanf(dim, "%dx%d", &rows, &cols);

    for (int i = 0; i < rows; i++) {
        scanf("%s", grid[i]);
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 'o') { sx = i; sy = j; }
            if (grid[i][j] == 'd') { ex = i; ey = j; }
        }
    }
}

int valido(int x, int y) {
    return x >= 0 && x < rows && y >= 0 && y < cols
           && !visited[x][y] && grid[x][y] != '#';
}

int bfs() {
    memset(visited, 0, sizeof(visited));
    memset(dist, 0, sizeof(dist));

    int front = 0, back = 0;

    qx[back] = sx;
    qy[back] = sy;
    back++;
    visited[sx][sy] = 1;

    while (front < back) {
        int cx = qx[front];
        int cy = qy[front];
        front++;

        if (cx == ex && cy == ey)
            return dist[cx][cy];

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (valido(nx, ny)) {
                visited[nx][ny] = 1;
                dist[nx][ny] = dist[cx][cy] + 1;
                qx[back] = nx;
                qy[back] = ny;
                back++;
            }
        }
    }

    return -1;
}

void imprimir_resultado(int resultado) {
    if (resultado == -1)
        printf("Poxa... Parece que nao foi dessa vez que Rebeka conseguiu fugir\n");
    else
        printf("Apos correr %d metros e quase desistir por causa da distância, Rebeka conseguiu escapar!\n", resultado);
}

int main() {
    ler_mapa();
    int resultado = bfs();
    imprimir_resultado(resultado);
    return 0;
}