#include "card.h"

MonsterCard makeCard(char name[], int atk, int def, char type[]) {
    MonsterCard card;

    strncpy(card.name, name, 99);
    card.name[99] = '\0';

    card.atk = atk;
    card.def = def;
    card.type = type;

    return card;
}

void printCard(MonsterCard card) {
    char nameCap[] = card.name;
    int i = 0;
    str[i] = toupper((unsigned char)str[i]);
    while(nameCap[i]) {
        nameCap[i] = toupper((unsigned char)nameCap[i]);
        i++;
    }
    printf("NAME: %s\n", nameCap);
    printf("ATK: %d\n", card.atk);
    printf("DEF: %d\n", card.def);
    printf("TYPE: %s\n", card.type);
    printf("\n");
}
