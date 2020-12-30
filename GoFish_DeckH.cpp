// cardplay-1/deck.h
// Fred Swartz 2004-11-22
#ifndef DECK_H
#define DECK_H

#include "card.h"

using namespace std;

class Deck {
  private:
    Card _cards[52];
    int  _nextCardIndex;

  public:
    Deck();
    Card dealOneCard();
    void shuffle();
};    

#endif
