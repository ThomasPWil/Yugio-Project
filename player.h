#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "card.h"

typedef struct Node
{
  int data;
  struct Node* next;
  
}Node;

typedef struct player {
  int hp;

  node *deck;
  
} Player;


// player structs to be created in player.c
extern Player player1;
extern Player player2;

void populateDecks(node** deckToPopulate);

void createPlayers();

int getP1_Health();

int getP2_Health();


