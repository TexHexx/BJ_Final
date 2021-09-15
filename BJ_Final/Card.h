#pragma once
#include <iostream>
#include <vector>
#include <string>

enum class cardSuits { heart, spade, cross, diamond };
enum class cardValues { _A = 1, _2 = 2, _3 = 3, _4 = 4, _5 = 5, _6 = 6, _7 = 7, _8 = 8, _9 = 9, _10 = 10, _J = 11, _Q = 12, _K = 13 };

class Card {
private:
	cardSuits _suit;
	cardValues _value;
	bool _position;
	const std::vector<std::string> _suitPresentation { "H", "S", "C", "D" };
	const std::vector<std::string> _valuePresentation{ "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
public:
	Card(cardSuits, cardValues, bool = true);
	void flip();

	int getValue() const;

	const std::string& getPrintSuit() const;

	const std::string& getPrintValue() const;

	bool isFlipped() const;
};

std::ostream& operator<< (std::ostream&, const Card& );