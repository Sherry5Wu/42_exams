/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 10:16:55 by jingwu            #+#    #+#             */
/*   Updated: 2024/07/05 10:44:31 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// int		max(int* tab, unsigned int len)
// {
// 	int		i;
// 	int		temp;

// 	if (len == 0)
// 		return (0);
// 	i = 1;
// 	while (i < len)
// 	{
// 		if (tab[0] < tab[i])
// 		{
// 			temp = tab[0];
// 			tab[0] = tab[i];
// 			tab[i] = temp;
// 		}
// 		i++;
// 	}
// 	return (tab[0]);
// }

// solution 2
int		max(int* tab, unsigned int len)
{
	unsigned int		i;
	int		max;

	if (len == 0)
		return (0);
	i = 1;
	max =  tab[0];
	while (i < len)
	{
		if (max < tab[i])
			max = tab[i];
		i++;
	}
	return (max);
}

#include <stdio.h>

int		main(void)
{
	int	tab[6] = {10,3, 765, 39, 0, 34};
	
	printf("max=%d\n", max(tab, 6));
	return (0);
}

/*
Assignment name  : max
Expected files   : max.c
Allowed functions:
--------------------------------------------------------------------------------

Write the following function:

int		max(int* tab, unsigned int len);

The first parameter is an array of int, the second is the number of elements in
the array.

The function returns the largest number found in the array.

If the array is empty, the function returns 0.

*/