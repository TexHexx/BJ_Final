#pragma once
#include "Deck.h"
#include "House.h"
#include "Player.h"
class Game
{
private:
	Deck _deck;
	House _house;
	std::vector<Player> _players;
public:
	explicit Game(const std::vector<std::string>&);
	void play();
};