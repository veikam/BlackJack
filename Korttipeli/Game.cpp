/**************************************************************************************
****File:		Game.cpp
****
****Desc:		Determines game state, check if participant is still in game print results
****
****Author:		Veikka Kamppi
***************************************************************************************/

#include "Game.h"
#define NUM_OF_ROUNDS 3

Game::Game()
{
	maxValue = 21;
	roundActive = true;
	currentRound = 1;
}

Game::~Game()
{
	//cout << "Game destructor called!" << endl;
}

/// <summary>
/// Handles game state
/// </summary>
void Game::startGame()
{
	try
	{
		do
		{
			cout << "Round " << *(&currentRound) << "\n--------------" << endl;
			initializeRound();
			round();
			endRound();
			currentRound++;
		} while (currentRound <= NUM_OF_ROUNDS );
	}
	catch (const std::exception&)
	{

	}
}

/// <summary>
/// Dealer creates and shiffles new card deck each round and
/// deals himself a card at start of the round
/// </summary>
void Game::initializeRound()
{
	dealer.createCardDeck();
	dealer.shuffleCardDeck();

	cout << "Dealer's first card\n--------------" << endl;
	timer.useTimer();
	dealer.setSumOfHand(dealer.dealCard());
	timer.useTimer();
	cout << endl;
}

/// <summary>
/// Empties cards, shows results and sets both participants hand value to 0
/// </summary>
void Game::endRound()
{
	dealer.emptyCardDeck();
	results();
	player.setHandToZero();
	dealer.setHandToZero();
}

/// <summary>
/// Check if round is active
/// </summary>
void Game::round()
{
	roundActive = true;
	playersTurn();
	if (roundActive)
	{
		dealersTurn();
	}

	if (dealer.getSumOfHand() > player.getSumOfHand() && roundActive) 
		dealer.setScore();
	else if ( player.getSumOfHand() > dealer.getSumOfHand() && roundActive )
		player.setScore();
}

/// <summary>
/// Deal cards untill hand is 17 or over
/// </summary>
void Game::dealersTurn()
{
	cout << "Dealers turn\n---------------\n\n" << endl;
	while (true)
	{
		if (!checkDealerHandCombined())
		{
			false;
			break;
		}
		else
		{
			dealer.setSumOfHand(dealer.dealCard());
			timer.useTimer();
		}
	}
}

/// <summary>
/// Deal player 2 starting cards, then using input decide to "hit" or "stand"
/// </summary>
void Game::playersTurn()
{
	cout << "Players turn\n---------------\n\n" << endl;
	int cardsToDeal = 2;
	for (int j = 0; j < cardsToDeal; j++)
	{
		player.setSumOfHand(dealer.dealCard());
		timer.useTimer();
	}
	bool i = true;
	while (i)
	{
		if (!checkPlayerHandCombined())
		{
			i = false;
			break;
		}
		else
		{
			int choice = 0;
			cout << "\n1) Hit\n2) Stand\n" << endl;
			cin >> choice;
			switch (choice)
			{
			case 1:
			{
				player.setSumOfHand(dealer.dealCard());
				cout << player.getSumOfHand() << endl;
				break;
			}
			default:
				i = false;
				break;
			}
		}	
	}
}

/// <summary>
/// Check if player is busted
/// If boolean value is false, round is over
/// </summary>
/// <returns></returns>
bool Game::checkPlayerHandCombined()
{
	bool result = true;
	cout << "Combined value of players cards: " << player.getSumOfHand() << endl;
	if (player.getSumOfHand() > maxValue)
	{
		cout << "Player is bust!" << endl;
		dealer.setScore();
		roundActive = false;
		result = false;
	}
	else if (player.getSumOfHand() == maxValue)
	{
		cout << "Player got BlacJack!" << endl;
		player.setScore();
		roundActive = false;
		result = false;
	}
	return result;
}

/// <summary>
/// Check if dealer is busted
/// If boolean value is false, round is over
/// </summary>
/// <returns></returns>
bool Game::checkDealerHandCombined()
{
	bool result = true;
	cout << "Combined value of dealers cards: " << dealer.getSumOfHand() << endl;

	if (dealer.getSumOfHand() > maxValue)
	{
		cout << "Dealer is bust!" << endl;
		player.setScore();
		roundActive = false;
		result = false;
	}
	else if (dealer.getSumOfHand() == maxValue)
	{
		cout << "Dealer got BlacJack!" << endl;
		dealer.setScore();
		roundActive = false;
		result = false;
	}
	else if (dealer.getSumOfHand() >= dealer.getTargetValue())
	{
		result = false;
	}
	return result;
}

/// <summary>
/// Get score of participants in the end of the round
/// </summary>
void Game::results()
{
	timer.useTimer();
	cout << "\nDealer's score: " << dealer.getScore() << " Player's score: " << player.getScore() << "\n" << endl;

	if (currentRound == 3 && dealer.getScore() < player.getScore())
		cout << "Player won!" << endl;
	else if (currentRound == 3)
		cout << "Dealer won!" << endl;
}