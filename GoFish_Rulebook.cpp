#ifndef RULEBOOK_H
#define RULEBOOK_H
#include <iostream>
#include <fstream>
#include <string>
// This portion of code was written by Josue Soto Lora //

using namespace std;

// Creates a text file for the rulebook
void ruleBook() {
  ofstream ruleBook;
  ruleBook.open("Rules_of_Engagement.txt");
  
  ruleBook << "RULES OF ENGAGEMENT" << endl;
  ruleBook << "The Goal is to win with the most 'books' of cards." << endl;
  ruleBook << "A book is any 'Four of a Kind', for example four aces or four twos" << endl;
  ruleBook << " " << endl;
  ruleBook << "CARD RANK:" << endl;
  ruleBook << "Cards are divided into ranks from Ace (high) to two (low)" << endl;
  ruleBook << "Keep in mind suits are not important! Only the numbers are relevant" << endl;
  ruleBook << " " << endl;
  ruleBook << "WHO STARTS:" << endl;
  ruleBook << "To determine who starts the computer will give you a random number" << endl;
  ruleBook << "If this number is higher than the computer's you will start" << endl;
  ruleBook << "If it is lower, the computer starts" << endl;
  ruleBook << " " << endl;
  ruleBook << "HOW TO PLAY" << endl;
  ruleBook << "The player asks their opponent for any rank of card they also have in their hand" << endl;
  ruleBook << "The Opponent gives all cards of that rank to the player" << endl;
  ruleBook << "If the opponent does not have that card they say 'go fish'" << endl;
  ruleBook << "at this point the player must choose from the top of the deck." << endl;
  ruleBook << "If the card being fished for is found the player's continues to ask for cards" << endl;
  ruleBook << "If the card being fished for is NOT found then the player's turn ends" << endl;
  ruleBook << "If the player is able to make a 'Four of a Kind' they are given a point" << endl;
  ruleBook << "who ever has the most points (aka books) is crowned the winner!" << endl;

  ruleBook.close();
}

#endif