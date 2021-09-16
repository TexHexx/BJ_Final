#include "Card.h"

Card::Card(cardSuits suit, cardValues value, bool position) : _suit(suit), _value(value), _position(position) {};

void Card::flip() { _position = !_position; };

int Card::getValue() const {
	if (!_position)
		return 0;
	return static_cast<int>(_value) > 10 ? 10 : static_cast<int>(_value);
};

const std::string& Card::getPrintSuit() const { return _suitPresentation.at(static_cast<int>(_suit)); };

const std::string& Card::getPrintValue() const { return _valuePresentation.at(static_cast<int>(_value) - 1); };

bool Card::isFlipped() const { return _position; };

std::ostream& operator<< (std::ostream& out, const Card& card)
{
	out << (card.isFlipped() ? (card.getPrintValue() + "|" + card.getPrintSuit()) : "X|X");
	return out;
}