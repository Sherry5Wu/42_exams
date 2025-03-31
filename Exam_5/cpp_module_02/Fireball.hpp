#pragma once

#include <string>
#include <iostream>
#include "ASpell.hpp"

class Fireball : public ASpell{
	public:
		Fireball();
		~Fireball();

		ASpell*	clone() const override;
};
