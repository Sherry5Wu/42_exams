#pragma once

#include <string>
#include <iostream>
#include "ATarget.hpp"

class BrickWall : public ATarget{
	public:
		BrickWall();
		~BrickWall();

		ATarget*	clone() const override;
};
