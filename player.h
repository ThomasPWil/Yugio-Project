#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "card.h"

typedef struct player {
  char name[50];
  int hp;

  Deck deck;

  MonsterCard hand[5];
  int handCount;

  Queue atkQueue;
  Queue defQueue;
  
} Player;

typedef struct Deck{
  MonsterCard cards[40];
  int top;
}Deck;

typedef struct Queue {
  MonsterCard cards[30];
  int front;
  int rear;
  int size;
} Queue;

Queue *createQueue();

void enqueue(Queue *q, MonsterCard card);

int dequeue(Queue *q, MonsterCard card);


// player structs to be created in player.c
extern Player player1;
extern Player player2;

void populateDecks(Deck deck1, Deck deck2);

Player *makePlayer();

void queueHand();

int getHealth(Player player);

