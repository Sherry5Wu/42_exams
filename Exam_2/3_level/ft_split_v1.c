#include <stdlib.h>

int	is_char_a_sep(char c)
{
	if (c == 32 || c == '\t' || c == '\n')
		return (1);
	else
		return (0);
}

void	copy_word(char *dest, char *start, char *end)
{
	int	i;

	i = 0;
	while (start < end)
		dest[i++] = *(start++);
	dest[i] = '\0';
}

int	count_words(char *str)
{
	int	count;
	int	is_word;

	count = 0;
	is_word = 0;
	while (*str)
	{
		if (is_char_a_sep(*str) == 0 && !is_word)
		{
			count++;
			is_word = 1;
		}
		else if (is_char_a_sep(*str) == 1)
			is_word = 0;
		str++;
	}
	return (count);
}

void	split_into_words(char **dest, char *str, int words)
{
	int		i;
	char	*start;

	i = 0;
	while (*str && i < words)
	{
		if (is_char_a_sep(*str) == 0)
		{
			start = str;
			while (*str && is_char_a_sep(*str) == 0)
				str++;
			dest[i] = (char *)malloc(sizeof(char) * (str - start + 1));
			if (!dest[i])
				return ;
			copy_word(dest[i], start, str);
			i++;
		}
		else
			str++;
	}
}

char	**ft_split(char *str)
{
	char	**res_str;
	int		words;

	words = count_words(str);
	res_str = (char **)malloc(sizeof(char *) * (words + 1));
	if (!res_str)
		return (NULL);
	if (words > 0)
		split_into_words(res_str, str, words);
	res_str[words] = 0;
	return (res_str);
}

#include <stdio.h>

int		main(int ac, char **av)
{
	(void)ac;
	char **strs;
	strs = ft_split(av[1]);
	for (int i = 0; i < count_words(av[1]); i++)
		printf("%s\n", strs[i]);	
}