/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 11:13:47 by jingwu            #+#    #+#             */
/*   Updated: 2024/07/11 14:19:05 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		is_sep(char c)
{
	if (c == 32 || c == '\t' || c == '\n')
		return (1);
	else
		return (0);
}

int		count_word(char *str)
{
	int		words = 0;
	int		i = 0;

	if (!str)
		return (0);
	while (str[i])
	{
		if ((is_sep(str[i]) == 0) && (is_sep(str[i + 1]) == 1|| str[i + 1] == '\0'))
			words++;
		i++;
	}
	return (words);
}

void 	copy_word(char *dest, char *src, int start, int end)
{
	int	  i = 0;

	while (start < end)
	{
		dest[i] = src[start];
		i++;
		start++;
	}
	dest[i] = '\0';
	printf("copy_word:%s\n", dest);
}

void	split_word(char **result, char *str, int words)
{
	int		i = 0;
	int		j = 0;
	int		k = 0;

	while (j < words && str[i])
	{		
		while (str[i] && is_sep(str[i]) == 1)
			i++;
		while (str[i + k] && is_sep(str[i + k]) == 0)
			k++;
		result[j] = malloc(sizeof(char) * (k + 1));
		if (!result)
			return ;
		copy_word(result[j], str, i, (k + i));
		j++;
		i = i  + k;	
	}	
}

char    **ft_split(char *str)
{
	char 	**result;
	int		words = 0;

	words = count_word(str);
	result = malloc(sizeof(char*) * (words + 1));
	if (!result)
		return (NULL);
	result[words] = 0;
	if (words  > 0)
		split_word(result, str, words);
	return (result);
}

#include <stdio.h>

int		main(int ac, char **av)
{
	int		words;
	char 	**strs;	

	(void)ac;
	words = count_word(av[1]);
//	printf("words=%d\n", words);
	strs = ft_split(av[1]);
	for (int i = 0; i < words; i++)
		printf("%s\n", strs[i]);
}
/*
Assignment name  : ft_split
Expected files   : ft_split.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes a string, splits it into words, and returns them as
a NULL-terminated array of strings.

A "word" is defined as a part of a string delimited either by spaces/tabs/new
lines, or by the start/end of the string.

Your function must be declared as follows:

char    **ft_split(char *str);
*/