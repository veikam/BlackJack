/**************************************************************************************
****File:		Player.cpp
****
****Desc:		Player class derives from Participant class.
****
****Author:		Veikka Kamppi
***************************************************************************************/

#include "Player.h"

Player::Player()
{

}

Player::~Player()
{
	//cout << "Player destructor called!" << endl;
}

int Player::getScore()
{
	return Participant::getScore();
}

void Player::setSumOfHand(int cardValue)
{
	Participant::setSumOfHand(cardValue);
}

int Player::getSumOfHand()
{
	return Participant::getSumOfHand();
}

void Player::setScore()
{
	Participant::setScore();
}

void Player::setHandToZero()
{
	Participant::setHandToZero();
}