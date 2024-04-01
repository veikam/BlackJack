#pragma once

#ifndef GAME_H
#define GAME_H

#include "Dealer.h"
#include "Player.h"
#include "Timer.h"
#include <iostream>

using namespace std;

class Game
{
private:
	int maxValue, currentRound;
	bool roundActive;
	Dealer dealer;
	Player player;
	Timer timer;

	void dealersTurn();
	void playersTurn();
	void initializeRound();
	void round();
	void endRound();
	bool checkPlayerHandCombined();
	bool checkDealerHandCombined();
	void results();

public:
	Game();
	~Game();
	void startGame();

protected:

};

#endif