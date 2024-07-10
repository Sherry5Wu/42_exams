/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:12:48 by jingwu            #+#    #+#             */
/*   Updated: 2024/07/10 07:54:22 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	to_lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + ('a' - 'A'));
	return (c);
}

int get_value(char c)
{
	if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	else if (c >= '0' && c <= '9')
		return (c - '0');
	else
		return (-1);
}

int		is_valid(char c, int base)
{
	char digits[17] = "0123456789abcdef";
	char digits2[17] = "0123456789ABCDEF";

	while (base--)
		if (digits[base] == c || digits2[base] == c)
			return (1);
	return (0);
}

int ft_atoi_base(const char *str, int str_base)
{
	int result = 0;
	int sign = 1;
	int value;

	if (*str == '-')
	{
		sign = -1;
		++str;
	}
	while (is_valid(*str, str_base) && (value = get_value(*str) >= 0))
	{
		result = result * str_base + value;
		++str;
	}
	return (result * sign);
}

#include <stdio.h>

int		main(void)
{
	printf("num=%d\n", ft_atoi_base("ah", 16));
}

/*
Assignment name  : ft_atoi_base
Expected files   : ft_atoi_base.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str (base N <= 16)
to an integer (base 10) and returns it.

The characters recognized in the input are: 0123456789abcdef
Those are, of course, to be trimmed according to the requested base. For
example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".

Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".

Minus signs ('-') are interpreted only if they are the first character of the
string.

Your function must be declared as follows:

int	ft_atoi_base(const char *str, int str_base);
*/