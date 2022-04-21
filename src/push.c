/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damarry <damarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 21:00:39 by damarry           #+#    #+#             */
/*   Updated: 2022/03/04 21:00:40 by damarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/push_swap.h"

void	push_a(t_stack **stack_a, t_stack **stack_b, int *len_a, int *len_b)
{
	t_stack	*tmp;

	if (!(*stack_b))
		return ;
	tmp = (*stack_b);
	(*stack_b) = (*stack_b)->next;
	tmp->next = (*stack_a);
	(*stack_a) = tmp;
	*len_a += 1;
	*len_b -= 1;
	up_putendl_fd("pa", 1);
}

void	push_b(t_stack **stack_a, t_stack **stack_b, int *len_a, int *len_b)
{
	t_stack	*tmp;

	if (!(*stack_a))
		return ;
	tmp = (*stack_a);
	(*stack_a) = (*stack_a)->next;
	tmp->next = (*stack_b);
	(*stack_b) = tmp;
	*len_a -= 1;
	*len_b += 1;
	up_putendl_fd("pb", 1);
}
