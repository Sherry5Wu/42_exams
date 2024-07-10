/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 08:31:31 by jingwu            #+#    #+#             */
/*   Updated: 2024/07/08 10:07:59 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// based on the current case, this is a simply version of atoi.
int		ft_atoi(char *str)
{
	int		num = 0;
	int		i = 0;

	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num);	
}

int		is_prime(int n)
{
	int		i;

	i = 2;
	while (i < n)
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (1);
}

// because the passed argument will be always postive number, so don't chekc 
// negitive case here.
void	print_num(int	num)
{
	char 	c;

	if (num > 9)
		print_num (num / 10);
	c = (num % 10) + '0';
	write (1, &c, 1);
}

int	add_prime_sum(int	num)
{
	int		sum;
	int		i;

	sum  = 0;
	i = 2;
	while (i <= num)
	{
		if (is_prime(i) == 1)
			sum += i;
		i++;
	}
	return (sum);
}

int		main(int ac, char **av)
{
	if (ac == 2 && ft_atoi(av[1]) > 0)
		print_num(add_prime_sum(ft_atoi(av[1])));
	else
	 	print_num(0);
	write(1, "\n", 1);
	return (0);
}


/*
Assignment name  : add_prime_sum
Expected files   : add_prime_sum.c
Allowed functions: write, exit
--------------------------------------------------------------------------------

Write a program that takes a positive integer as argument and displays the sum
of all prime numbers inferior or equal to it followed by a newline.

If the number of arguments is not 1, or the argument is not a positive number,
just display 0 followed by a newline.

Yes, the examples are right.

Examples:

$>./add_prime_sum 5
10
$>./add_prime_sum 7 | cat -e
17$
$>./add_prime_sum | cat -e
0$
$>
*/