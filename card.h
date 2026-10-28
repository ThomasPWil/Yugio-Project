#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct monsterCard {
  char mName[100];

  int atk;
  int def;

  char type[50];

} Card;

typedef struct Node
{
  struct Node *next;

  Card card;

}node;

extern node* deck_p1;
extern node* deck_p2;

node *createNode(Card newCard);

int insertBeforeHead(node **head, Card newCard);

int isEmpty(node *front);

int deleteHead(node **head);

struct Node *push(node **top, Card newCard);

int pop(node **node);

void printStack(node** top);

// not sure if this proper haven't learned extern keryword in class
// but extern is the only way to have declared vars in one file work in another
extern Card cardTest;
extern Card cardTest2;
extern Card cardTest3;
extern Card cardTest4;
extern Card cardTest5;

Card createCard(char mName[], int atk, int def, char type[]);

void createAllCards();
