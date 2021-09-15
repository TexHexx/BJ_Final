#include "Game.h"

Game::Game(const std::vector<std::string>& names) {
	_deck.clear();
	_deck.populate();
	_deck.shuffle();

	_players.clear();
	_players.reserve(names.size());
	for (auto name : names) {
		_players.push_back(Player(name));
	};
};

void Game::play() {
	for (int i = 0; i < 2; ++i) {
		_deck.deal(_house);
		if (i == 1) {
			_house.flipFirstCard();
			std::cout << _house << std::endl;
		}
		for (auto _player = _players.begin(); _player < _players.end(); ++_player) {
			_deck.deal(*_player);
			if (i == 1) {
				std::cout << *_player << std::endl;
			}
		};
	};

	for (auto _player = _players.begin(); _player < _players.end(); ++_player) {
		if (!_deck.additionalCards(*_player))
			break;
	};

	_house.flipFirstCard();
	std::cout << _house << std::endl;
	_deck.additionalCards(_house);
	
	if (_house.isBoosted()) {
		for (auto _player = _players.begin(); _player < _players.end(); ++_player) {
			if (!_player->isBoosted()) {
				_player->win();
			}
			else {
				_player->lose();
			}
		}
	}
	else {
		for (auto _player = _players.begin(); _player < _players.end(); ++_player) {
			if (_player->isBoosted()) {
				_player->lose();
			}
			else {
				if (_player->getTotal() > _house.getTotal()) {
					_player->win();
				}
				else if (_player->getTotal() == _house.getTotal()) {
					_player->push();
				}
				else {
					_player->lose();
				}
			}
		};
	};

	for (auto _player = _players.begin(); _player < _players.end(); ++_player) {
		_player->clear();
	};
	_house.clear();
}