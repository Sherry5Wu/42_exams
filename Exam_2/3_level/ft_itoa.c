/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 09:25:30 by jingwu            #+#    #+#             */
/*   Updated: 2024/07/11 11:01:55 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

unsigned int	get_size(int nb)
{
	unsigned int	size = 0;

	if ( nb <= 0)
		size++;
	while (nb != 0)
	{
		nb /= 10;
		size++;
	}
	return (size);
}

int		abs_value(int num)
{
	if (num < 0)
		return (-num);
	else
		return (num);
}

char	*ft_itoa(int nbr)
{
	char  	*str;
	int		size = 0;

	size = get_size(nbr);
	str = malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	str[size] = '\0';
	if (nbr < 0)
		str[0] = '-';
	if (nbr == 0)
		str[0] = '0';
	// put in the value from the end of the string.
	while (nbr != 0)
	{
		size--;
		str[size] = abs_value(nbr % 10) + '0';
		nbr /= 10;
	}
	return (str);
}

#include <stdio.h>

int	main(int ac, char **av)
{
	(void)ac;
	char *str = ft_itoa(atoi(av[1]));
	printf("str=%s\n", str);
	free(str);
	return (0);
}

/*
Assignment name  : ft_itoa
Expected files   : ft_itoa.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes an int and converts it to a null-terminated string.
The function returns the result in a char array that you must allocate.

Your function must be declared as follows:

char	*ft_itoa(int nbr);
*/