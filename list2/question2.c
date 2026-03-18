#include <stdio.h>

int main() {
    int n, k, p;
    scanf("%d %d %d", &n, &k, &p);

    int primeiro = -1;
    int q = 0;

    for (int i = n; i < k; i++) {
        int x = i;
        int cont = 0;
        int valido = 1;

        if (x == 0) {
            valido = 0;
        } else {
            while (x % 2 == 0 && x > 0) {
                x /= 2;
            }

            for (int d = 3; d * d <= x; d += 2) {
                int vezes = 0;

                while (x % d == 0) {
                    x /= d;
                    vezes++;
                }

                if (vezes > 1) {
                    valido = 0;
                    break;
                }

                if (vezes == 1) {
                    cont++;
                }
            }

            if (valido && x > 1) {
                cont++;
            }
        }

        if (valido && cont == p) {
            if (primeiro == -1) {
                primeiro = i;
            } else {
                q++;
            }
        }
    }

    if (primeiro == -1) {
        printf("Poxa dudinha, me desculpa, nao achei os numeros mas vou te mandar uma foto de um gatinho fofo.\n");
    } else {
        printf("%d %d\n", primeiro, q);
    }

    return 0;
}