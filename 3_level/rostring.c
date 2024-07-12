/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 07:32:16 by jingwu            #+#    #+#             */
/*   Updated: 2024/07/12 08:55:52 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rostr(char *str)
{
	int		i = 0;
	int		f_start;
	
	// find the start of the first word
	while (str[i] && (str[i] == 32 || str[i] == '\t'))
		i++;
	f_start = i;
	// skip the first word
	while (str[i] && str[i] != 32 && str[i] != '\t')
		i++;
	// skip the whitespace before the second word
	while (str[i] && (str[i] == 32 || str[i] == '\t'))
		i++;
	// loop the rest of the str	
	while (str[i])
	{
		// find the start of each word
		if ((str[i] && str[i] != 32 && str[i] != '\t') && (str[i - 1] == 32 || str[i - 1] == '\t'))
		{
			// loop to print the word
			while (str[i] && str[i] != 32 && str[i] != '\t')
			{
				write(1, &str[i], 1);
				i++;
			}
			// print a space after print each word
			write(1, " ", 1);
		}
		i++;
	}
	// print the first word
	while (str[f_start] && (str[f_start] != 32 && str[f_start] != '\t'))
	{
		write(1, &str[f_start], 1);
			f_start++;
	}	
}

int		main(int ac, char **av)
{
	if (ac > 1)
		rostr(av[1]);
	write(1, "\n",  1);
	return (0);
}

/*
Assignment name  : rostring
Expected files   : rostring.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string and displays this string after rotating it
one word to the left.

Thus, the first word becomes the last, and others stay in the same order.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

Words will be separated by only one space in the output.

If there's less than one argument, the program displays \n.

Example:

$>./rostring "abc   " | cat -e
abc$
$>
$>./rostring "Que la      lumiere soit et la lumiere fut"
la lumiere soit et la lumiere fut Que
$>
$>./rostring "     AkjhZ zLKIJz , 23y"
zLKIJz , 23y AkjhZ
$>
$>./rostring "first" "2" "11000000"
first
$>
$>./rostring | cat -e
$
$>
*/