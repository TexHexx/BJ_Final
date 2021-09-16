#pragma once
#include "GenericPlayer.h"
class House : public GenericPlayer {
public:
	virtual bool isHitting() const;
	void flipFirstCard();
	House();
	virtual ~House() {};
};