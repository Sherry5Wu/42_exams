/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 14:38:10 by jingwu            #+#    #+#             */
/*   Updated: 2024/07/08 08:29:14 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// Return 1, if found character c in the first n letters of the str; 
// otherwise return 0;
int		double_check(char c, char * str, int n)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
	while (i < n)
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

/*
	1. first output s1: check if the letter doubled before output;
	2. then output s2: if the letter is not doubled in s1 and s2, then output;
*/
void	ft_union(char *s1, char *s2)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (!s1 && !s2)
		return ;
	while (s1[i])
	{
		if (double_check(s1[i], s1, i) == 0)
			write(1, &s1[i], 1);
		i++;
	}
	while(s2[j])
	{
		if ((double_check(s2[j], s1, i) == 0) && (double_check(s2[j], s2, j) == 0))
			write(1, &s2[j], 1);
		j++;
	}
}

int		main(int ac, char **av)
{
	if (ac == 3)
		ft_union(av[1], av[2]);
	write(1, "\n", 1);
	return (0);
}

/*
Assignment name  : union
Expected files   : union.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in either one of the strings.

The display will be in the order characters appear in the command line, and
will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Example:

$>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
zpadintoqefwjy$
$>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6vewg4thras$
$>./union "rien" "cette phrase ne cache rien" | cat -e
rienct phas$
$>./union | cat -e
$
$>
$>./union "rien" | cat -e
$
$>
*/