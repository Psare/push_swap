/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damarry <damarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 21:02:36 by damarry           #+#    #+#             */
/*   Updated: 2022/03/04 21:02:37 by damarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/push_swap_bonus.h"

void	rotate_a(t_stack **stack_a)
{
	t_stack	*tmp;

	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	tmp = (*stack_a);
	(*stack_a) = (*stack_a)->next;
	tmp->next = NULL;
	up_lstadd_back(stack_a, tmp);
}

void	rotate_b(t_stack **stack_b)
{
	t_stack	*tmp;

	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	tmp = (*stack_b);
	(*stack_b) = (*stack_b)->next;
	tmp->next = NULL;
	up_lstadd_back(stack_b, tmp);
}

void	rotate_ab(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	if ((*stack_a) && (*stack_a)->next)
	{
		tmp = (*stack_a);
		(*stack_a) = (*stack_a)->next;
		tmp->next = NULL;
		up_lstadd_back(stack_a, tmp);
	}
	if ((*stack_b) && (*stack_b)->next)
	{
		tmp = (*stack_b);
		(*stack_b) = (*stack_b)->next;
		tmp->next = NULL;
		up_lstadd_back(stack_b, tmp);
	}
}
