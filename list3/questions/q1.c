#include <stdio.h>

int main () {
    int n; 
    scanf("%d", &n); // numero de entradas

    for (int i = 0; i < n; i++) { // for de cada uma das entradas
        int amount;  
        scanf("%d", &amount); // quantidade de numeros a ser enviada

        int numbers[amount]; // vetor dos numeros 
        int order = 1; // numeros atual da sequencia decrescente
        int best_order = 0; // numero da melhor sequencia decrescente
        int best_init; // inicio da melhor sequencia
        int init = 0; // inicio da sequencia atual
        int end_sequence = 0; // final da melhor sequencia

        for (int j = 0; j < amount; j++) { // loop para percorrer todos os numeors do vetor 
            scanf("%d", &numbers[j]); 
            if (j > 0 && numbers[j] < numbers[j - 1]) { // verificar se ta na ordem decrescente (n pode ser o numero inicial)
                order++; // caso for coloca mais um na ordem atual
                end_sequence = j; // e coloca ele como o final da sequencia
            } else {
                order = 1; // caso for maior reinicia 
                init = j;  // o inicio vira o numero atual
            }

            if (order > best_order) { // caso a ordem atual for a maior ja vista
                best_order = order; // atualiza o numero de termos
                best_init = init; // coloca o melhor inicio (pode se repetir)
                end_sequence = j; //coloca o melhor final (pode se repetir)
            }
        }
        
        // print final 
        if (best_order != 1) { // verificar se n teve ordem decrescente 
            printf("%d\n", best_order); } else {
                printf("0"); // caso n teve printa 0 (se n printaria 1)
            }
        for (int j = best_init; j <= end_sequence; j++) {
            if (best_order != 1) {  // se n teve sequencia n printa
                if (j == best_init){
                    printf("%d", numbers[j]); // para o inicial n ter espaços 
                } else {
                    printf(" %d", numbers[j]);  // para o final ter espaços
                }
            }
        }
        printf("\n"); // pula a linha pra receber o proximo 

    }

    return 0;
}