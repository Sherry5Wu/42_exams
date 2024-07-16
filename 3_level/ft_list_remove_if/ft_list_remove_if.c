/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 11:38:26 by jingwu            #+#    #+#             */
/*   Updated: 2024/07/16 11:24:49 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list		*tmp;
	
	if (!begin_list || !*begin_list)
		return ;
	
	tmp = *begin_list;
	// when the first node is the needed delete note.
	if (cmp(tmp ->data, data_ref) == 0)
	{
		*begin_list = tmp ->next;
		free(tmp); // remember to free tmp here
		ft_list_remove_if(begin_list, data_ref, cmp);
	}
	tmp = *begin_list;
	// first node is safe, checking the next one.
	ft_list_remove_if(&(tmp ->next), data_ref, cmp);
}

/*
Assignment name  : ft_list_remove_if
Expected files   : ft_list_remove_if.c
Allowed functions: free
--------------------------------------------------------------------------------

Write a function called ft_list_remove_if that removes from the
passed list any element the data of which is "equal" to the reference data.

It will be declared as follows :

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());

cmp takes two void* and returns 0 when both parameters are equal.

You have to use the ft_list.h file, which will contain:

$>cat ft_list.h
typedef struct      s_list
{
    struct s_list   *next;
    void            *data;
}                   t_list;
$>
*/