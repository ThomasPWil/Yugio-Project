#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "player.h"
#include <stdbool.h>
#include <math.h>

void declareWinner();

void coinFlip();

void handleBattle(MonsterCard card1,MonsterCard card2);

void LPCalculations(int *currLP, int damage);

//used for if one player activated an attack card and another activated a defense card
int getDamage1Atk(int atk, int def, Player *player);

int getDamage2Atk(int atk1,int atk2);

void endBattle();

int displayTurnMenu(MonsterCard hand[5], Player *player);

void removeAtIndex(MonsterCard hand[5], Player *player, int index);

void removeBattleCards(Queue *q);

void printCurrentBattleData();

extern bool p1First;

extern bool p2First;



