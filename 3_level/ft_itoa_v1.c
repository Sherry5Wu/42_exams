//the solution is getting from 
// https://github.com/sayakura/42__Exams--Beginner/blob/master/4_ft_itoa.c

#include <stdlib.h>

char	*ft_itoa(int nbr)
{
	int	neg = (nbr < 0) ? 1 : 0;
	int size = (neg) ? 3 : 2;
	int temp = nbr;
	char *base = "0123456789";
	char *ptr;

	while (temp /= 10)
		size++;
	ptr = (char *)malloc(size);
	ptr[--size] = '\0';
	ptr[--size] = (nbr < 0) ? base[-(nbr % 10)] : base[nbr % 10];
	while (nbr /= 10)
		ptr[--size] = (nbr < 0) ? base[-(nbr % 10)] : base[nbr % 10];
	if (neg)
		ptr[--size] = '-';
	return (ptr);
}

#include <stdio.h>
int 	main(void)
{
	printf("%s\n", ft_itoa(-2147483648));
	printf("%s\n", ft_itoa(0));
	printf("%s\n", ft_itoa(2147483647));
	printf("%s\n", ft_itoa(1));
	return (0);
}