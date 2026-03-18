#include <stdio.h>

int main() {
    int n, k, p;
    scanf("%d %d %d", &n, &k, &p);

    int primeiro = -1;
    int q = 0;

    for (int i = n; i < k; i++) {
        int x = i;
        int cont = 0; // numero que caem no msm caso, o q no caso 
        int valido = 1; // se o numero nao for valido é 0

        if (x == 0) { // 0 nao é considerado um numero primo e ia dar pau na regra
            valido = 0;
        } else { // 
            while (x % 2 == 0 && x > 0) { // loop pra remover todos os 2, ja que 2 e o unico primo par 
                x /= 2;
            }

            for (int d = 3; d * d <= x; d += 2) { // o resultado da divisao (ou n por dois)
                int vezes = 0;

                while (x % d == 0) { // verificar os primos 
                    x /= d; // dividir 
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