#include <stdio.h>

int main() {

    long long N, A, B;
    long long total, somaA, somaB, somaAB, resposta;
    long long qtdA, qtdB, qtdAB;
    long long mmc;

    scanf("%lld", &N);
    scanf("%lld %lld", &A, &B);

    // soma de 1 ate N
    total = N * (N + 1) / 2;

    // multiplos de A
    qtdA = N / A;
    somaA = A * qtdA * (qtdA + 1) / 2;

    // multiplos de B
    qtdB = N / B;
    somaB = B * qtdB * (qtdB + 1) / 2;

    // mmc (como A e B sao primos)
    if (A == B) {
        mmc = A;
    } else {
        mmc = A * B;
    }

    qtdAB = N / mmc;
    somaAB = mmc * qtdAB * (qtdAB + 1) / 2;

    resposta = total - somaA - somaB + somaAB;

    printf("%lld\n", resposta);

    if (resposta % 2 == 0) {
        printf("Lá ele!!!");
    }
    else {
        printf("Opa xupenio AULAS...");
    }

    return 0;
}