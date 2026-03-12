#include <stdio.h>
#include <stdlib.h>

int main() {
    int x, y, c;
    scanf("%d %d %d", &x, &y, &c);

    int quadrante_origem;
    int quadrante_destino;

    // Determinar quadrante de origem
    if (x > 0 && y > 0)
        quadrante_origem = 1;
    else if (x < 0 && y > 0)
        quadrante_origem = 2;
    else if (x < 0 && y < 0)
        quadrante_origem = 3;
    else if (x > 0 && y < 0)
        quadrante_origem = 4;
    else {
        printf("caminhada invalida\n");
        return 0;
    }

    // Destino o quadrante diagonal
    if (quadrante_origem == 1)
        quadrante_destino = 3;
    else if (quadrante_origem == 2)
        quadrante_destino = 4;
    else if (quadrante_origem == 3)
        quadrante_destino = 1;
    else
        quadrante_destino = 2;

    // Verificar se o quadrante a evitar realmente adjacente ao de origem
    int adjacente_valido = 0;

    if (quadrante_origem == 1 && (c == 2 || c == 4))
        adjacente_valido = 1;
    else if (quadrante_origem == 2 && (c == 1 || c == 3))
        adjacente_valido = 1;
    else if (quadrante_origem == 3 && (c == 2 || c == 4))
        adjacente_valido = 1;
    else if (quadrante_origem == 4 && (c == 1 || c == 3))
        adjacente_valido = 1;

    if (!adjacente_valido) {
        printf("caminhada invalida\n");
        return 0;
    }

    // Coordenadas reais do destino (posicao (1,1) no quadrante de destino)
    int dest_x, dest_y;

    switch (quadrante_destino) {
        case 1: dest_x =  1; dest_y =  1; break;
        case 2: dest_x = -1; dest_y =  1; break;
        case 3: dest_x = -1; dest_y = -1; break;
        case 4: dest_x =  1; dest_y = -1; break;
    }

    int passos_x = abs(dest_x - x);
    int passos_y = abs(dest_y - y);

    // Determinar ordem dos passos baseado no quadrante evitado
    if (quadrante_origem == 1) {
        if (c == 2)
            printf("%d passos em y e %d passos em x\n", passos_y, passos_x);
        else // c == 4
            printf("%d passos em x e %d passos em y\n", passos_x, passos_y);
    }
    else if (quadrante_origem == 3) {
        if (c == 2)
            printf("%d passos em x e %d passos em y\n", passos_x, passos_y);
        else // c == 4
            printf("%d passos em y e %d passos em x\n", passos_y, passos_x);
    }
    else if (quadrante_origem == 2) {
        if (c == 1)
            printf("%d passos em y e %d passos em x\n", passos_y, passos_x);
        else // c == 3
            printf("%d passos em x e %d passos em y\n", passos_x, passos_y);
    }
    else { // quadrante_origem == 4
        if (c == 1)
            printf("%d passos em x e %d passos em y\n", passos_x, passos_y);
        else // c == 3
            printf("%d passos em y e %d passos em x\n", passos_y, passos_x);
    }

    return 0;
}