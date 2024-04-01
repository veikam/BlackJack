#pragma once

#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include <string>
#include <vector>
#include <iostream>
#include <random>
#include <algorithm>

using namespace std;

class Deck
{
private:
	int cardsPerSuit, numberOfSuits;
	vector<Card> CardDeck;
	Card *card = new Card();
	void removeCardFromDeck();

public:
	Deck();
	~Deck();
	void createCardDeck();
	void shuffleCardDeck();
	void printCardDeck();
	int numberOfCardsInDeck();
	int drawNewCard();
	void emptyCardDeck();
	
protected:

};

#endif