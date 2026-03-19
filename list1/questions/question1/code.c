#include <stdio.h>
#include <stdlib.h>


int main() {
    int day_now, month_now, year_now;
    int day_birth, month_birth, year_birth;
    int love, luck, work, color;

    scanf("%d/%d/%d %d/%d/%d", &day_birth, &month_birth, &year_birth, &day_now, &month_now, &year_now);

    love = (day_now + month_now + year_now + day_birth + month_birth + year_birth) * 7 % 101;
    luck = ((day_now + month_now + day_birth + month_birth) * 9 + abs(year_now - year_birth)) % 101;
    work = (year_now + year_birth - (day_now + month_now + day_birth + month_birth) * 8) % 101;
    color = (day_now * day_now + month_now * month_now + year_now * year_now + day_birth * day_birth + month_birth * month_birth + year_birth * year_birth) % 11;

    //love
    printf("Amor: %d%% ", love);

    if (love < 20) {
        printf("Pessimo dia para se apaixonar.");
    }
    else if (love >= 20 && love <= 40) {
        printf("Melhor manter o coracao <3 longe de perigo.");
    }
    else if (love >= 41 && love <= 69) {
        printf("Se o papo e as ideias baterem, esta liberado pensar em algo.");
    }
    else if (love >= 70 && love <= 80) {
        printf("Saia com o coracao aberto, mas lembre, nem toda troca de olhar em onibus e sinal de romance.");
    }
    else {
        printf("Um dia deslumbrantemente lindo para amar. Ps: Cuidado com a intensidade.");
    }
    
    //luck
    printf("\nSorte: %d%% ", luck);

    if (luck < 30) {
        printf("Nem jogue moedas pra cima hoje.");
    }
    else if (luck >= 30 && luck <= 50) {
        printf("Melhor nao arriscar.");
    }
    else if (luck >= 51 && luck <= 79) {
        printf("Por sua conta em risco.");
    }
    else if (luck >= 80 && luck <= 90) {
        printf("Hoje vale a pena arriscar.");
    }
    else {
        printf("Nao tenha medo de virar cartas hoje.");
    }
    
    printf(" Sem tigrinho nem jogos de azar, por favor!");

    //work
    printf("\nTrabalho: %d%% ", work);

    if (work < 40) {
        printf("Hoje nao sera um dia tao proveitoso, keep calm e faca o basico.");
    }
    else if (work >= 40 && work <= 50) {
        printf("Segura a emocao, nao xinga ninguem, nao esquece de beber agua.");
    }
    else if (work >= 51 && work <= 69) {
        printf("Um dia proveitoso com certeza, leve sua simpatia consigo.");
    }
    else if (work >= 70 && work <= 84) {
        printf("Boas vibracoes hoje, chances podem estar ao seu redor.");
    }
    else {
        printf("Use do maximo de networking poss�vel hoje, dia bom para negocios.");
    }

    //color
    printf("\nCor: ");

    switch (color) {
        case 0: printf("Cinza."); break;
        case 1: printf("Vermelho."); break;    
        case 2: printf("Laranja."); break;
        case 3: printf("Amarelo."); break; 
        case 4: printf("Verde."); break;
        case 5: printf("Azul."); break;
        case 6: printf("Roxo."); break;
        case 7: printf("Marrom."); break;
        case 8: printf("Rosa."); break;
        case 9: printf("Preto."); break;
        case 10: printf("Branco."); break;
    }

    return 0;
}