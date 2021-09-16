#pragma once
#include "Card.h"

class Hand {
private:
	int MAX_CARDS = 7;
	int const ACE_ADDITION = 10;
protected:
	std::vector<Card*> _cards;
public:
	int const BJ = 21;
	Hand();
	void clear();
	void add(Card& );
	int getTotal() const;
	const std::vector<Card*>& getCards() const;
	virtual ~Hand();
};

