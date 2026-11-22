#include "card.h"
#include "player.h"
#include "battle.h"
#include "player.h"

int rounds = 0;
bool p1First;
bool p2First;

int p1Choice; // use these to figure out if which we should attack scenario we should play
int p2Choice; // use these to figure out if which we should attack scenario we should play

void coinFlip()
{
  srand(time(NULL));
  int p1num = 1;
  int p2num = 2;

  int randNum = (rand() % 2) + 1;

  if(randNum == 1)
  {
    printf("num was 1 player 1 goes first \n");
    p1First = true;
  }
  else if(randNum == 2)
  {
    printf("num was 2 player 2 goes first \n");
    p2First = true;
  }
}

void LPCalculations(int currLP, int damage)
{
  currLP -= damage;
}

// use this if we have one attcker and other is defensive
int getDamage1Atk(int atk, int def)
{
  // need to check for type bonuses calcualtions
  //atkBonus();
  //defBonus();
  return atk - def;
}

// use if we have 2 attackers
int getDamage2Atk(int atk1,int atk2)
{
  int damage = 0;
  
  if(atk1 > atk2)
  {
    // need to check for type bonuses
    LPCalculations(player2.hp,damage);
    return damage = atk1 - atk2;
  
  }
  else if(atk2 > atk1)
  {
    LPCalculations(player2.hp,damage);
    return damage = atk2 - atk1;
  }
  else if(atk1 == atk2)
  {
    return 0;
  }
}

void removeAtIndex(MonsterCard hand[5], Player player, int index)
{
  for(int i = index; i < player.handCount - 1; i++) 
  {
    hand[i] = hand[i + 1];
  }
  drawCard(&player);
}

void removeBattleCards(Queue *q)
{
  dequeue(q);
}

void endBattle()
{
  if(player1.hp <= 0)
  {
    printf("player2 wins!\n");
  }
  else if(player2.hp <= 0 )
  {
    printf("player1 wins!\n");
  }
  else if(player1.deck.top == 0 && player2.deck.top == 0)
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
  printf("%s's turn",player->name);
  // print hand 
  int choice = 0;
  printf("choose a number (1-2) 1 to activate an attack card \n");
  printf("2 to activate a defense card");
  scanf(" %d " , &choice);

  if(choice == 1)
  {
    printf("choose an attack card to activate (1-5)\n");
    // display list of cards in hand
    for(int i = 0; i < player->handCount; i++)
    {
      printf("%s %d %d \n", player->hand[i].name, player->hand[i].atk, player->hand[i].def);
    }

    int atkChoice = 0;
    scanf(" %d ", &atkChoice);
    enqueue(&player->atkQueue, player->hand[atkChoice]);
    removeAtIndex(player->hand, *player, atkChoice);
    return player->hand[atkChoice].atk;
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
    scanf(" %d ", &defChoice);
    enqueue(&player->defQueue, player->hand[defChoice]);
    removeAtIndex(player->hand, *player, defChoice);
    return player->hand[defChoice].def;
    
  }
}




