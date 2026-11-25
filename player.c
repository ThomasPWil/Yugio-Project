#include "card.h"
#include "player.h"
#include "battle.h"
#include "player.h"

int rounds = 0;


void printBattleData()
{
  printf("%s current life points: %d \n" , player1.name, player1.hp);
  printf("%s current life points: %d \n \n" , player2.name, player2.hp);
}

void LPCalculations(int *currLP, int damage)
{
  *currLP -= damage;
}

// use this if we have one attcker and other is defensive
int getDamage1Atk(int atk, int def, Player *player)
{
  // need to check for type bonuses calcualtions
  int damage = atk - def;
  printf("damage dealt: %d to %s \n", atk - def, player->name);
  LPCalculations(&player->hp,damage);
  printBattleData();
  return damage;
}

// use if we have 2 attackers
int getDamage2Atk(int atk1,int atk2)
{
  int damage = 0;
 
  if(atk1 > atk2)
  {
    // need to check for type bonuses
    damage = atk1 - atk2;
    LPCalculations(&player2.hp,damage);
    printf("damage dealt to player 2: %d\n", damage);
    printBattleData();
    return damage;
  
  }
  else if(atk2 > atk1)
  {
    LPCalculations(&player2.hp,damage);
    damage = atk2 - atk1;
    printf("damage dealt to player 1: %d\n", damage);
    printBattleData();
    return damage;
  }
  else if(atk1 == atk2)
  {
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

int displayTurnMenu(MonsterCard hand[5], Player *player)
{
  printf("%s's turn \n \n",player->name);
  // print hand 
  int choice = 0;
  printf("choose a number (1-2) 1 to activate an attack card \n");
  printf("2 to activate a defense card \n");
  scanf("%d" , &choice);
  printf("\n");

  if(choice == 1) {
    printf("choose an attack card to activate (1-5)\n");
    printf("player hand: %d \n", player->handCount);

    // display list of cards in hand
    for(int i = 0; i < player->handCount; i++)
    {
      printf("%s %d %d %s \n", player->hand[i].name, player->hand[i].atk, player->hand[i].def,  player->hand[i].type);
    }

    int atkChoice = 0;
    scanf("%d", &atkChoice);
    enqueue(&player->atkQueue, player->hand[atkChoice]);
    removeAtIndex(player->hand, player, atkChoice);
    return choice;
  } else if(choice == 2) {
    printf("choose a defense card to activate\n");
    // display list of cards in hand
    int defChoice = 0;
    for(int i = 0; i < player->handCount; i++)
    {
      printf("%s %d %d \n", player->hand[i].name, player->hand[i].atk, player->hand[i].def);
    }
    scanf("%d", &defChoice);
    enqueue(&player->defQueue, player->hand[defChoice]);
    removeAtIndex(player->hand, player, defChoice);
    return choice;
    
  }
}






