/**************************************************************************************
****File:		Deck.cpp
**** 
****Desc:		Functions to create Card deck to a vector using Card class,
****            shuffle, print, draw new card, remove card and wipe card deck empty
****
****Author:		Veikka Kamppi
***************************************************************************************/

#include "Deck.h"

Deck::Deck()
{
	numberOfSuits = 4;
	cardsPerSuit = 13;

}
Deck::~Deck()
{
    delete card;
    //cout << "Deck destructor called!" << endl;
}

/// <summary>
/// Pass values through constructor to the last index of an empty 2D vector
/// </summary>
void Deck::createCardDeck()
{
    for (int suit = 1; suit <= numberOfSuits; suit++)
        for (int value = 1; value <= cardsPerSuit; value++)
        {
            *card = Card(suit, value);
            CardDeck.push_back(*card);
        }
}

void Deck::shuffleCardDeck()
{
    random_device rd;
    mt19937 gen(rd());
    shuffle(begin(CardDeck), end(CardDeck), gen);
}

void Deck::printCardDeck()
{
    for (int column = 0; column < CardDeck.size(); column++)
    {
        CardDeck[column].displayCard();
        CardDeck[column].valueOfCard();
    }
    cout << "\nDeck -> PrintCardDeck()\n" << endl;
}

/// <summary>
/// Returns amount of cards left in deck
/// </summary>
/// <returns></returns>
int Deck::numberOfCardsInDeck()
{
    int size = CardDeck.size();
    return size;
}

/// <summary>
/// Draws first card from card deck and removes it
/// returns value of the drawn card
/// </summary>
/// <returns></returns>
int Deck::drawNewCard()
{
    int value = CardDeck.front().displayCard();
    removeCardFromDeck();
    numberOfCardsInDeck();
    return value;
}

/// <summary>
/// Removes first card from vector
/// </summary>
void Deck::removeCardFromDeck()
{
    CardDeck.erase(CardDeck.begin());
}

/// <summary>
/// Cleans card deck from cards in the end of the round
/// </summary>
void Deck::emptyCardDeck()
{
    CardDeck.clear();
}