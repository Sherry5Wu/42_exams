/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 09:00:30 by jingwu            #+#    #+#             */
/*   Updated: 2024/07/10 09:38:09 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// solution 1
// void	hidenp(char *s1, char *s2)
// {
// 	int		i = 0;
// 	int		j = 0;
// 	if (!*s1)
// 		write(1, "1", 1);
// 	while (s1[i])
// 	{
// 		while (s2[j])
// 		{
// 			if (s2[j] == s1[i])
// 			{
// 				i++;
// 				j++;
// 				break ;
// 			}
// 			else
// 				j++;
// 		}
// 		if (!s2[j])
// 		{
// 			write(1, "0", 1);
// 			return ;
// 		}
// 		if (!s1[i + 1])
// 		{
// 			write (1, "1", 1);
// 			return ;
// 		}	
// 	}
// }

// solution 2
void	hidenp(char *s1, char *s2)
{
	int		i = 0;
	int 	j = 0;

	while (s1[i])
	{
		while (s1[i] != s2[j] && s2[j] != '\0')
			j++;
		if (s2[j] == '\0')
		{
			write(1, "0", 1);
			return ;
		}
		i++;
		j++;
	}
	write(1, "1", 1);
}

int		main(int ac, char **av)
{
	if (ac == 3)
		hidenp(av[1], av[2]);
	write(1, "\n", 1);
	return (0);
}

/*
Assignment name  : hidenp
Expected files   : hidenp.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program named hidenp that takes two strings and displays 1
followed by a newline if the first string is hidden in the second one,
otherwise displays 0 followed by a newline.

Let s1 and s2 be strings. We say that s1 is hidden in s2 if it's possible to
find each character from s1 in s2, in the same order as they appear in s1.
Also, the empty string is hidden in any string.

If the number of parameters is not 2, the program displays a newline.

Examples :

$>./hidenp "fgex.;" "tyf34gdgf;'ektufjhgdgex.;.;rtjynur6" | cat -e
1$
$>./hidenp "abc" "2altrb53c.sse" | cat -e
1$
$>./hidenp "abc" "btarc" | cat -e
0$
$>./hidenp | cat -e
$
$>
*/