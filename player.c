#include "player.h"
#include "card.h"


Player player1;
Player player2;

int p1_hp = 8000;
int p2_hp = 8000;

Node *deck_p1;
Node *deck_p2;

Node* push(Node* deckToPopulate, MonsterCard Mcard)
{
  struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->card = Mcard;
  newNode->next = deckToPopulate;
  
}

void printStack(Node *deck)
{
  Node *temp = deck_p1;
  while(temp != NULL)
  {
    printf("%s -> \n", temp->card.name);
    temp = temp->next;
  }
}

void populateDecks(node** deckToPopulate)
{
  // add cards to deck stack
  push(deckToPopulate,cardTest);
  push(deckToPopulate,cardTest2);
}

void createPlayers()
{
  player1 = (Player){8000, deck_p1};
  populateDecks(&deck_p1);
 
  player2 = (Player){8000,deck_p2};
  populateDecks(&deck_p2);
}

int getP1_Health()
{
  return player1.hp;
}

int getP2_Health()
{
  return player2.hp;
}

void main()
{
  createAllCards();
  createPlayers();
  printStack(&deck_p1);
  
}

