#pragma once

#ifndef PARTICIPANT_H
#define PARTICIPANT_H

#include "Card.h"
#include <iostream>

class Participant
{
private:
	int score, sumOfHand;
	Card card = Card();

public:
	Participant();
	~Participant();
	void setScore();
	int getSumOfHand();
	void setSumOfHand(int cardValue);
	int getScore();
	void setHandToZero();

protected:

};
#endif
