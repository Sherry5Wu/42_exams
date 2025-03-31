/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 13:48:20 by jingwu            #+#    #+#             */
/*   Updated: 2024/07/11 10:15:30 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

  typedef struct  s_point
  {
    int           x;
    int           y;
  }               t_point;
// Attention to the sequence x and y, in array it should be array[y][x], in the
// struct it is t_point{x, y}  
void	fill(char **tab, t_point size, t_point cur, char c)
{
	// Attention: when cur.x = size.x or cur.y = size.y, is also invaild.

	if (cur.x < 0 || cur.x >= size.x || cur.y < 0 || cur.y >= size.y 
			|| tab[cur.y][cur.x] != c)
		return ;
	tab[cur.y][cur.x] = 'F';
	// attention: how to pass the new t_point type argument.
	fill(tab, size, (t_point){cur.x - 1, cur.y}, c);
	fill(tab, size, (t_point){cur.x + 1, cur.y}, c);
	fill(tab, size, (t_point){cur.x, cur.y - 1}, c);
	fill(tab, size, (t_point){cur.x, cur.y + 1}, c);
}
  
  void  flood_fill(char **tab, t_point size, t_point begin)
  {
		// In an array, the first number is for the row, and second is for the col.
		//so the parameter is tab[begin.y][begin.x]
		fill(tab, size, begin, tab[begin.y][begin.x]);
  }


#include <stdlib.h>
#include <stdio.h>

char** make_area(char** zone, t_point size)
{
	char** new;

	new = malloc(sizeof(char*) * size.y);
	for (int i = 0; i < size.y; ++i)
	{
		new[i] = malloc(size.x + 1);
		for (int j = 0; j < size.x; ++j)
			new[i][j] = zone[i][j];
		new[i][size.x] = '\0';
	}

	return new;
}

int main(void)
{
	t_point size = {8, 5};
	char *zone[] = {
		"11111111",
		"10001001",
		"10010001",
		"10110001",
		"11100001",
	};

	char**  area = make_area(zone, size);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	printf("\n");

	t_point begin = {7, 4};
	flood_fill(area, size, begin);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	return (0);
}

/*
Assignment name  : flood_fill
Expected files   : flood_fill.c
Allowed functions: -
--------------------------------------------------------------------------------

Write a function that takes a char ** as a 2-dimensional array of char, a 
t_point as the dimensions of this array and a t_point as the starting point.

Starting from the given 'begin' t_point, this function fills an entire zone 
by replacing characters inside with the character 'F'. A zone is an group of 
the same character delimitated horizontally and vertically by other characters
or the array boundry.

The flood_fill function won't fill diagonally.

The flood_fill function will be prototyped like this:
  void  flood_fill(char **tab, t_point size, t_point begin);

The t_point structure is prototyped like this: (put it in flood_fill.c)

  typedef struct  s_point
  {
    int           x;
    int           y;
  }               t_point;

Example:

$> cat test.c
#include <stdlib.h>
#include <stdio.h>

char** make_area(char** zone, t_point size)
{
	char** new;

	new = malloc(sizeof(char*) * size.y);
	for (int i = 0; i < size.y; ++i)
	{
		new[i] = malloc(size.x + 1);
		for (int j = 0; j < size.x; ++j)
			new[i][j] = zone[i][j];
		new[i][size.x] = '\0';
	}

	return new;
}

int main(void)
{
	t_point size = {8, 5};
	char *zone[] = {
		"11111111",
		"10001001",
		"10010001",
		"10110001",
		"11100001",
	};

	char**  area = make_area(zone, size);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	printf("\n");

	t_point begin = {7, 4};
	flood_fill(area, size, begin);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	return (0);
}

$> gcc flood_fill.c test.c -o test; ./test
11111111
10001001
10010001
10110001
11100001

FFFFFFFF
F000F00F
F00F000F
F0FF000F
FFF0000F
$> 
*/