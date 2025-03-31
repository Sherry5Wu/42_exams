/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 09:38:33 by jingwu            #+#    #+#             */
/*   Updated: 2024/07/10 10:15:14 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int    lcm(unsigned int a, unsigned int b)
{
	unsigned int		lcm = 0;

	if (!a || !b)
		return (0);
	lcm = (a > b)? a : b;
	while (1)
	{
		if (lcm % a == 0 && lcm % b == 0)
			return (lcm);
		lcm++;
	}	
}

// solution 2
// unsigned int	lcm(unsigned int a, unsigned int b)
// {
// 	int	gcd = 0;
// 	int	org_a = a;
// 	int	org_b = b;

// 	while (1)
// 	{
// 		if (a == 0)
// 			break;
// 		b %= a;
// 		if (b == 0)
// 			break;
// 		a %= b;
// 	}
// 	gcd = (!b) ? a : b;
// 	return (gcd ? (org_a / gcd * org_b) : 0);
// }

// below are only for test
#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	(void)ac;
	printf("LCM=%u\n", lcm((unsigned int)atoi(av[1]), (unsigned int)atoi(av[2])));
	return (0);
}

/*
Assignment name  : lcm
Expected files   : lcm.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function who takes two unsigned int as parameters and returns the 
computed LCM of those parameters.

LCM (Lowest Common Multiple) of two non-zero integers is the smallest postive
integer divisible by the both integers.

A LCM can be calculated in two ways:

- You can calculate every multiples of each integers until you have a common
multiple other than 0

- You can use the HCF (Highest Common Factor) of these two integers and 
calculate as follows:

	LCM(x, y) = | x * y | / HCF(x, y)
  
  | x * y | means "Absolute value of the product of x by y"

If at least one integer is null, LCM is equal to 0.

Your function must be prototyped as follows:

  unsigned int    lcm(unsigned int a, unsigned int b);
*/