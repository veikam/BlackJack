/**************************************************************************************
****File:		Card.cpp
****
****Desc:		Functions to create cards, fetch card value and to display cards
****
****Author:		Veikka Kamppi
***************************************************************************************/

#include "Card.h"
#define	IMG_CARD_VAL 10

Card::Card()
{
	suit = 0;
	value = 0;
}
Card::~Card()
{
	//cout << "Card destructor called!" << endl;
}

Card::Card(int givenSuit, int givenValue)
{
	this->suit = givenSuit;
	this->value = givenValue;
}

int Card::displayCard()
{
	cout << getSuit(suit) << " " << getValue(value) << endl;
	return valueOfCard();
}

/// <summary>
/// Sets value of card greater than 10 to 10
/// doesn't affect Ace
/// </summary>
/// <returns></returns>
int Card::valueOfCard()
{
	if (value > IMG_CARD_VAL)
	{
		value = IMG_CARD_VAL;
	}
	return value;
}

string Card::getSuit( int suit )
{
	string result = "";

	switch ( suit )
	{
		
		case 1:
			{
				result = "Hearths";
				break;
			}
		case 2:
			{
				result = "Spades";
				break;
			}
		case 3:
			{
				result = "Clubs";
				break;
			}
		case 4:
			{
				result = "Diamonds";
				break;
			}
		default:
			break;
		}
	return result;
}

string Card::getValue(int value)
{
	string result = "";
	switch ( value )
	{
		case 1:
		{
			result = "Ace";
			break;
		}
		case 2:
		{
			result = "Two";
			break;
		}
		case 3:
		{
			result = "Three";
			break;
		}
		case 4:
		{
			result = "Four";
			break;
		}
		case 5:
		{
			result = "Five";
			break;
		}
		case 6:
		{
			result = "Six";
			break;
		}
		case 7:
		{
			result = "Seven";
			break;
		}
		case 8:
		{
			result = "Eight";
			break;
		}
		case 9:
		{
			result = "Nine";
			break;
		}
		case 10:
		{
			result = "Ten";
			break;
		}
		case 11:
		{
			result = "Jack";
			break;
		}
		case 12:
		{
			result = "Queen";
			break;
		}
		case 13:
		{
			result = "King";
			break;
		}
	default:
		break;
	}
	return result;
}



