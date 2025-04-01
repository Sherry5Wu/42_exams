#include "ATarget.hpp"
#include "ASpell.hpp"

ATarget::ATarget() : type_("default"){}

ATarget::ATarget(const ATarget& other) : type_(other.type_){}

ATarget&	ATarget::operator=(const ATarget& other){
	if ( this != &other){
		type_ = other.type_;
	}
	return *this;
}

ATarget::ATarget(const std::string& type) : type_(type){}

ATarget::~ATarget(){}

const std::string&	ATarget::getType() const{
	return type_;
}

void	ATarget::getHitBySpell(const ASpell& spell) const{
	std::cout << type_ << " has been " << spell.getEffects() << "!\n";
}
