#include "Deck.h"

void Deck::populate() {
	clear();
	for (int suit = static_cast<int>(cardSuits::heart); suit <= static_cast<int>(cardSuits::diamond); ++suit) {
		for (int value = static_cast<int>(cardValues::_A); value <= static_cast<int>(cardValues::_K); ++value) {
			_cards.push_back(new Card(static_cast<cardSuits>(suit), static_cast<cardValues>(value)));
		}
	}
};

void Deck::shuffle() {
	std::srand(time(0));
	std::random_shuffle(_cards.begin(), _cards.end());
};

bool Deck::deal(Hand& hand) {
	if (!_cards.empty()) {
		hand.add(*_cards.back());
		_cards.pop_back();
		return true;
	}
	return false;
};

bool Deck::additionalCards(GenericPlayer& player) {
	while ((!player.isBoosted()) && (player.isHitting())) {
		if (!deal(player)) {
			std::cout << "No more cards in a deck!" << std::endl;
			return false;
		};
		std::cout << player << std::endl;
		if (player.isBoosted()) {
			player.bust();
			break;
		};
		if (player.getTotal() == player.BJ) {
			break;
		}
	};
	return true;
};