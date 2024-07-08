/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:21:23 by jingwu            #+#    #+#             */
/*   Updated: 2024/07/04 14:29:11 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char    *ft_strdup(char *src)
{
	int		i;
	char	*newstr;

	i = 0;
	if (!src)
		return (NULL);
	while (src[i])
		i++;
	newstr = malloc(sizeof(char) * i + 1);
	if (!newstr)
		return (NULL);
	newstr[i] = '\0';
	while (i--)
		newstr[i] = src[i];
	return (newstr);
}

#include <stdio.h>

int main(void)
{
	printf("%s\n", ft_strdup("This is a test!"));
}

/*
Reproduce the behavior of the function strdup (man strdup).

Your function must be declared as follows:

char    *ft_strdup(char *src);

*/