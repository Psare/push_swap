/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_sorted_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damarry <damarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 21:02:05 by damarry           #+#    #+#             */
/*   Updated: 2022/03/04 21:02:06 by damarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/push_swap_bonus.h"

int	if_sorted_inner(t_stack *stack, t_stack *tmp)
{
	t_stack	*tmp_next;
	int		num;

	num = tmp->num;
	if (!tmp->next)
		tmp_next = stack;
	else
		tmp_next = tmp->next;
	while (tmp_next->num != num)
	{
		if (tmp_next->num < tmp->num)
			return (0);
		tmp = tmp->next;
		if (!tmp)
			tmp = stack;
		tmp_next = tmp_next->next;
		if (!tmp_next)
			tmp_next = stack;
	}
	return (1);
}

int	if_sorted(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp)
	{
		if (if_sorted_inner(stack, tmp))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
