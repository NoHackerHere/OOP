#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iterator>
#include <list>
#include <ctime>
#include "function.h"
#include "class.h"
#include "card.h"
#include "deck.h"
#include "rulebook.h"
// This portion of code was written by Chandler Chen //

using namespace std;

void ruleBook();
void gameStart(computerPlayer_c&, thePlayer_c&);

int main() {
  // Initialise variables
  int menuStart; // Choose to see rules or start game
  srand(time(0)); // Seeds the RNG for picking a card
  
  // Set up game
  thePlayer_c userPlayer; // Instantiate object for user
  computerPlayer_c cpuPlayer; // Instantiate object for cpu
  
  srand(time(0)); // Initializes random "seed"
  Deck deck; // Creates new deck object
  deck.shuffle(); // Shuffles deck of cards by swapping elements
  
  //Populate the hand for each player
  for(int i = 0; i < 7; i++) {
    Card c = deck.dealOneCard(); // Creates a new card object
		userPlayer.addToHand(c.getFace()); // Passes card values to be stored inside vector in side objects
    c = deck.dealOneCard();
    cpuPlayer.addToHand(c.getFace());
    // Destructs card objects
	}
  
  do {
    cout << "Good morning, Buddy. Have you played Go Fish before?" << endl;
  	cout << "Enter 2 to see the Rules of Engagement." << endl;
  	cout << "Enter 1 to dive right in." << endl;
  	cout << "Enter 0 to quit." << endl;
  	cin >> menuStart;
    switch (menuStart) {
      case 1: // Start the game
        gameStart(cpuPlayer, userPlayer); // Passes player objects for operation in function
        break;
      case 2: // Look at rulebook; create a text file, stored locally, and writes to it; the user can open
        ruleBook();
        cout << "Check your local drive for Rules_of_Engagement.txt"  << endl;
        break;
      case 0:
        cout << "For f**ks sake..." << endl;
        break;
  	} // End switch
  } while(menuStart != 0);
  
  return 0;
} // End main











