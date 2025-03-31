/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 11:29:18 by jingwu            #+#    #+#             */
/*   Updated: 2024/07/15 13:12:39 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	output_char(char c, int repeat)
{
	while (repeat--)
		write(1, &c, 1);
}

void	repeat_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i])	
	{
		if (str[i] >= 65 && str[i] <= 90)
			output_char(str[i], (str[i] - 65 + 1));
		else if (str[i] >= 97 && str[i] <= 122)
			output_char(str[i], (str[i] - 97 + 1));
		else
			output_char(str[i], 1);
		i++;
	}
}

int	main(int ac, char ** av)
{
	if (ac == 2)
		repeat_alpha(av[1]);
	output_char('\n', 1);
	return (0);
}

/*
Assignment name  : repeat_alpha
Expected files   : repeat_alpha.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program called repeat_alpha that takes a string and display it
repeating each alphabetical character as many times as its alphabetical index,
followed by a newline.

'a' becomes 'a', 'b' becomes 'bb', 'e' becomes 'eeeee', etc...

Case remains unchanged.

If the number of arguments is not 1, just display a newline.

Examples:

$>./repeat_alpha "abc"
abbccc
$>./repeat_alpha "Alex." | cat -e
Alllllllllllleeeeexxxxxxxxxxxxxxxxxxxxxxxx.$
$>./repeat_alpha 'abacadaba 42!' | cat -e
abbacccaddddabba 42!$
$>./repeat_alpha | cat -e
$
$>
$>./repeat_alpha "" | cat -e
$
$>
*/