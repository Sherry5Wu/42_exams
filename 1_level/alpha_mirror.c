/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 08:47:41 by jingwu            #+#    #+#             */
/*   Updated: 2024/07/04 11:45:43 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Write a program called alpha_mirror that takes a string and displays this string
after replacing each alphabetical character by the opposite alphabetical
character, followed by a newline.

'a' becomes 'z', 'Z' becomes 'A'
'd' becomes 'w', 'M' becomes 'N'

and so on.

Case is not changed.

If the number of arguments is not 1, display only a newline.

Examples:

$>./alpha_mirror "abc"
zyx
*/

#include <unistd.h>

int	main(int ac, char **av)
{
	int	i;

	if (ac == 2)
	{
		i = 0;
		while(av[1][i] != '\0')
		{
			if ((av[1][i] >= 'A' && av[1][i] <= 'Z') )
				av[1][i] = 'A' + 'Z' - av[1][i];
			else if (av[1][i] >= 'a' && av[1][i] <= 'z')
				av[1][i] = 'a' + 'z' - av[1][i];
			write(1, &av[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
