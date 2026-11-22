#include "player.h"
#include "card.h"

Player player1;
Player player2;

int p1_hp = 8000;
int p2_hp = 8000;

int deckTotal = 30;

Deck deck_p1;
Deck deck_p2;

FILE *cards;

MonsterCard cardArr[60] = {};

Queue *createQueue() { //creates and initializes queue
    Queue *newQueue = malloc(sizeof(Queue));
    
    if(newQueue == NULL) {
        printf("Memory Allocation Failed\n");
        return NULL;
    }

    newQueue->front = 0;
    newQueue->rear = -1;
    newQueue->size = 0;
    
    return newQueue;
}

int isEmpty(Queue *q) { //checks if a queue is empty
    return q->size == 0;
}

int isFull(Queue *q) { //checks if a queue is full
    return q->size ==30;
}

void enqueue(Queue* q, MonsterCard card) {
    if (q->size == 30) {
        printf("Queue is full!\n");
        return;
    }

    q->rear = (q->rear + 1) % 30;
    q->cards[q->rear] = card;
    q->size++;
}

MonsterCard dequeue(Queue *q) {
    MonsterCard card;

    if(q->size == 0) {
        printf("Queue is empty!\n");
        return card;
    }

    card = q->cards[q->front];
    q->front = (q->front + 1) %30;
    q->size--;

    return card;
}

void queueHand() {
  // draw 5 cards into player 1 and player 2 hands
}

int handleCardFile() {
  cards = fopen("cards.txt", "r");
  char buffer[100];

  char name[100];
  int attack;
  int defense;
  char type[100];

  int curr = 0;
  
  if(cards == NULL)
  {
    printf("could not find cards file");
    return 0;
  }
  
  while (curr < 30 && fscanf(cards, "%s %d %d %s", name, &attack, &defense, type) == 4) {
      cardArr[curr] = makeCard(name, attack, defense, type);
      curr++;
  }

    fclose(cards);
    return curr;
}

void populateDeck(Deck *deck)
{
  int numCards = handleCardFile();
  // use for loop and have an array of cards
  for(int i = 0; i < numCards; i++)
  {
    deck->cards[i] = cardArr[i];
  }

  for(int j = 31; j < 60; j ++)
  {
    // push next 30 into deck
  }

   deck->top = numCards;
}

void createPlayers()
{
  player1 = (Player){"Player1",p1_hp, deck_p1, 5, createQueue(), createQueue()};
  player2 = (Player){"Player2",p2_hp, deck_p2, 5, createQueue(), createQueue()};
  populateDeck(&deck_p1);
  populateDeck(&deck_p2);

  //make player hands (will add in later)
}

