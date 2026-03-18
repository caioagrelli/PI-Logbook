#include <stdio.h>

int main() {
    int x, n;
    scanf("%d", &x);
    scanf("%d", &n);

    int melhor_canal = -1;
    int melhor_minuto = -1;
    long long melhor_termo = -1;
    int melhor_distancia = -1;

    for (int c = 1; c <= n; c++) {
        long long f1, f2;
        scanf("%lld %lld", &f1, &f2);

        // Apenas 3 variaveis para percorrer a sequencia
        long long ant2 = f1;  // f(i-2)
        long long ant1 = f2;  // f(i-1)

        // Verifica distancia do primeiro termo
        int dist = (int)(ant2 - x);
        if (dist < 0) dist = -dist;
        int melhor_dist_canal = dist;
        long long melhor_termo_canal = ant2;
        int melhor_minuto_canal = 1;

        // Verifica distancia do segundo termo
        dist = (int)(ant1 - x);
        if (dist < 0) dist = -dist;
        if (dist < melhor_dist_canal) {
            melhor_dist_canal = dist;
            melhor_termo_canal = ant1;
            melhor_minuto_canal = 2;
        }

        // Gera e verifica os proximos termos ate passar x
        int minuto = 3;
        long long atual = ant2 + ant1;

        while (atual <= x) {
            dist = (int)(atual - x);
            if (dist < 0) dist = -dist;
            if (dist < melhor_dist_canal) {
                melhor_dist_canal = dist;
                melhor_termo_canal = atual;
                melhor_minuto_canal = minuto;
            }
            ant2 = ant1;
            ant1 = atual;
            atual = ant2 + ant1;
            minuto++;
        }

        // Verifica o primeiro termo que passou x
        dist = (int)(atual - x);
        if (dist < 0) dist = -dist;
        if (dist < melhor_dist_canal) {
            melhor_dist_canal = dist;
            melhor_termo_canal = atual;
            melhor_minuto_canal = minuto;
        }

        // Empate entre canais: pega o de indice maior (por isso <=)
        if (melhor_distancia == -1 || melhor_dist_canal <= melhor_distancia) {
            melhor_distancia = melhor_dist_canal;
            melhor_canal = c;
            melhor_minuto = melhor_minuto_canal;
            melhor_termo = melhor_termo_canal;
        }
    }

    // Verifica VIP: soma dos algarismos do melhor termo > 10
    int soma = 0;
    long long numero = melhor_termo;
    while (numero > 0) {
        soma += numero % 10;
        numero /= 10;
    }

    if (soma > 10) {
        printf("Xupenio, para ir ao lulupalooza vc deve entrar no canal %d e sera chamado mais ou menos no minuto %d e com o VIP garantido!!!\n", melhor_canal, melhor_minuto);
    } else {
        printf("Xupenio, para ir ao lulupalooza vc deve entrar no canal %d e sera chamado mais ou menos no minuto %d, mas o ingresso VIP n�o vai rolar :(\n", melhor_canal, melhor_minuto);
    }

    return 0;
}