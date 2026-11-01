#include "card.h"

MonsterCard createCard(char name[], int atk, int def, MonsterType type) {
    MonsterCard card;

    strncpy(card.name, name, 99);
    card.name[99] = '\0';

    card.atk = atk;
    card.def = def;
    card.type = type;

    return card;
}
