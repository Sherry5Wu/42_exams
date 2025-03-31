/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpellBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:01:03 by jingwu            #+#    #+#             */
/*   Updated: 2025/03/31 13:11:27 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <map>

class ASpell;

class SpellBook{
	public:
		SpellBook();
		~SpellBook();

		void	learnSpell(ASpell* spell);
		void	forgetSpell(std::string const & name);
		ASpell*	createSpell(std::string const & name);

		// for debugging
		// void	printSpells();

	private:
		std::map<std::string, ASpell*> spells_;
		SpellBook(const SpellBook&);
		SpellBook& operator=(const SpellBook&); // why this one need to be here
};

#include "ASpell.hpp"
