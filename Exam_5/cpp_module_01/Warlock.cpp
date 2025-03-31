#include "Warlock.hpp"

Warlock::Warlock(std::string name, std::string title) : name_(name),
title_(title){
	std::cout << name_ << ": This looks like another boring day.\n";
}

// Have changed here in exercice_02
Warlock::~Warlock(){
	std::cout << name_ << ": My job here is done!\n";
	std::map<std::string, ASpell*>::iterator begin = spells_.begin();
	std::map<std::string, ASpell*>::iterator end = spells_.end();
	while (begin != end){
		delete begin->second;
		begin++;
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

// carefule the for logic here
void	Warlock::learnSpell(ASpell* spell){
	if (spell){
		spells_.insert(std::pair<std::string, ASpell*>(spell->getName(), spell->clone()));
	}
}

void	Warlock::forgetSpell(const std::string& spellName){
	std::map<std::string, ASpell*>::iterator it = spells_.find(spellName);
	if (it != spells_.end()){
		delete it->second;
	}
	spells_.erase(spellName);
}

void	Warlock::launchSpell(const std::string& spellName, const ATarget& target){
	ASpell* spell = spells_[spellName];
	if (spell){
		spell->launch(target);
	}
}

