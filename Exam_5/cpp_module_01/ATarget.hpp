#pragma once

#include <string>
#include <iostream>
class ASpell;

class ATarget{
	private:
		std::string	type_;

	public:
		ATarget();
		ATarget(const ATarget& other);
		ATarget&	operator=(const ATarget& other);

		ATarget(const std::string& type);
		virtual	~ATarget();

		const std::string&	getType() const;
		virtual ATarget*	clone() const = 0;
		void	getHitBySpell(const ASpell& spell) const;
};
