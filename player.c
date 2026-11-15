#include "player.h"
#include "card.h"

Player player1;
Player player2;

int p1_hp = 8000;
int p2_hp = 8000;

Node *deck_p1;
Node *deck_p2;

queue *p1_hand;
queue *p2_hand;

int deckTotal = 30;

Node* push(Node* deckToPopulate, MonsterCard Mcard)
{
  struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->card = Mcard;
  newNode->next = deckToPopulate;
  
}

Node *createNode(MonsterCard card)
{
  Node *newNode = (Node *)malloc(sizeof(Node));

  if(newNode == NULL)
  {
    return NULL;
  }
  
  newNode->card = card;
  newNode->next = NULL;
  return newNode;
}

int deleteHead(Node **head)
{
  Node *temp = *head;
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

queue *createQueue()
{
  queue *newQueue = (queue *)malloc(sizeof(queue));
  newQueue->front = newQueue->rear = NULL;
  return newQueue;
}

void enqueue(queue* q, MonsterCard card)
{
  Node *newNode = createNode(card);
  if(q->rear == NULL)
  {
    q->front = q->rear = createNode(card);
    return;
  }

  q->rear->next = newNode;
  q->rear = newNode;
}

void queueHand()
{
  // draw 5 cards into player 1 and player 2 hands
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

  //make player hands (will add in later)
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
