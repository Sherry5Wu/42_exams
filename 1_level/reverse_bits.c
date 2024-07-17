/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 08:17:44 by jingwu            #+#    #+#             */
/*   Updated: 2024/07/17 08:44:18 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char	c = 0;
	unsigned int	i = 8;
	
	while (i--) // while loop repeats 8 times
	{
		// (octec & 1) get the first bit n ;
		// (c >> 1) move 1 bit left;
		// then "|" with (c >> 1) , then pass the bit n to c
		c = (c << 1) | (octet & 1);
		// octect = octet >> 1; Move the bit needed to deal with to the location bit[0].
		octet >>= 1; 
	}
	return (c);
}

/*
Assignment name  : reverse_bits
Expected files   : reverse_bits.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that takes a byte, reverses it, bit by bit (like the
example) and returns the result.

Your function must be declared as follows:

unsigned char	reverse_bits(unsigned char octet);

Example:

  1 byte
_____________
 0100  0001
     ||
     \/
 1000  0010
*/