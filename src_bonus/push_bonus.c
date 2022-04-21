/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damarry <damarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 21:02:27 by damarry           #+#    #+#             */
/*   Updated: 2022/03/04 21:02:27 by damarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/push_swap_bonus.h"

void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	if (!(*stack_b))
		return ;
	tmp = (*stack_b);
	(*stack_b) = (*stack_b)->next;
	tmp->next = (*stack_a);
	(*stack_a) = tmp;
}

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	if (!(*stack_a))
		return ;
	tmp = (*stack_a);
	(*stack_a) = (*stack_a)->next;
	tmp->next = (*stack_b);
	(*stack_b) = tmp;
}
