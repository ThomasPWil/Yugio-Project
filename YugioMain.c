#include "battle.h"
#include "card.h"
#include "player.h"

int choice;

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

void handleInput(int userChoice)
{
    switch(userChoice)
    {
     case 1:
     printf("create players \n");
     break;

     case 2:
     printf("add cards to players \n");
     break;

     case 3:
     printf("battle players \n");
     break;

     case 4:
     printf("quit game \n");
     break;

     default:
     printf("not valid option \n");
     int c;
     while ((c = getchar()) != '\n' && c != EOF) {
            /* throw away the bad input */
        }
     createMenu();
     int choice = getUserInput();
     handleInput(choice);
     

     break;
    }

   

   
}

void main()
{
  createMenu();
  int choice = getUserInput();
  handleInput(choice);
  
}



