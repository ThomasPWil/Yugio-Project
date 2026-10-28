#include "card.h"

Card cardTest;
Card cardTest2;

node* deck_p1 = NULL;
node* deck_p2 = NULL;

Card createCard(char mName[], int atk, int def, char type[])
{
  Card newCard;
  strcpy(newCard.mName,mName);
  newCard.atk = atk;
  newCard.def = def;
  strcpy(newCard.type, type);
  
  return newCard;
}

node *createNode(Card newCard)
{
   node* newNode = (node*)malloc(sizeof(struct Node));

   if(newNode == NULL)
   {
      return NULL;
   }

   newNode->card = newCard;
   newNode->next = NULL;
   return newNode;
}

int insertBeforeHead(node **head, Card newCard)
{
  node *newNode = createNode(newCard);

  if(newNode == NULL)
  {
    return -1;
  }

  if(*head == NULL)
  {
   *head = newNode;
   return 0;
  }
  newNode->next = *head;
  *head = newNode;
  return 0;
}

int isEmpty(node *front)
{
   return (front == NULL);
}

int deleteHead(node **head)
{
  node *temp = *head;
  *head = (*head)->next;
  free(temp);
  return 0;
}

struct Node *push(node **top, Card newCard)
{
   if(insertBeforeHead(top, newCard))
   {
      printf("stack overflow");
   }

}

int pop(node **node)
{
  if(isEmpty(*node))
  {
    printf("stack underflow");
    return -1;
  }

  deleteHead(node);
}

void printStack(node** top)
{
  if(isEmpty(*top))
  {
   printf("stack empty\n");

  }
  node* temp = *top;
  while(temp != NULL)
  {
   printf(" %s \n", temp->card.mName);
   temp = temp->next;
  }
  printf("stack complete ");
}

void createAllCards()
{
  // add cards you would like to create here
  cardTest = createCard("Verdugo", 100 , 100 , "fire");
  cardTest2 = createCard("Garrador", 150, 150, "Normal");
}
