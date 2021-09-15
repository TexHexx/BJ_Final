#pragma once
#include "Hand.h"
class GenericPlayer : public Hand
{
protected:
	std::string _name;
public:
	virtual bool isHitting() const = 0;
	bool isBoosted() const;
	void bust() const;
	const std::string& getName() const;
	explicit GenericPlayer(const std::string& );
	virtual ~GenericPlayer() {};
};

std::ostream& operator<< (std::ostream&, const GenericPlayer& );
