/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 13:25:55 by jingwu            #+#    #+#             */
/*   Updated: 2024/07/03 09:44:47 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	first_word(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i] && (str[i] == 9 || str[i] == 32))
		i++;
	while (str[i] && str[i] != 9 && str[i] != 32)
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		first_word(av[1]);
	write(1, "\n", 1);
	return (1);
}
