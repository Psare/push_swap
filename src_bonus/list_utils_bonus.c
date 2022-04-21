/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damarry <damarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 21:02:10 by damarry           #+#    #+#             */
/*   Updated: 2022/03/04 21:02:11 by damarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/push_swap_bonus.h"

void	up_lstadd_front(t_stack **lst, t_stack *new)
{
	if (!new)
		return ;
	new -> next = (*lst);
	(*lst) = new;
}

void	up_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*lst_copy;

	lst_copy = *lst;
	if (!(*lst))
		*lst = new;
	else
	{
		while (lst_copy -> next)
			lst_copy = lst_copy -> next;
		lst_copy->next = new;
	}
}

t_stack	*upt_lstnew(t_data *data, int i)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		stop_4(data);
	node -> num = data->num_arr[i];
	node -> next = NULL;
	return (node);
}
