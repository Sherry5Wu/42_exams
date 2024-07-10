/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 10:10:10 by jingwu            #+#    #+#             */
/*   Updated: 2024/07/08 11:06:02 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void 	epur_str(char *str)
{
	int		i = 0;
	int		flag = 0;
	
	if (!str)
		return ;
	while (str[i] && (str[i] == 32 || str[i] == '\t')) // pass the spaces and tabs in the beginning
			i++;
	while (str[i])
	{
		while (str[i] && (str[i] == 32 || str[i] == '\t'))
		{
			flag = 1;
			i++;
		}
		if(str[i] == '\0') // if it is the end of the str, then return. 
			return ;
		if (flag == 1)
			write(1, " ", 1);
		flag = 0;
		write(1, &str[i], 1);
		i++;
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
		epur_str(av[1]);
	write(1, "\n", 1);
	return (0);
}

/*
Assignment name  : epur_str
Expected files   : epur_str.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string, and displays this string with exactly one
space between words, with no spaces or tabs either at the beginning or the end,
followed by a \n.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

If the number of arguments is not 1, or if there are no words to display, the
program displays \n.

Example:

$> ./epur_str "See? It's easy to print the same thing" | cat -e
See? It's easy to print the same thing$
$> ./epur_str " this        time it      will     be    more complex  . " | cat -e
this time it will be more complex .$
$> ./epur_str "No S*** Sherlock..." "nAw S*** ShErLaWQ..." | cat -e
$
$> ./epur_str "" | cat -e
$
$>

$> ./epur_str "vous voyez c'est facile d'afficher la meme chose" | cat -e
vous voyez c'est facile d'afficher la meme chose$
$> ./epur_str " seulement          la c'est      plus dur " | cat -e
seulement la c'est plus dur$
$> ./epur_str "comme c'est cocasse" "vous avez entendu, Mathilde ?" | cat -e
$
$> ./epur_str "" | cat -e
$
$>
*/