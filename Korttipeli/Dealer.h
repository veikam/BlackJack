#pragma once

#ifndef DEALER_H
#define DEALER_H

#include "Participant.h"
#include "Deck.h"
#include <iostream>

class Dealer: public Participant
{
private:
	int targetValue;
	Deck deck;
	
public:
	Dealer();
	~Dealer();
	void createCardDeck();
	void emptyCardDeck();
	void shuffleCardDeck();
	int dealCard();
	void setSumOfHand(int cardValue);
	int getSumOfHand();
	void setScore();
	int getScore();
	int getTargetValue();
	void setHandToZero();

protected:

};
#endif
