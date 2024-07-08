/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camel_to_snake.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 10:39:20 by jingwu            #+#    #+#             */
/*   Updated: 2024/07/04 11:45:05 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Write a program that takes a single string in lowerCamelCase format
	and converts it into a string in snake_case format.

	A lowerCamelCase string is a string where each word begins with a capital letter
	except for the first one.

	A snake_case string is a string where each word is in lower case, separated by
	an underscore "_".

Examples:
$>./camel_to_snake "hereIsACamelCaseWord"
here_is_a_camel_case_word
$>./camel_to_snake "helloWorld" | cat -e
hello_world$
$>./camel_to_snake | cat -e
$
*/

#include <unistd.h>

int		main(int ac, char **av)
{
	int		i;

	if (ac == 2)
	{
		i = 0;
		while (av[1][i] != '\0')
		{
			if (av[1][i] >= 'A' && av[1][i] <= 'Z')
			{
				write(1, "_" ,1);
				av[1][i] += 32;
			}
			write(1, &av[1][i], 1);
			i++;
		}		
	}
	write(1, "\n", 1);
	return (0);
}