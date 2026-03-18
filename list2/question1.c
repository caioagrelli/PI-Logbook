    #include <stdio.h>

    int main () {
        char letter;
        scanf("%c", &letter);

        int n = letter - 'A';

        for (int i = 0; i <= n; i++) {

            // points init
            for (int j = 0; j < n - i; j++) {
                printf(".");
            }

            // growing
            for (int j = 0; j <= i; j++) {
                printf("%c", 'A' + j);
            }

            // descending
            for (int j = i - 1; j >= 0; j--) {
                printf("%c", 'A' + j);
            }

            // points end
            for (int j = 0; j < n - i; j++) {
                printf(".");
            }

            printf("\n");
        }
    return 0;
    }