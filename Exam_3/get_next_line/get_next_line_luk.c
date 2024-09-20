/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v2_get_next_line_luk.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 09:19:54 by jingwu            #+#    #+#             */
/*   Updated: 2024/09/17 11:28:07 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i = 0;

	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return (s);
		s++;
	}
	return (NULL); // remeber to return
}

void	ft_strcpy(char *dst, const char *src)
{
	while (*src)
		*dst++ = *src++;
	*dst = '\0';
}

char	*ft_strdup(const char *src)
{
	size_t	len = ft_strlen(src) + 1;
	char	*dst = malloc(len);

	if (dst == NULL)
		return (NULL);
	ft_strcpy(dst, src);
	return (dst);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char *join;

	if (!s1 || !s2)
		return (NULL);
	join = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!join) // remeber to check here
		return (NULL);
	ft_strcpy(join, s1);
	ft_strcpy(join + ft_strlen(s1), s2);
	free(s1); // remeber to free
	return (join);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1]; //here is just char, not char *.
	char		*line;
	char		*newline;
	int			countread;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_strdup(buf);
	while (!(newline = ft_strchr(line, '\n')) && (countread = read(fd, buf, BUFFER_SIZE)))
	{
		buf[countread] = '\0';
		line = ft_strjoin(line, buf);
	}
	if (ft_strlen(line) == 0)
		return (free(line), NULL);
	if (newline)
	{
		ft_strcpy(buf, newline + 1); // copy the rest characters (characters after '\n') to buf
		*(newline + 1) = '\0'; // set the character after '\n' to '\0'. So when output the line,
								// will stop at '\0', and which is the whole line should be ended.
	}
	else
		buf[0] = '\0';
	return (line);
}

#include <fcntl.h>
#include <stdio.h>
int main()
{
    int fd;
    char *line;
    int i = 0;

    fd = open("tests/test1.txt", O_RDONLY);
//	fd = open("tests/text.txt", O_RDONLY);
//  fd = open("tests/test1.txt", O_RDONLY);
//  fd = open("test/empty.txt", O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("line[%02d]=%s", i, line); // output format is "01, 02,...10"
        free(line);
        i++;
    }
    close(fd);
    return (0);
}
