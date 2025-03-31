#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator(){}

TargetGenerator::~TargetGenerator(){
	std::map<std::string, ATarget*>::iterator begin = targets_.begin();
	std::map<std::string, ATarget*>::iterator end = targets_.end();
	while (begin != end){
		delete begin->second;
		++begin;
	}
	targets_.clear();
}

void TargetGenerator::learnTargetType(ATarget* target){
	if(target){
		targets_.insert(std::pair<std::string, ATarget*>(target->getType(), target->clone()));
	}
}

void TargetGenerator::forgetTargetType(std::string const & name){
	std::map<std::string, ATarget*>::iterator it = targets_.find(name);
	if (it != targets_.end()){
		delete it->second;
	}
	targets_.erase(name);
}

ATarget* TargetGenerator::createTarget(std::string const & name){
	std::map<std::string, ATarget*>::iterator	it = targets_.find(name);
	if (it != targets_.end()){
		return targets_[name];
	}
	return nullptr;
}


/*<------------------for debugging------------------->*/
// void	TargetGenerator::printTargets(){
// 	std::map<std::string, ATarget*>::iterator begin = targets_.begin();
// 	std::map<std::string, ATarget*>::iterator end = targets_.end();
// 	std::cout << "Targets are: ";
// 	while (begin != end){
// 		 std::cout << begin->first << ", ";
// 		++begin;
// 	}
// 	std::cout << std::endl;
// }
