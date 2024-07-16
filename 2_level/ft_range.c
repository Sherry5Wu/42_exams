/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 08:18:44 by jingwu            #+#    #+#             */
/*   Updated: 2024/07/10 08:47:57 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int     *ft_range(int start, int end)
{
	int		*array;
	int		i = 0;
	int		size = 0;

	size = (start >= end)? (start - end + 1) : (end - start + 1);
	array = malloc(sizeof(int) * size);
	if (!array)
		return (0);
	if (start >= end)
	{
		while (i < size)
			array[i++] = start--;
	}
	else
	{
		while (i <  size)
			array[i++] = start++;
	}
	return (array);
}

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
	array = ft_range(start, end);
	for (int i = 0; i < len; i++)
		printf("%d\n", array[i]);
	free(array);
	return (0);
}

/*
Assignment name  : ft_range
Expected files   : ft_range.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_range(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at start and end at end (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 1, 2 and 3.
- With (-1, 2) you will return an array containing -1, 0, 1 and 2.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing 0, -1, -2 and -3.
*/