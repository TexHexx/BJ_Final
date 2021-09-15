#include "Player.h"
bool Player::isHitting() const {
	char answer;
	while (true)
	{
		std::cout << _name << " ,do you need more cards?(y/n): ";
		std::cin >> answer;
		switch (std::tolower(answer)) {
		case 'y':
			return true;
		case 'n':
			return false;
		default:
			std::cout << "Unrecognised answer, try again." << std::endl;
			continue;
		}
	}
};

void Player::win() const {
	std::cout << _name << " wins!" << std::endl;
};

void Player::lose() const {
	std::cout << _name << " loses!" << std::endl;
};

void Player::push() const {
	std::cout << _name << " pushes!" << std::endl;
};

Player::Player(const std::string& name) : GenericPlayer(name) {};