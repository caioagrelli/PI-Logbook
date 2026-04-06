#include <stdio.h>

int main() {
    int N, X, Y;
    scanf("%d %d %d", &N, &X, &Y);

    int latas[N + 1];

    // Inicializa todo mundo com 0 lata
    for (int i = 1; i <= N; i++) {
        latas[i] = 0;
    }

    // Clientes m�ltiplos de X compram 1 lata por padr�o
    if (X != 0) {
        for (int i = X; i <= N; i += X) {
            latas[i] = 1;
        }
    }

    // L� os clientes que compraram mais de 1 lata
    for (int i = 0; i < Y; i++) {
        int h, m, z;
        scanf("%d:%d %d", &h, &m, &z);

        // Descobre qual cliente foi atendido nesse hor�rio
        int minutos = (h - 7) * 60 + m;
        int cliente = minutos / 3;

        latas[cliente] = z;
    }

    int soma = 0;
    int vencedor = -1;
    int comprou = 0;

    // Procura quem levou a 50� lata
    for (int i = 1; i <= N; i++) {
        if (soma < 50 && soma + latas[i] >= 50) {
            vencedor = i;
            comprou = latas[i];
            break;
        }
        soma += latas[i];
    }

    if (vencedor == -1) {
        int faltam = 50 - soma;
        printf("Ainda nao foram vendidas latas suficientes. Faltam %d latas.\n", faltam);
    } else {
        int totalMin = 7 * 60 + vencedor * 3;
        int hh = totalMin / 60;
        int mm = totalMin % 60;

        printf("Quem levou a cesta basica foi o %d* cliente atendido por coragem, as %02d:%02d. Que comprou %d %s.\n",
               vencedor, hh, mm, comprou, (comprou == 1 ? "lata" : "latas"));
    }

    return 0;
}