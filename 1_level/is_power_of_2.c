/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 08:36:58 by jingwu            #+#    #+#             */
/*   Updated: 2024/07/15 13:01:35 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// solution 1
// int	    is_power_of_2(unsigned int n)
// {
// 	if (n == 0)
// 		return (0);
// 	while (n > 1)
// 	{
// 		if (n % 2 == 0)
// 			n = n / 2;
// 		else
// 			return (0);
// 	}
// 	return (1);
// }

// solution 2
/*
This line of code uses bitwise operations to determine if n is a power of 2.
n & (n - 1) is the key bitwise operation. This operation takes advantage of the 
characteristics of binary representation.
For example, if n is a power of 2, then only one bit in its binary representation 
is 1, and the rest are 0.
For example, 8 (2^3) is represented as 1000 in binary.
n - 1 will make the only 1 bit of n become 0, and all bits to the right of it 
become 1.
For example, 7 (8 - 1) is represented as 0111 in binary.
The bitwise AND operation (&) of n and n - 1 will result in 0.
For example, 1000 & 0111 = 0000.
Therefore, if n is a power of 2, then (n & (n - 1)) must be 0. If it is not 
a power of 2, the result is not 0.
In summary, this code uses bitwise operations to determine if a number is 
a power of 2. If the number is a power of 2, then (n & (n - 1)) equals 0 and 
the function returns 1; otherwise, it returns 0.
*/

int is_power_of_2(unsigned int n)
{
    if (n == 0)
        return (0);
    return ((n & (n - 1)) == 0);
}

// solution 2

#if 0

int		is_power_of_2(unsigned int n)
{
	if (n == 0)
		return (0);
	while (n % 2 == 0) 
		n /= 2;
	return ((n == 1) ? 1 : 0);
}

#endif

#include <stdio.h>

int	main(void)
{
	printf("%d\n", is_power_of_2(1024));
	printf("%d\n", is_power_of_2(1023));
	printf("%d\n", is_power_of_2(0));
	printf("%d\n", is_power_of_2(1));
}

/*
Assignment name  : is_power_of_2
Expected files   : is_power_of_2.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that determines if a given number is a power of 2.

This function returns 1 if the given number is a power of 2, otherwise it returns 0.

Your function must be declared as follows:

int	    is_power_of_2(unsigned int n);

*/