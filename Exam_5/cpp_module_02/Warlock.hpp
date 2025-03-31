#pragma once

#include <string>
#include <iostream>
#include <map>
#include "ASpell.hpp"
#include "ATarget.hpp"

// #include "ASpell.hpp" // rember to added this include here ex_01
#include "SpellBook.hpp"

class Warlock{
	private:
		std::string	name_;
		std::string	title_;

		// // added exercise 01
		// std::map<std::string, ASpell*> spells_;

		// added ex_02
		SpellBook book_;

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
		void	learnSpell(ASpell* spellName);
		void	forgetSpell(const std::string& spell);
		void	launchSpell(const std::string& spell, const ATarget& target);

		// for debugging
		// void	printBook();
};

