#include "battle.h"

int rounds = 0;


void printBattleData(Game *game)
{
  printf("%s current life points: %d \n" , game->p1.name, game->p1.hp);
  printf("%s current life points: %d \n \n" , game->p2.name, game->p2.hp);
  rounds++;
  
}

int coinFlip() {
  srand(time(NULL));

  int randNum = (rand() % 2) + 1;

  if(randNum == 1) {
    printf("num was 1 player 1 goes first \n \n \n");
    return 1;
  }
  else {
    printf("num was 2 player 2 goes first \n \n \n");
    return 2;
  }
}

void LPCalculations(int *currLP, int damage)
{
  *currLP -= damage;
  
}

// use this if we have one attcker and other is defensive
int getDamage1Atk(int atk, int def, Player *player, Game *game)
{

  // need to check for type bonuses calcualtions
  int damage = atk - def;
  if(damage < 0)
  {
    damage = 0;
    return 0;
  }
  
  if(!isEmpty(&game->p1.atkQueue))
  {
    printf("player1 activates %s \n", player1.atkQueue.cards[player1.atkQueue.front].name);
  }

  if(!isEmpty(&game->p1.defQueue))
  {
    printf("player1 activates %s \n", player1.defQueue.cards[player1.defQueue.front].name);
  }
  
  if(!isEmpty(&game->p2.atkQueue))
  {
    printf("player2 activates %s \n", player2.atkQueue.cards[player2.atkQueue.front].name);
  }

  if(!isEmpty(&game->p2.defQueue))
  {
    printf("player2 activates %s \n", player2.defQueue.cards[player2.defQueue.front].name);
  }
 

  if(game->firstPlayer == 1)
  {
    printf("%s attacks %s \n", player1.atkQueue.cards[player1.atkQueue.front].name,  player2.atkQueue.cards[player2.atkQueue.front].name);
  }
  else if(game->firstPlayer == 2)
  {
    printf("%s attacks %s \n", player2.atkQueue.cards[player2.atkQueue.front].name,  player1.atkQueue.cards[player1.atkQueue.front].name);
  }

  printf("damage dealt: %d to %s \n", atk - def, player->name);
  LPCalculations(&player->hp,damage);
  printBattleData();
  return damage;
}

// use if we have 2 attackers
int getDamage2Atk(int atk1,int atk2, Game *game)
{
  int damage = 0;
 
  if(atk1 > atk2)
  {
    // need to check for type bonuses
    damage = atk1 - atk2;
    LPCalculations(&player2.hp,damage);
    if(game->firstPlayer == 1)
    {
      printf("%s attacks %s \n", player1.atkQueue.cards[player1.atkQueue.front].name,  player2.atkQueue.cards[player2.atkQueue.front].name);
    }
    else if(game->firstPlayer == 2)
    {
      printf("%s attacks %s \n", player2.atkQueue.cards[player2.atkQueue.front].name,  player2.atkQueue.cards[player2.atkQueue.front].name);
    }
    printf("damage dealt to player 2: %d\n", damage);
    printBattleData();
    
    return damage;
  
  }
  else if(atk2 > atk1)
  {
    damage = atk2 - atk1;
    LPCalculations(&player1.hp,damage);

    if(game->firstPlayer == 1)
    {
      printf("%s attacks %s \n", player1.atkQueue.cards[player1.atkQueue.front].name,  player2.atkQueue.cards[player2.atkQueue.front].name);
    }
    else if(game->firstPlayer == 2)
    {
      printf("%s attacks %s \n", player2.atkQueue.cards[player2.atkQueue.front].name,  player2.atkQueue.cards[player2.atkQueue.front].name);
    }
   
    printf("damage dealt to player 1: %d \n", damage);
    printBattleData();
    return damage;
  }
  else if(atk1 == atk2)
  {
    printf("Both cards have similar attacks so no neither player talkes damage \n");
    return 0;
  }
}

void removeAtIndex(MonsterCard hand[5], Player *player, int index)
{
  for(int i = index; i < player->handCount - 1; i++) 
  {
    player->hand[i] = player->hand[i + 1];
  }
  player->handCount--;
  drawCard(player);
}

void removeBattleCards(Queue *q)
{
  if(!isEmpty(q))
  {
    dequeue(q);
  }
}

void endBattle(Game *game)
{
  if(game->p1.hp <= 0)
  {
    printf("player2 wins!\n");
  }
  else if(game->p2.hp <= 0 )
  {
    printf("player1 wins!\n");
  }
  else if(game->p1.deck.top == 0 && game->p2.deck.top == 0)
  {
    // draw condition occurs when both players run out of cards
    printf("draw! \n");
  }
  
  //printf("player1 life points %d", p1_hp);
  //printf("player2 life points %d", p2_hp);
  printf("rounds played: %d \n", rounds);
}

int displayTurnMenu(MonsterCard hand[5], Player *player)
{
  printf("%s's turn \n \n",player->name);
  // print hand 
  for(int i = 0; i < player->handCount; i++)
  {
    printf("%s %d %d %s \n", player->hand[i].name, player->hand[i].atk, player->hand[i].def,  player->hand[i].type);
  }

  int choice = 0;
  printf("choose a number (1-2) 1 to activate an attack card \n");
  printf("2 to activate a defense card \n");
  scanf("%d" , &choice);
  printf("\n");

  if(choice == 1)
  {
    printf("choose an attack card to activate (1-5)\n");
    printf("player hand: %d \n", player->handCount);

    // display list of cards in hand
    for(int i = 0; i < player->handCount; i++)
    {
      printf("%s %d %d %s \n", player->hand[i].name, player->hand[i].atk, player->hand[i].def,  player->hand[i].type);
    }

    int atkChoice = 0;
    scanf("%d", &atkChoice);
    atkChoice--;
    
    if(atkChoice >= 0 && atkChoice < 5)
    {
      enqueue(&player->atkQueue, player->hand[atkChoice]);
      removeAtIndex(player->hand, player, atkChoice);
    }
    else
    {
      printf("invalid selection try again\n");
    }
  
    return choice;
  }
  else if(choice == 2)
  {
    printf("choose a defense card to activate\n");
    // display list of cards in hand
    int defChoice = 0;
    for(int i = 0; i < player->handCount; i++)
    {
      printf("%s %d %d \n", player->hand[i].name, player->hand[i].atk, player->hand[i].def);
    }
    scanf("%d", &defChoice);
    defChoice--;
    enqueue(&player->defQueue, player->hand[defChoice]);
    removeAtIndex(player->hand, player, defChoice);
    return choice;
    
  }
  else
  {
    //printf("test");
  }
}
