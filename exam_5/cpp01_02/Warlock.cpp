#include "Warlock.hpp"

Warlock::Warlock(std::string name, std::string title) : name_(name),
title_(title){
	std::cout << name_ << ": This looks like another boring day.\n";
}

// Have changed here in exercice_02
Warlock::~Warlock(){
	std::cout << name_ << ": My job here is done!\n";
	std::vector<ASpell*>::iterator ite = spells_.end();
	for (std::vector<ASpell*>::iterator i = spells_.begin(); i != ite; ++i){
		delete *i;
	}
	spells_.clear();
}

const std::string&	Warlock::getName() const{
	return name_;
}

const std::string&	Warlock::getTitle() const{
	return title_;
}

void	Warlock::setTitle(const std::string& title){
	title_ = title;
}

void	Warlock::introduce() const{
	std::cout << name_ << ": I am " << name_  << ", " << title_ << "!\n";
}

/*--------------------------added at exercise_02-------------------------------------------*/

void	Warlock::learnSpell(ASpell* spell){
	if (spell){
		std::vector<ASpell*>::iterator ite = spells_.end();
		for (std::vector<ASpell*>::iterator i = spells_.begin(); i != ite; ++i){
			if ((*i)->getName() == spell->getName()){
				std::cout << "Here return" << std::endl; // for debugging
				return ;
			}
			std::cout << "Here" << std::endl; // for debugging
			spells_.push_back(spell->clone());
		}
	}
}

void	Warlock::forgetSpell(const std::string& spell){
	std::vector<ASpell*>::iterator ite = spells_.end();
		for (std::vector<ASpell*>::iterator i = spells_.begin(); i != ite; ++i){
			if ((*i)->getName() == spell){
				delete *i;
				i = spells_.erase(i);
			}
		}
}

void	Warlock::launchSpell(const std::string& spell, const ATarget& target){
	std::vector<ASpell*>::iterator ite = spells_.end();
		for (std::vector<ASpell*>::iterator i = spells_.begin(); i != ite; ++i){
			if ((*i)->getName() == spell){
				std::cout << "I am at launch" << std::endl;
				(*i)->launch(target);
			}
		}
}