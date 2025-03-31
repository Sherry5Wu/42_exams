/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 13:54:03 by jingwu            #+#    #+#             */
/*   Updated: 2024/07/15 08:43:27 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void sort_int_tab(int *tab, unsigned int size)
{
	unsigned int		i = 0;
	unsigned int		j;
	int		*tmp;
	int		data;

	tmp = tab;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tmp[i] > tmp[j])
			{
				data = tmp[i];
				tmp[i] = tmp[j];
				tmp[j] = data;
			}
			j++;
		}
		i++;
	}
}

// solution 2
# if 0
void	swap_elements(int *tab, unsigned int p1, unsigned int p2)
{
	int tmp = tab[p1];
	tab[p1] = tab[p2];
	tab[p2] = tmp;
}

void	bubble_sort(int *tab, unsigned int size)
{
	unsigned int i = 0;
	unsigned int j = 0;

	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if (tab[j] > tab[j + 1])
				swap_elements(tab, j, j + 1);
			j++;
		}
		i++;
	}
}
#endif

// for testing only
#include <stdio.h>

void	print_arr(int *tab, unsigned int size)
{
	unsigned int i = 0;
	while (i < size)
	{
		printf("%d, ", tab[i]);
		++i;
	}
	printf("\n");
}

int		main(void)
{
	int tab[] = { 5, -10, 3, -2, 1, 0 };
	unsigned int size = sizeof(tab) / sizeof(*tab);

	print_arr(tab, size);
	sort_int_tab(tab, size);
	print_arr(tab, size);
}

/*
Assignment name  : sort_int_tab
Expected files   : sort_int_tab.c
Allowed functions: 
--------------------------------------------------------------------------------

Write the following function:

void sort_int_tab(int *tab, unsigned int size);

It must sort (in-place) the 'tab' int array, that contains exactly 'size'
members, in ascending order.

Doubles must be preserved.

Input is always coherent.
*/