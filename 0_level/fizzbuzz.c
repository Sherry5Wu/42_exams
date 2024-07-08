/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 09:40:22 by jingwu            #+#    #+#             */
/*   Updated: 2024/07/03 10:40:31 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	output_num(int num)
{
	if (num > 9)
		output_num(num / 10);
	write(1, &"0123456789"[num % 10], 1);
}

int	main(void)
{
	int	n;

	n = 1;
	while (n <= 100)
	{
		if ((n % 3 == 0) && (n % 5 == 0))
			write(1, "fizzbuzz", 8);
		else if (n % 3 == 0)
			write(1, "fizz", 4);
		else if (n % 5 == 0)
			write(1, "buzz", 4);
		else
			output_num(n);
		write(1, "\n", 1);
		n++;
	}
}
