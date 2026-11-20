#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void declareWinner();

void coinFlip();

void handleBattle(MonsterCard card1,MonsterCard card2);

void LPCalculations(int currLP, int damage);

//used for if one player activated an attack card and another activated a defense card
int getDamage1Atk(int atk, int def);

int getDamage2Atks(int atk1,int atk2);

void endBattle();

void displayTurnMenu();
