#include "player.h"
#include "card.h"

Player player1;
Player player2;

int p1_hp = 8000;
int p2_hp = 8000;

Node *deck_p1;
Node *deck_p2;

int deckTotal = 30;

Node* push(Node* deckToPopulate, MonsterCard Mcard)
{
  struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->card = Mcard;
  newNode->next = deckToPopulate;
  
}

int deleteHead(Node **head)
{
  Node *temp = *head
  *head = (*head)->next;
  free(temp);
  return 0;
}

int pop(Node **deck)
{
  deleteHead(deck);
}

void printStack(Node *deck)
{
  Node *temp = deck;
  while(temp != NULL)
  {
    printf("%s -> \n", temp->card.name);
    temp = temp->next;
  }
}

void populateDecks(Node** deck1, Node** deck2)
{
  // use for loop and have an array of cards
  for(int i = 0; i < 30; i++)
  {
    // have array and push first 30 elements into p1 deck
  }

  for(int j = 0; j < 30; j ++)
  {
    // push next 30 into deck
  }

  //push(deckToPopulate,cardTest);
  //push(deckToPopulate,cardTest2);
}

void createPlayers()
{
  player1 = (Player){p1_hp, deck_p1};
  player2 = (Player){p2_hp,deck_p2};
  populateDecks(&deck_p1, &deck_p2);
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
  //createAllCards();
  createPlayers();
  printStack(deck_p1);
  printStack(deck_p2);
  
}
