#include <stdio.h>

int main() {
    long long N, A, B;
    long long amount, sa, sb, sab, response;
    long long qa, qb, qab;

    scanf("%lld", &N);
    scanf("%lld %lld", &A, &B);

    amount = N * (N + 1) / 2;

    qa = N / A;
    qb = N / B;
    qab = N / (A * B);

    sa = A * qa * (qa + 1) / 2;
    sb = B * qb * (qb + 1) / 2;
    sab = (A * B) * qab * (qab + 1) / 2;

    response = amount - sa - sb + sab;

    printf("%lld\n", response);

    if (response % 2 == 0) {
        printf("Lá ele!!!\n");
    } else {
        printf("Opa xupenio AULAS...\n");
    }

    return 0;
} 