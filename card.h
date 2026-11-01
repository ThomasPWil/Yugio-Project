#ifndef CARD_H
#define CARD_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct monsterCard {
	char name[100];

	int atk;
	int def;

	char type[50];
}MonsterCard;

MonsterCard makeCard(char name[], int atk, int def, char type[]);

void printCard(MonsterCard card);

void validateCard(MonsterCard card);

int atkBonus(char atkType[], char defType[]);

int defBonus(char atkType[], char defType[]);


#endif
