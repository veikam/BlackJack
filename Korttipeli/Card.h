#pragma once

#ifndef CARD_H
#define CARD_H

#include <string>
#include <iostream>

using namespace std;

class Card
{
private:
	int suit, value;
	string getSuit( int suit );
	string getValue( int value );

public:
	Card();
	~Card();
	Card(int givenSuit, int givenValue);
	int displayCard();
	int valueOfCard();

protected:


};

#endif