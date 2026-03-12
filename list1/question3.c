#include <stdio.h>

int main() {
    int total, px, py, pz;
    scanf("%d %d %d %d", &total, &px, &py, &pz);

    int investido = 0;
    int encontrou = 0;
    int A, B, C, sobra;
    int nt;

    // Tenta sem investir
    if ((total * px) % 100 == 0 && (total * py) % 100 == 0 && (total * pz) % 100 == 0) {
        A = total * px / 100;
        B = total * py / 100;
        C = total * pz / 100;
        sobra = total - A - B - C;
        investido = 0;
        encontrou = 1;
    }
    // Tenta investir 1 real
    else if (((total + 1) * px) % 100 == 0 && ((total + 1) * py) % 100 == 0 && ((total + 1) * pz) % 100 == 0) {
        nt = total + 1;
        A = nt * px / 100;
        B = nt * py / 100;
        C = nt * pz / 100;
        sobra = nt - A - B - C;
        if (sobra > 1) {
            investido = 1;
            encontrou = 1;
        }
    }
    // Tenta investir 2 reais
    else if (((total + 2) * px) % 100 == 0 && ((total + 2) * py) % 100 == 0 && ((total + 2) * pz) % 100 == 0) {
        nt = total + 2;
        A = nt * px / 100;
        B = nt * py / 100;
        C = nt * pz / 100;
        sobra = nt - A - B - C;
        if (sobra > 2) {
            investido = 2;
            encontrou = 1;
        }
    }
    // Tenta investir 3 reais
    else if (((total + 3) * px) % 100 == 0 && ((total + 3) * py) % 100 == 0 && ((total + 3) * pz) % 100 == 0) {
        nt = total + 3;
        A = nt * px / 100;
        B = nt * py / 100;
        C = nt * pz / 100;
        sobra = nt - A - B - C;
        if (sobra > 3) {
            investido = 3;
            encontrou = 1;
        }
    }

    int dinheiro_rebeka;

    if (encontrou) {
        printf("Cada homem ficou com %d, %d e %d reais, respectivamente\n", A, B, C);
        dinheiro_rebeka = 3 - investido + sobra;
    } else {
        printf("Nao foi dessa vez que Rebeka pode ajudar...\n");
        dinheiro_rebeka = 3;
    }

    // Prova de contas
    if (investido == 2) {
        char c1, c2, c3;
        scanf(" %c %c %c", &c1, &c2, &c3);
        int soma = (c1 - 'a' + 1) + (c2 - 'a' + 1) + (c3 - 'a' + 1);
        printf("%d\n", soma);
    } else if (investido == 3) {
        int i1, i2, i3;
        scanf("%d %d %d", &i1, &i2, &i3);

        int parcelas = 0;
        if (i1 % 3 == 0) parcelas += i1 / 3;
        if (i2 % 3 == 0) parcelas += i2 / 3;
        if (i3 % 3 == 0) parcelas += i3 / 3;

        if (i1 % 3 == 0 || i2 % 3 == 0 || i3 % 3 == 0)
            printf("%d\n", parcelas);
    }

    if (dinheiro_rebeka >= 7)
        printf("Ela conseguiu! Rebeka voltou para casa e apanhou da mae por sumir noite passada!\n");
    else
        printf("E parece que Rebeka vai ter que voltar andando...\n");

    return 0;
}