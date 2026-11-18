#include "card.h"

MonsterCard makeCard(char name[], int atk, int def, char type[]) {
    MonsterCard card;
    strcpy(card.name, name);
    
    card.atk = atk;
    card.def = def;

    strcpy(card.type, type);

    return card;
}

void printCard(MonsterCard card) {
    char nameCap[100];
    strcpy(nameCap, card.name);

    int i = 0;
    nameCap[i] = toupper((unsigned char)nameCap[i]);
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


int validateCard(MonsterCard card) {
    if (strlen(card.name) == 0)
        return 0;
    if (card.atk < 0)
        return 0;
    if (card.def < 0)
        return 0;
    if (strlen(card.type) == 0)
        return 0;

    return 1;
}

int atkBonus(char atkType[], char defType[])
{
    // will have 3 types fire,water and grass

    //if strong against a type it does double damage
    if(strcmp(atkType, "Fire") == 0 && strcmp(defType, "Grass") == 0)
    {
      return 1;
    }

    if(strcmp(atkType, "Water") == 0 && strcmp(defType, "Fire") == 0)
    {
      return 1;
    }

    if(strcmp(atkType, "Grass") == 0 && strcmp(defType, "Water") == 0)
    {
      return 1;
    }

    return 0;
}

int defBonus(char atkType[], char defType[]) {
    //if weak against a type it does half damage

    if(strcmp(atkType, "Fire") == 0 && strcmp(defType, "Water") == 0)
    {
      return 1;
    }

    if(strcmp(atkType, "Water") == 0 && strcmp(defType, "Grass") == 0)
    {
      return 1;
    }

    if(strcmp(atkType, "Grass") == 0 && strcmp(defType, "Fire") == 0)
    {
      return 1;
    }

    return 0;
}

int getAtk(MonsterCard card)
{
    return card.atk;
}

int getDef(MonsterCard card)
{
    return card.def;
}

