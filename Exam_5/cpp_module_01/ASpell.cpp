#include "ASpell.hpp"
#include "ATarget.hpp"

ASpell::ASpell() : name_("default"), effects_("default"){}

ASpell::ASpell(const ASpell& other) : name_(other.name_),
effects_(other.effects_) {}

ASpell&	ASpell::operator=(const ASpell& other){
	if ( this != &other){
		name_ = other.name_;
		effects_ = other.effects_;
	}
	return *this;
}

ASpell::ASpell(const std::string& name, const std::string& effects)
: name_(name), effects_(effects){}

ASpell::~ASpell(){}

const std::string&	ASpell::getName() const{
	return name_;
}

const std::string&	ASpell::getEffects() const{
	return effects_;
}

void	ASpell::launch(const ATarget& target) const{
	target.getHitBySpell((*this));
}

