/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 07:57:36 by jingwu            #+#    #+#             */
/*   Updated: 2024/07/10 08:17:37 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// typedef struct s_list
// {
// 	struct s_list 	*next;
// 	void			*data;	
// }	t_list;
// int		ft_list_size(t_list *begin_list)
// {
// 	int		count;
// 	t_list	*tmp;

// 	count  = 0;
// 	tmp = begin_list;
// 	while (tmp)
// 	{
// 		count++;
// 		tmp = tmp -> next;
// 	}
// 	return (count);
// }

// solution 2
typedef struct s_list
{
	struct s_list 	*next;
	void			*data;	
}	t_list;

int		ft_list_size(t_list *begin_list)
{
	if (!begin_list)
		return (0);
	else
		return (1 + ft_list_size(begin_list -> next));
}


#include <stdio.h>
#include <stdlib.h>

int		main(void)
{
	int		n = 5;
	t_list	*lst_1;
	t_list	*lst_2;
	t_list	*lst_3;

	lst_3 = malloc(sizeof(t_list));
	lst_3 -> next = 0;
	lst_3 -> data = &n;

	lst_2 = malloc(sizeof(t_list));
	lst_2 -> next = lst_3;
	lst_2 -> data = &n;

	lst_1 = malloc(sizeof(t_list));
	lst_1 -> next = lst_2;
	lst_1 -> data = &n;

	printf("size=%d\n", ft_list_size(lst_3));
}

/*
Assignment name  : ft_list_size
Expected files   : ft_list_size.c
Allowed functions: 
--------------------------------------------------------------------------------

Write a function that returns the number of elements in the linked list that's
passed to it.

It must be declared as follows:

int	ft_list_size(t_list *begin_list);

You must use the following structure in your program ft_list_size.c :

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;

*/