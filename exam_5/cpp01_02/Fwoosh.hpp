#pragma once

#include <string>
#include <iostream>
#include "ASpell.hpp"

class Fwoosh : public ASpell{
	public:
		Fwoosh();
		~Fwoosh();

		ASpell*	clone() const override;
};