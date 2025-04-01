/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpellBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:15:55 by jingwu            #+#    #+#             */
/*   Updated: 2025/04/01 11:36:03 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SpellBook.hpp"

SpellBook::SpellBook(){}

SpellBook::~SpellBook(){
	std::map<std::string, ASpell*>::iterator begin = spells_.begin();
	std::map<std::string, ASpell*>::iterator end = spells_.end();
	while (begin != end){
		delete begin->second;
		begin++;
	}
	spells_.clear(); // remember to clear the whole map;
}

void	SpellBook::learnSpell(ASpell* spell){
	if(spell){
		std::map<std::string, ASpell*>::iterator it = spells_.find(spell->getName());
		if (it == spells_.end()){
			spells_.insert(std::pair<std::string, ASpell*>(spell->getName(), spell->clone()));
		}
	}
}

void	SpellBook::forgetSpell(std::string const & name){
	std::map<std::string, ASpell*>::iterator it = spells_.find(name);
	if (it != spells_.end()){
		delete it->second;
	}
	spells_.erase(name);
}

ASpell*	SpellBook::createSpell(std::string const & name){
	std::map<std::string, ASpell*>::iterator	it = spells_.find(name);
	if (it != spells_.end()){
		return spells_[name];
	}
	return nullptr;
}

// for bebugging
void	SpellBook::printSpells(){
	std::map<std::string, ASpell*>::iterator begin = spells_.begin();
	std::map<std::string, ASpell*>::iterator end = spells_.end();
	std::cout << "Spells are: ";
	while (begin != end){
		 std::cout << begin->first << ", ";
		++begin;
	}
	std::cout << std::endl;
}
