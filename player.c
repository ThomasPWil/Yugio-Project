#include "player.h"
#include "card.h"


Player player1;
Player player2;

void main()
{
  createAllCards();
  createPlayers();
  printStack(&deck_p1);
  
}

void populateDecks(node** deckToPopulate)
{
  // add cards to deck stack
  push(deckToPopulate,cardTest);
  push(deckToPopulate,cardTest2);
}

void createPlayers()
{
  player1 = (Player){8000, deck_p1};
  populateDecks(&deck_p1);
 
  player2 = (Player){8000,deck_p2};
  populateDecks(&deck_p2);
}
