#pragma once
#include "GenericPlayer.h"
class Player : public GenericPlayer {
public:
	virtual bool isHitting() const;

	void win() const;

	void lose() const;

	void push() const;

 	explicit Player(const std::string& );

	virtual ~Player() {};
};