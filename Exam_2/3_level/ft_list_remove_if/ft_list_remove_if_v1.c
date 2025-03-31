/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if_v1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 12:56:08 by jingwu            #+#    #+#             */
/*   Updated: 2024/07/12 13:35:43 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp) ())
{
	t_list *head;
	t_list *past;
	t_list *t_remove;

	head = *begin_list;
	past = NULL;
	t_remove = NULL;
	while (head != NULL)
	{
		if ((*cmp)(head->data, data_ref) == 0)
		{
			if (head == *begin_list)
				*begin_list = head->next;
			else
				past->next = head->next;
			t_remove = head;
			head = head->next;
			free(t_remove);
		}
		else
		{
			past = head;
			head = head->next;
		}
	}
}