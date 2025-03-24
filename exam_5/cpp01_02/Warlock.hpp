#pragma once

#include <string>
#include <iostream>
#include <vector>
#include "ASpell.hpp" // rember to added this include here

class ASpell;
class ATarget;

class Warlock{
	private:
		std::string	name_;
		std::string	title_;

		// added exercise 02
		std::vector<ASpell*> spells_;


		Warlock();
		Warlock(const Warlock&);
		Warlock&	operator=(const Warlock&);

	public:
		Warlock(std::string name, std::string title);
		~Warlock();

		const std::string&	getName() const;
		const std::string&	getTitle() const;
		void	setTitle(const std::string& title);
		void	introduce() const;

		// // added exercise 02
		void	learnSpell(ASpell* spell);
		void	forgetSpell(const std::string& spell);
		void	launchSpell(const std::string& spell, const ATarget& target);
};