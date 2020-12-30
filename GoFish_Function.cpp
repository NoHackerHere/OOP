#ifndef FUNCTION_H
#define FUNCTION_H
#include <iostream>
#include <string>
#include <algorithm>
#include <list>
#include <cstdlib>
#include <iterator>
#include "class.h"
// This portion of code was written by Chandler Chen //

using namespace std;

void endGame(string, int);

// Runs the game
void gameStart(computerPlayer_c& cpuPlayerObject, thePlayer_c& playerObject) { // Player always goes first
  int bailout; // Exits the game at any time, progress is not saved
  string askCpuRank; // Temp variable to store user input
  string askPlayerRank; // Temp variable to store cpu input
  int playerBook;
  int playerBookCount = 0;
  int cpuBook;
  int cpuBookCount = 0;
  int askPlayer; // User input if they have the card cpu requested
  bool inHand; // Presearches the user's hand to mitigate boshitting
  char toFish; // Initates go fishing
  list<playerHand_s>::iterator it;
  
  do {
    int cpuHandRand = rand()%(cpuPlayerObject.myHand.size()); // Determines what index to choose a card in cpu hand
    cout << "Your hand: " << endl;
		playerObject.printHand();
    cout << "What card rank to axe for? * to exit. ";
		cin >> askCpuRank;
    if(askCpuRank == "*") {break;} // Exits the game
    if(askCpuRank == "p") {continue;} // Prints the hand
    playerBook = playerObject.bookCount(askCpuRank);
    cout << playerBook << " books of " << askCpuRank << endl;
    if(playerBook > 0) {playerBookCount += 1;}
    inHand = cpuPlayerObject.searchHand(askCpuRank); // Searches the cpu hand for the card
    if(inHand) {
      playerObject.addToHand(askCpuRank); // Adds the card to the users hand
      cpuPlayerObject.deleteFromHand(askCpuRank); // Removes the card from cpu hand
      cout << "You got a cahd!" << endl;
    } else { // Goes fishing if the cpu doesn't have card
      cout << "Not here, press x to Go Fish." << endl;
      cin >> toFish;
      if(toFish = 'x') {playerObject.goFish();
                       cout << "Gone Fishin'..." << endl;}
    }
    
    it = cpuPlayerObject.myHand.begin();
    advance(it, cpuHandRand);
		askPlayerRank = it->playerRank; // Assigns rank to the variable for cpu to ask user
    
    cout << "Do you has a " << askPlayerRank << " ?" << endl;
    cout << "Yes: 1 No: 0" << endl; cin >> askPlayer; cout << endl;
    inHand = playerObject.searchHand(askPlayerRank);
    cpuBook = cpuPlayerObject.bookCount(askPlayerRank);
    if(cpuBook > 0) {cpuBookCount += 1;}
    
    if(askPlayer && inHand) { // User lie detector
      cpuPlayerObject.addToHand(askPlayerRank);
      playerObject.deleteFromHand(askPlayerRank);
      cout << "danke schön!" << endl;
    } else if(!askPlayer && inHand) {
      cout << "Liar Liar! Knickers on fire!" << endl;
      playerObject.deleteFromHand(askPlayerRank);
      cpuPlayerObject.addToHand(askPlayerRank);
    } else if(askPlayer && !inHand) {
      for(int i = 0; i < 50; i++) {
        cout << "I don't like liars..." << endl;
      }
    }
    
    if((playerBookCount > cpuBookCount) && playerBookCount == 2) {
      endGame("Little Buddy", playerBookCount);
      break;
    }
    else if((cpuBookCount > playerBookCount) && cpuBookCount == 2) {
      endGame("CPU", cpuBookCount);
      break;
    }
		
  } while (1);
  
  return; // Exit function and return to main(), quits game.
} // End gameStart
  
void endGame(string playerName, int numBooks) {
  cout << "Winner is " << playerName << " with " << numBooks << " books!" << endl;
  cout << "That was a fun one!" << endl;
}

#endif









