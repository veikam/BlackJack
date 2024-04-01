/**************************************************************************************
****File:		Participant.cpp
****
****Desc:		Base class for player and dealer.
****			Functions to set & get score, set & get sum of hand, set sum of hand to 0.
****
****Author:		Veikka Kamppi
***************************************************************************************/

#include "Participant.h"

Participant::Participant()
{
	score = 0;
	sumOfHand = 0;
}

Participant::~Participant()
{
	//cout << "Participant destructor called!" << endl;
}

void Participant::setScore() 
{
	score++;
}

/// <summary>
/// Set sum of hand to card value
/// Decide Ace value automatically
/// </summary>
/// <param name="cardValue"></param>
void Participant::setSumOfHand(int cardValue)
{
	if (cardValue == 1 && cardValue + sumOfHand < 21)
	{
		cardValue = 11;
		cout << "Ace value is: " << cardValue << endl;
	}
	this->sumOfHand += cardValue;
}

/// <summary>
/// Return total sum of cards of participant
/// </summary>
/// <returns></returns>
int Participant::getSumOfHand()
{
	cout << endl;
	return sumOfHand;
}

/// <summary>
/// Return score of participant
/// </summary>
/// <returns></returns>
int Participant::getScore()
{
	return score;
}

/// <summary>
/// Set sum of hand to zero after each round
/// </summary>
void Participant::setHandToZero()
{
	this->sumOfHand = 0;
}