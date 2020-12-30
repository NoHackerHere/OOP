#ifndef CLASSLIST_H
#define CLASSLIST_H
#include <iostream>
#include <string>
#include <list>
#include <cstdlib>
#include <iterator>
#include <algorithm>
#include "deck.h"
#include "card.h"
// This portion of code was written by Chandler Chen //

using namespace std;

struct playerHand_s {
  string playerRank;
};

// Classes of Players
class playerClass_c {
  protected:
  
  public:
  	list<playerHand_s> myHand;
  	// Makes hand by calling 7 times with input of cards chosen randomly
  	void addToHand(string cardRank) {
      playerHand_s tempList; // Instantiate temporary struct
      tempList.playerRank = cardRank;

      myHand.push_back(tempList); // Insert to myHand lists
      return;
    }
    // Traverse the list of cards and delete the match only after adding to the other players hand
  	void deleteFromHand(string cardRank) {
			list<playerHand_s>::iterator it; // Iterator for the hand list
      for(it = myHand.begin(); it != myHand.end(); it++) { // Finds the elements
        if(it->playerRank == cardRank) {
          myHand.erase(it);
          break;
        }
      }
      return;
    }
  	// Draw one card from the deck
  	void goFish() {
      Deck tempDeck; // Temporary deck object
      tempDeck.shuffle();
			Card c = tempDeck.dealOneCard(); // Temporary card object
			addToHand(c.getFace()); // Appends it to the hand list
      return;
    }
  	// Returns T/F if card is in the hand
    bool searchHand(string cardRank) {
      bool found = 0;
      list<playerHand_s>::iterator it;
      for(it = myHand.begin(); it != myHand.end(); it++) {
        if(it->playerRank == cardRank) {
      		found = 1;
          break;
        }
      }
      return found;
  	}
}; // End of playerClass_c

class thePlayer_c : public playerClass_c {
  private:
  	// None
  	// A myHand list is inherited
  public:
  	// Prints hand of user
  	void printHand() {
      list<playerHand_s>::iterator it;
      for(it = myHand.begin(); it != myHand.end(); it++) {
        cout << it->playerRank << endl;
      }
      return;
    }
  	int bookCount(string cardRank) {
      list<playerHand_s>::iterator it;
      int cardCounter = 0;
      int bookCounter;
      for(it = myHand.begin(); it != myHand.end(); it++) {
        if(it->playerRank == cardRank) {cardCounter += 1;}
        if(cardCounter > 3) {bookCounter += 1;}
      }
    return bookCounter;
    }
}; // End of thePlayer_c

class computerPlayer_c : public playerClass_c {
  private:
  	// None
  public:
  	// None
  	// All functions inherited from base
  	int bookCount(string cardRank) {
      list<playerHand_s>::iterator it;
      int cardCounter;
      int bookCounter;
      for(it = myHand.begin(); it != myHand.end(); it++) {
        if(it->playerRank == cardRank) {cardCounter++;}
        if(cardCounter > 3) {bookCounter++;}
      }
    return bookCounter;
    }
};

#endif











