#include "battle.h"
#include "card.h"
#include "player.h"
#include <time.h>
#include <stdbool.h>

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


void handleBadInput(GameState *game)
{
  int c;
  while ((c = getchar()) != '\n' && c != EOF) {
    /* throw away the bad input */
  }
  createMenu();
  int choice = getUserInput();
  handleInput(choice, game);
}


void handleInput(int userChoice, Game *game) {
    switch(userChoice)
    {
     case 1:
         printf("Enter name for Player 1: ");
         scanf("%s", game->p1.name);
         printf("Enter name for Player 2: ");
         scanf("%s", game->p2.name);
         
         &game->playersCreated = true;
         break;

     case 2:
         printf("cards have been added to players \n");
         populateDeck(&game->p1.deck);
         populateDeck(&game->p2.deck);
         game->playersHaveCards = true;
         break;

     case 3:
     if(game->playersHaveCards == true && game->playersCreated == true)
     {
      game->battleStarted = true;
      printf("battling players \n");
      firstPlayer = coinFlip();

      // draw cards
      
      queueHand(&game->p1);
      queueHand(&game->p2);

    

      // place cards into battle queues
     

      // activate cards
      if(firstPlayer == 1)
      {
        while(game->battleEnded == false) {
            
            int p1Num = displayTurnMenu(game->p1.hand, &game->p1);
            int p2Num = displayTurnMenu(game->p2.hand, &game->p2);

         if(p1Num == 1 && p2Num == 1) {
             
             getDamage2Atk(game->p1.atkQueue.cards[game->p1.atkQueue.front].atk, game->p2.atkQueue.cards[game->p2.atkQueue.front].atk);
         } else if(p1Num == 1 && p2Num == 2) {
             
             getDamage1Atk(game->p1.atkQueue.cards[game->p1.atkQueue.front].atk, game->p2.defQueue.cards[game->p2.defQueue.front].def, &game->p1);
         } else if(p1Num == 2 && p2Num == 1) {
             
             getDamage1Atk(game->p2.atkQueue.cards[game->p2.atkQueue.front].atk, game->p1.defQueue.cards[game->p1.defQueue.front].def, &game->p2);
         }
        }
      }
      else if(firstPlayer == 2)
      {
        while(game->battleEnded == false)
        {
         int p2Num = displayTurnMenu(game->p2.hand, &game->p2);
         int p1Num = displayTurnMenu(game->p1.hand, &game->p1);
         if(p1Num == 1 && p2Num == 1)
         {
          game->p1.atkQueue.cards[game->p1.atkQueue.front].atk += atkBonus(game->p1.atkQueue.cards[game->p1.atkQueue.front].type, 
          game->p2.atkQueue.cards[game->p1.atkQueue.front].type, game->p1.atkQueue.cards[game->p1.atkQueue.front]);

          game->p2.atkQueue.cards[game->p2.atkQueue.front].atk += atkBonus(game->p2.atkQueue.cards[game->p2.atkQueue.front].type, 
          game->p1.atkQueue.cards[game->p1.atkQueue.front].type, game->p2.atkQueue.cards[game->p1.atkQueue.front]);

          getDamage2Atk(game->p1.atkQueue.cards[game->p1.atkQueue.front].atk, game->p2.atkQueue.cards[game->p2.atkQueue.front].atk);
         }
         else if(p1Num == 1 && p2Num == 2)
         {
          getDamage1Atk(game->p1.atkQueue.cards[game->p1.atkQueue.front].atk, game->p2.defQueue.cards[game->p2.defQueue.front].def, &game->p1);

          game->p1.atkQueue.cards[game->p1.atkQueue.front].atk += atkBonus(game->p1.atkQueue.cards[game->p1.atkQueue.front].type, 
          game->p2.defQueue.cards[game->p2.defQueue.front].type, game->p1.atkQueue.cards[game->p1.atkQueue.front]);

          game->p2.defQueue.cards[game->p2.defQueue.front].atk += defBonus(game->p2.atkQueue.cards[game->p2.atkQueue.front].type, 
          game->p1.atkQueue.cards[game->p1.atkQueue.front].type, game->p2.defQueue.cards[game->p2.defQueue.front]);
         }
         else if(p1Num == 2 && p2Num == 1)
         {
          getDamage1Atk(game->p2.atkQueue.cards[game->p2.atkQueue.front].atk, game->p1.defQueue.cards[game->p1.defQueue.front].def, &game->p2);

          game->p1.defQueue.cards[game->p1.defQueue.front].def += defBonus(game->p1.defQueue.cards[game->p1.defQueue.front].type, 
          game->p2.atkQueue.cards[game->p2.atkQueue.front].type, game->p1.defQueue.cards[game->p1.defQueue.front]);

          game->p2.atkQueue.cards[game->p2.atkQueue.front].atk += atkBonus(game->p2.atkQueue.cards[game->p2.atkQueue.front].type, 
          game->p1.defQueue.cards[game->p1.defQueue.front].type, game->p2.atkQueue.cards[game->p2.atkQueue.front]);
         }
        }
      }
      removeBattleCards(&game->p1.atkQueue);
      removeBattleCards(&game->p1.defQueue);
      removeBattleCards(&game->p2.atkQueue);
      removeBattleCards(&game->p2.defQueue);
      
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




int main(void) {
    Game game = {0};

    while (!game.battleStarted)
    {
        createMenu();

        int choice = getUserInput();

        handleInput(choice, &game);
    }

    return 0;
}
