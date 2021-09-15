#include "Hand.h"


Hand::Hand() { _cards.reserve(MAX_CARDS); };

void Hand::add(Card& card) { _cards.push_back(&card); };

int Hand::getTotal() const {
	bool hasAce = false;
	int result = 0;
	for (auto card : _cards) {
		int cardValue = card->getValue();
		if (cardValue == 1)
			hasAce = true;
		result += card->getValue();
	};
	if (((result + ACE_ADDITION) <= BJ) && hasAce)
		result += ACE_ADDITION;
	return result;
};

Hand::~Hand() { 
	clear();
};

void Hand::clear() {
	for (auto card : _cards)
		delete card;
	_cards.clear();
};

const std::vector<Card*>& Hand::getCards() const { return _cards; };