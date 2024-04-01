/**************************************************************************************
****File:		Dealer.cpp
****
****Desc:		Dealer class derives from Participant class.
****			Functions to create, shuffle & empty card deck.
****
****Author:		Veikka Kamppi
***************************************************************************************/

#include "Dealer.h"

Dealer::Dealer()
{
	targetValue = 17;
}
Dealer::~Dealer()
{
	//cout << "Dealer destructor called!" << endl;
}

void Dealer::setScore()
{
	Participant::setScore();
}

int Dealer::getScore()
{
	return Participant::getScore();
}

void Dealer::setSumOfHand(int cardValue)
{
	Participant::setSumOfHand(cardValue);
}

int Dealer::getSumOfHand()
{
	return Participant::getSumOfHand();
}

/// <summary>
/// Deal new card from card deck
/// </summary>
/// <returns></returns>
int Dealer::dealCard()
{
	return deck.drawNewCard();
}

/// <summary>
/// Dealer's ability to create new deck of cards
/// </summary>
void Dealer::createCardDeck() 
{
	deck.createCardDeck();
	cout << "New card deck of " << deck.numberOfCardsInDeck() << " cards created." << endl;
}

/// <summary>
/// Dealer's ability to shuffle card deck
/// </summary>
void Dealer::shuffleCardDeck() 
{
	deck.shuffleCardDeck();
	cout << "Cards are shuffled.\n\n" << endl;
}

/// <summary>
/// Dealers ability to empty card deck of cards
/// </summary>
void Dealer::emptyCardDeck()
{
	deck.emptyCardDeck();
}

/// <summary>
/// Getter for dealer target for sum of hand
/// </summary>
/// <returns></returns>
int Dealer::getTargetValue()
{
	return targetValue;
}

void Dealer::setHandToZero()
{
	Participant::setHandToZero();
}