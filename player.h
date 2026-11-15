#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "card.h"

typedef struct Node
{
  MonsterCard card;
  struct Node* next;
  
}Node;

typedef struct player {
  int hp;

  Node *deck;
  
} Player;

Node *createNode(MonsterCard card);

typedef struct Queue
{
  Node* front;
  Node* rear;

}queue;

queue *createQueue();

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

