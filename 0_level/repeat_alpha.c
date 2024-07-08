/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 11:29:18 by jingwu            #+#    #+#             */
/*   Updated: 2024/07/03 11:46:05 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	output_char(char c, int repeat)
{
	while (repeat--)
		write(1, &c, 1);
}

void	repeat_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i])	
	{
		if (str[i] >= 65 && str[i] <= 90)
			output_char(str[i], (str[i] - 65 + 1));
		else if (str[i] >= 97 && str[i] <= 122)
			output_char(str[i], (str[i] - 97 + 1));
		else
			output_char(str[i], 1);
		i++;
	}
}

int	main(int ac, char ** av)
{
	if (ac == 2)
		repeat_alpha(av[1]);
	output_char('\n', 1);
	return (0);
}
