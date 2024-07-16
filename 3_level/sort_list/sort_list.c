/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 08:56:49 by jingwu            #+#    #+#             */
/*   Updated: 2024/07/16 11:30:43 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	t_list		*tmp;
	int			n;

	tmp = lst;
	while (tmp && (tmp -> next))
	{
		// if the current data and next data don't follow the order, then swap the datas.
		// then the comparetion starts from the first node again.
		if (cmp(tmp -> data,(tmp -> next) -> data) == 0)
		{
			n  = tmp -> data;
			tmp -> data = (tmp ->next) -> data;
			(tmp -> next) -> data = n;
			tmp = lst; // let tmp repoint to the begin of the list. so the cmp will start from begin again;
		}
		else
			tmp = tmp ->next;
	}
	return (lst);
}

/*
Assignment name  : sort_list
Expected files   : sort_list.c
Allowed functions: 
--------------------------------------------------------------------------------

Write the following functions:

t_list	*sort_list(t_list* lst, int (*cmp)(int, int));

This function must sort the list given as a parameter, using the function 
pointer cmp to select the order to apply, and returns a pointer to the 
first element of the sorted list.

Duplications must remain.

Inputs will always be consistent.

You must use the type t_list described in the file list.h 
that is provided to you. You must include that file 
(#include "list.h"), but you must not turn it in. We will use our own 
to compile your assignment.

Functions passed as cmp will always return a value different from 
0 if a and b are in the right order, 0 otherwise.

For example, the following function used as cmp will sort the list 
in ascending order:

int ascending(int a, int b)
{
	return (a <= b);
}
*/