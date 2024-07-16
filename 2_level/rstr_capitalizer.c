/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:29:47 by jingwu            #+#    #+#             */
/*   Updated: 2024/07/16 07:54:38 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
 loop the str, 
  1. if the current character is in a-z, then convert it to uppercase
	 if the next character IS space, tab or \0;
 2. if the current character is in A-Z, then convert it to lowercase
	if the next character is NOT space , tab or \0;
 
*/
void	rstr_c(char *str)
{
	int		i = 0;

	while (str[i])
	{
		if ((str[i] >= 'a' && str[i] <= 'z')  && (str[i + 1] == 32 || str[i + 1] == '\t' || str[i + 1] == '\0'))
			str[i] -= 32;				
		else if ((str[i] >= 'A' && str[i] <= 'Z') && (str[i + 1] != 32 && str[i + 1] != '\t' && str[i + 1] != '\0'))
			str[i] += 32;	
		write(1, &str[i], 1);
		i++;
	}
}

int		main(int ac, char **av)
{
	int		i;
	if (ac > 1)
	{
		i = 1;
		while (i < ac)
		{
			rstr_c(av[i]);
			write(1, "\n", 1);
			i++;
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}


/*
ssignment name  : rstr_capitalizer
Expected files   : rstr_capitalizer.c
Allowed functions: write
--------------------------------------------------------------------------------
Write a program that takes one or more strings and, for each argument, puts 
the last character that is a letter of each word in uppercase and the rest
in lowercase, then displays the result followed by a \n.

A word is a section of string delimited by spaces/tabs or the start/end of the
string. If a word has a single letter, it must be capitalized.

A letter is a character in the set [a-zA-Z]

If there are no parameters, display \n.

Examples:

$> ./rstr_capitalizer | cat -e
$
$> ./rstr_capitalizer "a FiRSt LiTTlE TESt" | cat -e
A firsT littlE tesT$
$> ./rstr_capitalizer "SecONd teST A LITtle BiT   Moar comPLEX" "   But... This iS not THAT COMPLEX" "     Okay, this is the last 1239809147801 but not    the least    t" | cat -e
seconD tesT A littlE biT   moaR compleX$
   but... thiS iS noT thaT compleX$
     okay, thiS iS thE lasT 1239809147801 buT noT    thE leasT    T$
$>
*/