#include "House.h"
bool House::isHitting() const { return getTotal() <= 16; };
void House::flipFirstCard() {
	if (_cards.size() > 0)
		_cards[0]->flip();
};
House::House() : GenericPlayer("House") {};