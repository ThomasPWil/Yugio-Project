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

