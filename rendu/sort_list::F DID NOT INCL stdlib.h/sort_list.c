/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 08:18:16 by rengelbr          #+#    #+#             */
/*   Updated: 2019/08/06 10:01:11 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "list.h"
#include <stdlib.h>
t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	int tmp;
	t_list *head;

	tmp = 0;
	head = lst;
	while (lst->next != NULL)
	{	
		if (!(cmp(lst->data, lst->next->data)))
		{
			tmp = lst->data;
			lst->data = lst->next->data;
			lst->next->data = tmp;
			lst = head;
		}
		else
			lst = lst->next;
	}
	lst = head;
	return (lst);
}
