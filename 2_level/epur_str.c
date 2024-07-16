/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 08:28:06 by jingwu            #+#    #+#             */
/*   Updated: 2024/07/16 08:54:03 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	epur_str(char *str)
{
	int		i = 0;
	int		space = 1;
	
	while (str[i] && (str[i] == 32 || str[i] == '\t'))
		i++;
	while (str[i])
	{
		while (str[i] && (str[i] == 32 || str[i] == '\t'))
		{
			space = 1;
			i++;
		}
		if (!str[i])
			return ;
		if (space == 1)
		{
			write(1, " ", 1);
			space = 0;			
		}
		while (str[i] && (str[i] != 32 && str[i] != '\t'))
		{
			write(1, &str[i], 1);
			i++;
		}
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
		epur_str(av[1]);
	write(1, "\n", 1);
	return (0);
}