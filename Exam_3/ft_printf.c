/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 08:11:10 by jingwu            #+#    #+#             */
/*   Updated: 2024/09/17 08:31:05 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

int	put_str(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i])
	{
		len += write(1, &str[i], 1);
		i++;
	}
	return (len);
}

int	put_digit(long long int nbr, int base)
{
	int		len;
	char	*hexa;

	len = 0;
	hexa = "0123456789abcdef";
	if (nbr < 0)
	{
		nbr = nbr * (-1);
		len += write(1, "-", 1);
	}
	if (nbr >= base)
		len += put_digit((nbr / base), base);
	len += write(1, &hexa[nbr % base], 1);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	va_list	ptr;

	len = 0;
	va_start(ptr, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			if (*format == 's')
				len += put_str(va_arg(ptr, char *));
			else if (*format == 'd')
				len += put_digit((long long int)va_arg(ptr, int), 10);
			else if (*format == 'x')
				len += put_digit((long long int)va_arg(ptr, unsigned int), 16); // here is "unsigned int"
			else
				len += write(1, format, 1); // don't forget this condition.
		}
		else
			len += write(1, format, 1); // it is in else branch
		format++;
	}
	va_end(ptr); // here
	return (len);
}
//#if 0
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int	size;
	int len;

	size = 0;
	len = 0;
	ft_printf("testcase_1\n");
	size = ft_printf("%%\n");
	len = printf("%%\n");
	printf("size=%d\nlen=%d\n\n", size, len);

	ft_printf("testcase_2\n");
	size = ft_printf("%s\n", "toto");
	len = printf("%s\n", "toto");
	printf("size=%d\nlen=%d\n\n", size, len);

	ft_printf("testcase_3\n");
	size = ft_printf("Magic %s is %d\n", "number", 42);
	len = printf("Magic %s is %d\n", "number", 42);
	printf("size=%d\nlen=%d\n\n", size, len);

	ft_printf("testcase_4\n");
	size = ft_printf("Hexadecimal for %d is %x\n", -42, -42);
	len = printf("Hexadecimal for %d is %x\n", -42, -42);
	printf("size=%d\nlen=%d\n\n", size, len);

	ft_printf("testcase_5\n");
	size = ft_printf("%d %d %x\n", INT_MAX, INT_MIN, UINT_MAX);
	len = printf("%d %d %x\n", INT_MAX, INT_MIN, UINT_MAX);
	printf("size=%d\nlen=%d\n\n", size, len);

	ft_printf("testcase_6\n");
	size = ft_printf("%d, %d\n", 0, -24);
	len = printf("%d, %d\n", 0, -24);
	printf("size=%d\nlen=%d\n\n", size, len);

	ft_printf("testcase_7\n");
	size = ft_printf("Hello world\n");
	len = printf("Hello world\n");
	printf("size=%d\nlen=%d\n\n", size, len);

	ft_printf("testcase_8\n");
	size = ft_printf("");
	len = printf("");
	printf("size=%d\nlen=%d\n\n", size, len);

	return (0);
}

//# endif
