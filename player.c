#include "player.h"

void push(int value)
{
   struct Node* newNode = malloc(sizeOf(struct Node));
   newNode->data = value;
}
