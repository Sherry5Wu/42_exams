/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 13:57:49 by jingwu            #+#    #+#             */
/*   Updated: 2024/07/16 08:19:44 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stddef.h>
#include <string.h>
size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t		i;
	size_t		j;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		j = 0;
		while (reject[j])
		{
			if (s[i] == reject[j])
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}

// for test only
#include <stdio.h>
#include <string.h>

int		main(void)
{
	printf("sys=%lu\n", strcspn("", "2"));
	printf("own=%lu\n\n", ft_strcspn("", "2"));

	printf("sys=%lu\n", strcspn("Tutorialspoint", "Textbook"));
	printf("own=%lu\n\n", ft_strcspn("Tutorialspoint", "Textbook"));

	printf("sys=%lu\n", strcspn("abcde", "de"));
	printf("own=%lu\n", ft_strcspn("abcde", "de"));
}
/*
Reproduce exactly the behavior of the function strcspn
(man strcspn).

The function should be prototyped as follows:

size_t	ft_strcspn(const char *s, const char *reject);
*/
/*
strcspn()函数计算s中最初的一段长度，该段完全由不包含在reject中的字节组成。
strcspn()函数返回s中最初的一段不包含在字符串reject中的字节数。

#include <stdio.h>
#include <string.h>

int main() {
   int size;

   // Intializing string(Matched Characters)
   char str1[] = "tutorialspoint";
   char str2[] = "tutorial"; 
    
   // Using strcspn() to 
   size = strcspn(str1, str2);
    
   printf("The unmatched characters before the first matched character: %d\n", size);
   return 0;
}


Output: The unmatched characters before the first matched character: 0
*/