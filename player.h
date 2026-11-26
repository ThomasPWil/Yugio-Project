#ifndef PLAYER_H
#define PLAYER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "card.h"

typedef struct Deck{
  MonsterCard cards[30];
  int top;
}Deck;

typedef struct Queue {
  MonsterCard cards[30];
  int front;
  int rear;
  int size;
} Queue;

typedef struct player {
  char name[50];
  int hp;

  Deck deck;

  MonsterCard hand[5];
  int handCount;

  Queue atkQueue;
  Queue defQueue;
  
} Player;


Queue *createQueue();

int isEmpty(Queue *q);

int isFull(Queue *q);

void enqueue(Queue *q, MonsterCard card);

MonsterCard dequeue(Queue *q);

void queueHand(Player *player);

void drawCard(Player *player);

int handleCardFile();

void populateDeck(Deck *deck);

void createPlayers();





// player structs to be created in player.c
extern Player player1;
extern Player player2;


#endif
