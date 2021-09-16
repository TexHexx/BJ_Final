#pragma once
#include "GenericPlayer.h"
#include <algorithm>

class Deck : public Hand {
public:
	bool deal(Hand& hand);
	void populate();
	void shuffle();
	bool additionalCards(GenericPlayer& player);
	virtual ~Deck() {};
};

