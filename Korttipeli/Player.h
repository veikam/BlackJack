#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include "Participant.h"
#include <iostream>

class Player : public Participant
{
private:
	

public:
	Player();
	~Player();
	void setSumOfHand(int cardValue);
	int getSumOfHand();
	void setScore();
	int getScore();
	void setHandToZero();

protected:

};

#endif
