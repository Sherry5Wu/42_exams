#pragma once

#include <string>
#include <iostream>

class ATarget;

class ASpell{
	protected:
		std::string	name_;
		std::string	effects_;

	public:
		ASpell();
		ASpell(const ASpell& other);
		ASpell&	operator=(const ASpell& other);

		ASpell(const std::string& name, const std::string& effects);
		virtual	~ASpell();

		const std::string&	getName() const;
		const std::string&	getEffects() const;
		virtual ASpell*	clone() const = 0;
		void	launch(const ATarget& target) const;
};
