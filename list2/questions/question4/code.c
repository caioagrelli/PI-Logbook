#include <stdio.h>

int main() {
    int q;
    scanf("%d", &q);

    int pos = 0;               // coluna atual do cursor
    int drawn_current = 0;     // 0 = ponto atual ainda nao foi desenhado na linha atual
                               // 1 = ponto atual ja existe desenhado

    for (int i = 0; i < q; i++) {
        int x;
        char c;
        scanf("%d %c", &x, &c);

        if (c == 'D') {
            if (drawn_current == 0) {
                // primeiro horizontal da linha: imprime so X pontos
                for (int j = 0; j < pos; j++) {
                    printf(" ");
                }
                for (int j = 0; j < x; j++) {
                    printf(".");
                }
                printf("\n");

                pos = pos + x - 1;
                drawn_current = 1;
            } else {
                // ponto atual ja esta desenhado: inclui ele
                for (int j = 0; j < pos; j++) {
                    printf(" ");
                }
                for (int j = 0; j <= x; j++) {
                    printf(".");
                }
                printf("\n");

                pos = pos + x;
                drawn_current = 1;
            }
        }

        else if (c == 'E') {
            // se ainda nao existe ponto desenhado, so pode ser primeira instrucao
            // e mover para esquerda da origem e invalido
            if (drawn_current == 0) {
                printf("Informacao invalida\n");
                return 0;
            }

            if (pos < x) {
                printf("Informacao invalida\n");
                return 0;
            }

            for (int j = 0; j < pos - x; j++) {
                printf(" ");
            }
            for (int j = 0; j <= x; j++) {
                printf(".");
            }
            printf("\n");

            pos = pos - x;
            drawn_current = 1;
        }

        else if (c == 'B') {
            if (drawn_current == 0) {
                // primeira vez na linha: precisa desenhar X linhas
                for (int j = 0; j < x; j++) {
                    for (int k = 0; k < pos; k++) {
                        printf(" ");
                    }
                    printf(".\n");
                }
                drawn_current = 1;
            } else {
                // ponto atual ja esta desenhado na linha atual
                // entao so imprime as proximas X-1 linhas
                for (int j = 1; j < x; j++) {
                    for (int k = 0; k < pos; k++) {
                        printf(" ");
                    }
                    printf(".\n");
                }
                drawn_current = 1;
            }
        }
    }

    return 0;
}