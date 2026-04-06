#include <stdio.h>
#include <string.h>

#define MAX_LED 61
#define MAX_GIANT 100000

int main() {
    int R;
    scanf("%d", &R);

    char results[1000][MAX_LED]; // estado final de cada teste
    int r;

    for (r = 0; r < R; r++) {
        char s[MAX_LED];
        int F;
        scanf("%s %d", s, &F);

        int n = strlen(s);
        int i, c;

        // Simular F clocks
        for (c = 0; c < F; c++) {
            // LED 0 sempre troca
            if (s[0] == 'X') s[0] = 'O';
            else             s[0] = 'X';

            // Cascata: se o led anterior ficou X (desligado), o pr�ximo troca
            for (i = 1; i < n; i++) {
                if (s[i-1] == 'X') {
                    if (s[i] == 'X') s[i] = 'O';
                    else             s[i] = 'X';
                } else {
                    break; // led anterior est� ligado, para a cascata
                }
            }
        }

        // Guardar resultado e imprimir
        strcpy(results[r], s);
        printf("%s\n", s);
    }

    // Montar a luz gigante
    char giant[MAX_GIANT];
    int giant_len = 0;
    int i;

    // Copiar primeiro fio
    for (i = 0; results[0][i] != '\0'; i++)
        giant[giant_len++] = results[0][i];

    // Anexar os demais com ornamento
    for (r = 1; r < R; r++) {
        char last  = giant[giant_len - 1];
        char first = results[r][0];
        char ornament;

        if (giant_len % 2 == 0) {
            // tamanho par
            if (last == first) ornament = '@';
            else               ornament = '$';
        } else {
            // tamanho impar
            if (last == first) ornament = '#';
            else               ornament = '%';
        }

        giant[giant_len++] = ornament;

        for (i = 0; results[r][i] != '\0'; i++)
            giant[giant_len++] = results[r][i];
    }

    giant[giant_len] = '\0';
    printf("%s\n", giant);

    return 0;
}