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

void enqueue(queue *q, MonsterCard card);

int dequeue(queue *q, MonsterCard card);


// player structs to be created in player.c
extern Player player1;
extern Player player2;

void populateDecks(Node** deck1, Node** deck2);

void createPlayers();

void queueHand();

int getP1_Health();

int getP2_Health();

