/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 10:47:21 by jingwu            #+#    #+#             */
/*   Updated: 2024/07/03 11:08:35 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

#include <stdlib.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		char *str = malloc(sizeof(char) * 100);
		printf("ft_strcpy(\"%s\", str) = %s \n", av[1], ft_strcpy(str, av[1]));
		free(str);
	}
	return (0);
}
