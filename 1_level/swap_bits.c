/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 12:49:18 by jingwu            #+#    #+#             */
/*   Updated: 2024/07/05 14:35:28 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char	swap_bits(unsigned char octet)
{
	return ((octet >> 4) | (octet << 4));
}

#include <stdio.h>

int main() 
{
    unsigned char test_cases[] = {
        0b00001111, // 15
        0b11110000, // 240
        0b10101010, // 170
        0b01010101, // 85
        0b11001100, // 204
        0b00110011, // 51
        0b00000000, // 0
        0b11111111  // 255
    };

    int num_cases = sizeof(test_cases) / sizeof(test_cases[0]);

    for (int i = 0; i < num_cases; i++) {
        unsigned char original = test_cases[i];
        unsigned char swapped = swap_bits(original);

        printf("Original: 0x%02X, Swapped: 0x%02X\n", original, swapped);
    }

    return 0;
}

/*
Assignment name  : swap_bits
Expected files   : swap_bits.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that takes a byte, swaps its halves (like the example) and
returns the result.

Your function must be declared as follows:

unsigned char	swap_bits(unsigned char octet);

Example:

  1 byte
_____________
 0100 | 0001
     \ /
     / \
 0001 | 0100
*/