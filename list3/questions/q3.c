#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_STR 102
#define MAX_WORD_LEN 101

int main() {
    char s[MAX_STR];
    char w1[MAX_WORD_LEN], w2[MAX_WORD_LEN];
    int total_pairs = 0;
    int n = 0; // numero de palavras
    int i, j, k;

    fgets(s, MAX_STR, stdin);
    int len = strlen(s);

    // --- Contar palavras ---
    int in_word = 0;
    for (i = 0; i <= len; i++) {
        if (i < len && isalpha((unsigned char)s[i])) {
            if (!in_word) { in_word = 1; n++; }
        } else {
            in_word = 0;
        }
    }

    // --- Primeira passagem: contar pares de anagramas ---
    int idx_i, idx_j;
    int start, wlen;

    for (idx_i = 0; idx_i < n; idx_i++) {

        // Extrair palavra idx_i -> w1
        int count = 0;
        in_word = 0;
        for (i = 0; i <= len; i++) {
            if (i < len && isalpha((unsigned char)s[i])) {
                if (!in_word) { in_word = 1; start = i; }
            } else {
                if (in_word) {
                    if (count == idx_i) {
                        wlen = i - start;
                        for (k = 0; k < wlen; k++)
                            w1[k] = tolower((unsigned char)s[start + k]);
                        w1[wlen] = '\0';
                    }
                    count++;
                    in_word = 0;
                }
            }
        }

        for (idx_j = idx_i + 1; idx_j < n; idx_j++) {

            // Extrair palavra idx_j -> w2
            count = 0;
            in_word = 0;
            for (i = 0; i <= len; i++) {
                if (i < len && isalpha((unsigned char)s[i])) {
                    if (!in_word) { in_word = 1; start = i; }
                } else {
                    if (in_word) {
                        if (count == idx_j) {
                            wlen = i - start;
                            for (k = 0; k < wlen; k++)
                                w2[k] = tolower((unsigned char)s[start + k]);
                            w2[wlen] = '\0';
                        }
                        count++;
                        in_word = 0;
                    }
                }
            }

            // Verificar anagrama
            int freq[26] = {0};
            int anagrama = 1;
            if (strlen(w1) != strlen(w2)) {
                anagrama = 0;
            } else {
                for (k = 0; w1[k] != '\0'; k++) freq[(unsigned char)w1[k] - 'a']++;
                for (k = 0; w2[k] != '\0'; k++) freq[(unsigned char)w2[k] - 'a']--;
                for (k = 0; k < 26; k++)
                    if (freq[k] != 0) { anagrama = 0; break; }
            }

            if (anagrama) total_pairs++;
        }
    }

    // --- Sa?da ---
    if (total_pairs == 0) {
        printf("Nao existem anagramas na frase.\n");
    } else {
        printf("Pares de anagramas encontrados:\n");

        for (idx_i = 0; idx_i < n; idx_i++) {

            // Extrair palavra idx_i -> w1
            int count = 0;
            in_word = 0;
            for (i = 0; i <= len; i++) {
                if (i < len && isalpha((unsigned char)s[i])) {
                    if (!in_word) { in_word = 1; start = i; }
                } else {
                    if (in_word) {
                        if (count == idx_i) {
                            wlen = i - start;
                            for (k = 0; k < wlen; k++)
                                w1[k] = tolower((unsigned char)s[start + k]);
                            w1[wlen] = '\0';
                        }
                        count++;
                        in_word = 0;
                    }
                }
            }

            for (idx_j = idx_i + 1; idx_j < n; idx_j++) {

                // Extrair palavra idx_j -> w2
                count = 0;
                in_word = 0;
                for (i = 0; i <= len; i++) {
                    if (i < len && isalpha((unsigned char)s[i])) {
                        if (!in_word) { in_word = 1; start = i; }
                    } else {
                        if (in_word) {
                            if (count == idx_j) {
                                wlen = i - start;
                                for (k = 0; k < wlen; k++)
                                    w2[k] = tolower((unsigned char)s[start + k]);
                                w2[wlen] = '\0';
                            }
                            count++;
                            in_word = 0;
                        }
                    }
                }

                // Verificar anagrama
                int freq[26] = {0};
                int anagrama = 1;
                if (strlen(w1) != strlen(w2)) {
                    anagrama = 0;
                } else {
                    for (k = 0; w1[k] != '\0'; k++) freq[(unsigned char)w1[k] - 'a']++;
                    for (k = 0; w2[k] != '\0'; k++) freq[(unsigned char)w2[k] - 'a']--;
                    for (k = 0; k < 26; k++)
                        if (freq[k] != 0) { anagrama = 0; break; }
                }

                if (anagrama)
                    printf("%s e %s\n", w1, w2);
            }
        }

        printf("\nTotal de pares: %d\n", total_pairs);
    }

    return 0;
}