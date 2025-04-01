/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TargetGenerator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:46:25 by jingwu            #+#    #+#             */
/*   Updated: 2025/04/01 09:47:33 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include "ATarget.hpp"
#include <map>

class TargetGenerator{
	public:
		TargetGenerator();
		~TargetGenerator();

		void learnTargetType(ATarget* target);
		void forgetTargetType(std::string const & name);
		ATarget* createTarget(std::string const & name);

		// for debugging
		void	printTargets();

	private:
		std::map<std::string, ATarget*>	targets_;

		TargetGenerator(const TargetGenerator&);
		TargetGenerator&	operator=(const TargetGenerator&);
};
