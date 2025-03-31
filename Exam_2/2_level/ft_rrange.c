/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 08:44:29 by jingwu            #+#    #+#             */
/*   Updated: 2024/07/10 08:59:43 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int     *ft_rrange(int start, int end)
{
	int		*array;
	int		i = 0;
	int		size =0;

	size = abs(start - end) + 1;
	array = malloc(sizeof(int) * size);
	if (!array)
		return (0);
	while (i < size)
	{
		if (start <= end)
			array[i] = end--;
		else
			array[i] = end++;
		i++;
	}
#if 0  
	if (start > end) // another way to assign values
		step = 1;
	else
		step = -1;

	i = 0;
	while (i < number_of_ints)
	{
		array[i] = end;
		end = end + step;
		++i;
	}
# endif

	return (array);
}



// below is for testing only
#include <stdio.h>
#include <stdlib.h>

int		main(int ac, char **av)
{
	int		*array;
	int		len;
	int		start = atoi(av[1]);
	int		end = atoi(av[2]);

	(void)ac;
	len = abs(start - end) + 1;
	array = ft_rrange(start, end);
	for (int i = 0; i < len; i++)
		printf("%d, ", array[i]);
	free(array);
	return (0);
}

/*
Assignment name  : ft_rrange
Expected files   : ft_rrange.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_rrange(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at end and end at start (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 3, 2 and 1
- With (-1, 2) you will return an array containing 2, 1, 0 and -1.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing -3, -2, -1 and 0.
*/