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
    printf("select an option ");
    scanf("%d ", &userChoice);

    return userChoice;
}

void handleInput(int userChoice)
{
    switch(userChoice)
    {
     case 1:
     printf("create players");
     break;

     case 2:
     printf("add cards to players");
     break;

     case 3:
     printf("battle players");
     break;

     case 4:
     printf("quit game");
     break;

     default:
     printf("not valid option");
     break;
    }

   
}

void main()
{
  createMenu();
  int choice = getUserInput();
  handleInput(choice);
}

