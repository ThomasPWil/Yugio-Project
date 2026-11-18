#ifndef CARD_H
#define CARD_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct monsterCard {
	char name[100];

	int atk;
	int def;

	char type[50];
}MonsterCard;

MonsterCard makeCard(char name[], int atk, int def, char type[]);

void printCard(MonsterCard card);

int validateCard(MonsterCard card);

int atkBonus(char atkType[], char defType[], MonsterCard card);

int defBonus(char atkType[], char defType[]);

// adding this to quickly retreve atk of a card
int getAtk(MonsterCard card);

// adding this to retreve def of card
int getDef(MonsterCard card);

#endif
