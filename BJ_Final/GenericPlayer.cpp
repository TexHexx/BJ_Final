#include "GenericPlayer.h"

bool GenericPlayer::isBoosted() const { return getTotal() > 21; };
void GenericPlayer::bust() const { std::cout << _name << " has too much!" << std::endl; };
const std::string& GenericPlayer::getName() const { return _name; };
GenericPlayer::GenericPlayer(const std::string& name) : _name(name), Hand() {};

std::ostream& operator<< (std::ostream& out, const GenericPlayer& player)
{
	out << player.getName() << " ( ";
	auto _cards = player.getCards();
	for (auto card : _cards) {
		out << *card << " ";
	};
	out << ") " << player.getTotal();
	return out;
}
