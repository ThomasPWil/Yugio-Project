#include "battle.h"
#include "card.h"
#include "player.h"
#include <time.h>
#include <stdbool.h>

bool playersHaveCards;
bool playersCreated;
bool battleStarted = false;
bool battleEnded = false;
bool p1First2;
bool p2First2;

void createMenu()
{
    printf("========== YU-GI-OH! CARD BATTLE ==========\n");
    printf("1. Create Players \n");
    printf("2. Add Cards to Players \n");
    printf("3. Battle Other Player \n");
    printf("4. Quit Game\n");
}

int getUserInput()
{
    int userChoice;
    printf("select an option: ");
    scanf(" %d", &userChoice);

    return userChoice;
}


void handleBadInput()
{
  int c;
  while ((c = getchar()) != '\n' && c != EOF) {
    /* throw away the bad input */
  }
  createMenu();
  int choice = getUserInput();
  //handleInput(choice);
}


void handleInput(int userChoice)
{
    switch(userChoice)
    {
     case 1:
     printf(" players have been created \n");
     createPlayers();
     playersCreated = true;
     
     break;

     case 2:
     printf("cards have been added to players \n");
     populateDeck(&player1.deck);
     populateDeck(&player2.deck);
     playersHaveCards = true;
     break;

     case 3:
     if(playersHaveCards == true && playersCreated == true)
     {
      battleStarted = true;
      printf("battling players \n");
      coinFlip();

      // draw cards
      
      queueHand(&player1);
      queueHand(&player2);

    

      // place cards into battle queues
     

      // activate cards
      if(p1First == true)
      {
        while(battleEnded == false)
        {
          int p1Num = displayTurnMenu(player1.hand, &player1);
          int p2Num = displayTurnMenu(player2.hand, &player2);

         if(p1Num == 1 && p2Num == 1)
         {
          getDamage2Atk(player1.atkQueue.cards[player1.atkQueue.front].atk, player2.atkQueue.cards[player2.atkQueue.front].atk);
         }
         else if(p1Num == 1 && p2Num == 2)
         {
          getDamage1Atk(player1.atkQueue.cards[player1.atkQueue.front].atk, player2.defQueue.cards[player2.defQueue.front].def, &player1);
         }
         else if(p1Num == 2 && p2Num == 1)
         {
          getDamage1Atk(player2.atkQueue.cards[player2.atkQueue.front].atk, player1.defQueue.cards[player1.defQueue.front].def, &player2);
         }
        }
      }
      else if(p2First == true)
      {
        while(battleEnded == false)
        {
         int p2Num = displayTurnMenu(player2.hand, &player2);
         int p1Num = displayTurnMenu(player1.hand, &player1);
         if(p1Num == 1 && p2Num == 1)
         {
          player1.atkQueue.cards[player1.atkQueue.front].atk += atkBonus(player1.atkQueue.cards[player1.atkQueue.front].type, 
          player2.atkQueue.cards[player1.atkQueue.front].type, player1.atkQueue.cards[player1.atkQueue.front]);

          player2.atkQueue.cards[player2.atkQueue.front].atk += atkBonus(player2.atkQueue.cards[player2.atkQueue.front].type, 
          player1.atkQueue.cards[player1.atkQueue.front].type, player2.atkQueue.cards[player1.atkQueue.front]);

          getDamage2Atk(player1.atkQueue.cards[player1.atkQueue.front].atk, player2.atkQueue.cards[player2.atkQueue.front].atk);
         }
         else if(p1Num == 1 && p2Num == 2)
         {
          getDamage1Atk(player1.atkQueue.cards[player1.atkQueue.front].atk, player2.defQueue.cards[player2.defQueue.front].def, &player1);

          player1.atkQueue.cards[player1.atkQueue.front].atk += atkBonus(player1.atkQueue.cards[player1.atkQueue.front].type, 
          player2.defQueue.cards[player2.defQueue.front].type, player1.atkQueue.cards[player1.atkQueue.front]);

          player2.defQueue.cards[player2.defQueue.front].atk += defBonus(player2.atkQueue.cards[player2.atkQueue.front].type, 
          player1.atkQueue.cards[player1.atkQueue.front].type, player2.defQueue.cards[player2.defQueue.front]);
         }
         else if(p1Num == 2 && p2Num == 1)
         {
          getDamage1Atk(player2.atkQueue.cards[player2.atkQueue.front].atk, player1.defQueue.cards[player1.defQueue.front].def, &player2);

          player1.defQueue.cards[player1.defQueue.front].def += defBonus(player1.defQueue.cards[player1.defQueue.front].type, 
          player2.atkQueue.cards[player2.atkQueue.front].type, player1.defQueue.cards[player1.defQueue.front]);

          player2.atkQueue.cards[player2.atkQueue.front].atk += atkBonus(player2.atkQueue.cards[player2.atkQueue.front].type, 
          player1.defQueue.cards[player1.defQueue.front].type, player2.atkQueue.cards[player2.atkQueue.front]);
         }
        }
      }
      removeBattleCards(&player1.atkQueue);
      removeBattleCards(&player1.defQueue);
      removeBattleCards(&player2.atkQueue);
      removeBattleCards(&player2.defQueue);
      
     } 
     else
     {
       printf("have not created players or added cards yet");
       handleBadInput();
     }
    
     

     break;

     case 4:
     printf("quit game \n");
     break;

     default:
     printf("not valid option \n");
     handleBadInput();

     break;
    }

   

   
}




int main(void)
{
  while(battleStarted == false)
  {
   createMenu();
   int choice = getUserInput();
   handleInput(choice);
  }
  

  return 0;
  
}









