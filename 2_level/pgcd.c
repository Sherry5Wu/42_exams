/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 10:27:40 by jingwu            #+#    #+#             */
/*   Updated: 2024/07/10 10:48:11 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	hcd(unsigned int n, unsigned int m)
{
	unsigned int 	hdc;

	// the highest common denominator can't be greater than the smallest
	// of the two numbers
	hdc = (n >= m)? m : n; 
	while (hdc > 0)
	{
		if (n % hdc == 0 && m % hdc == 0)
		{
			printf("%u", hdc);
			return ;
		}
		hdc--;
	}
}

int		main(int ac, char **av)
{
	if (ac == 3)
		hcd((unsigned int)atoi(av[1]), (unsigned int)atoi(av[2]));
	printf("\n");
	return (0);
}

/*
Assignment name  : pgcd
Expected files   : pgcd.c
Allowed functions: printf, atoi, malloc, free
--------------------------------------------------------------------------------

Write a program that takes two strings representing two strictly positive
integers that fit in an int.

Display their highest common denominator followed by a newline (It's always a
strictly positive integer).

If the number of parameters is not 2, display a newline.

Examples:

$> ./pgcd 42 10 | cat -e
2$
$> ./pgcd 42 12 | cat -e
6$
$> ./pgcd 14 77 | cat -e
7$
$> ./pgcd 17 3 | cat -e 
1$
$> ./pgcd | cat -e
$
*/
