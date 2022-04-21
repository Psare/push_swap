/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damarry <damarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 21:01:19 by damarry           #+#    #+#             */
/*   Updated: 2022/03/04 21:01:20 by damarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/push_swap.h"

void	swap_a(t_stack **stack_a)
{
	t_stack	*tmp;

	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	tmp = (*stack_a)->next;
	(*stack_a)->next = tmp->next;
	tmp->next = (*stack_a);
	(*stack_a) = tmp;
	up_putendl_fd("sa", 1);
}

void	swap_b(t_stack **stack_b)
{
	t_stack	*tmp;

	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	tmp = (*stack_b)->next;
	(*stack_b)->next = tmp->next;
	tmp->next = (*stack_b);
	(*stack_b) = tmp;
	up_putendl_fd("sb", 1);
}

void	swap_ab(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	if ((*stack_a) && (*stack_a)->next)
	{
		tmp = (*stack_a)->next;
		(*stack_a)->next = tmp->next;
		tmp->next = (*stack_a);
		(*stack_a) = tmp;
	}
	if ((*stack_b) && (*stack_b)->next)
	{
		tmp = (*stack_b)->next;
		(*stack_b)->next = tmp->next;
		tmp->next = (*stack_b);
		(*stack_b) = tmp;
	}
	up_putendl_fd("ss", 1);
}
