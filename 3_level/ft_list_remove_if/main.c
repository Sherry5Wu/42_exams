#include <stdio.h>
#include "ft_list.h"
#include <stdlib.h>
#include <string.h>

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());

void	print_list(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		printf("%s, ", (char *)(tmp ->data) );
		tmp = tmp -> next;
	}
}

int		main()
{
	char	*ch = "5"; // ch should be declcared as a string

	t_list	**begin;
	
	t_list	*d = malloc(sizeof(t_list));
	d ->data = "5"; // data value is a string.
	d ->next = 0;

	t_list	*c = malloc(sizeof(t_list));
	c ->data = "5";
	c ->next = d; // here is "c -> next = d" not "c -> next = &d"

	t_list	*b = malloc(sizeof(t_list));
	b ->data = "53";
	b ->next = c;

	t_list	*a = malloc(sizeof(t_list));
	a ->data = "5";
	a ->next = b;

	begin = &a;
	print_list(*begin);
	ft_list_remove_if(begin, (void *)ch, strcmp);
	printf("\n---------------\n");
	print_list(*begin);
}