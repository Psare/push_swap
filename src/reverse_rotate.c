/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damarry <damarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 21:00:54 by damarry           #+#    #+#             */
/*   Updated: 2022/03/04 21:00:56 by damarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/push_swap.h"

void	rev_rotate_a(t_stack **stack_a)
{
	t_stack	*tmp_1;
	t_stack	*tmp_2;

	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	tmp_1 = (*stack_a);
	tmp_2 = (*stack_a);
	while (tmp_1->next)
		tmp_1 = tmp_1->next;
	while (tmp_2->next != tmp_1)
		tmp_2 = tmp_2 -> next;
	tmp_2->next = NULL;
	tmp_1->next = (*stack_a);
	(*stack_a) = tmp_1;
	up_putendl_fd("rra", 1);
}

void	rev_rotate_b(t_stack **stack_b)
{
	t_stack	*tmp_1;
	t_stack	*tmp_2;

	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	tmp_1 = (*stack_b);
	tmp_2 = (*stack_b);
	while (tmp_1->next)
		tmp_1 = tmp_1->next;
	while (tmp_2->next != tmp_1)
		tmp_2 = tmp_2 -> next;
	tmp_2->next = NULL;
	tmp_1->next = (*stack_b);
	(*stack_b) = tmp_1;
	up_putendl_fd("rrb", 1);
}

void	rev_ab_a(t_stack **stack_a)
{
	t_stack	*tmp_1;
	t_stack	*tmp_2;

	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	tmp_1 = (*stack_a);
	tmp_2 = (*stack_a);
	while (tmp_1->next)
		tmp_1 = tmp_1->next;
	while (tmp_2->next != tmp_1)
		tmp_2 = tmp_2 -> next;
	tmp_2->next = NULL;
	tmp_1->next = (*stack_a);
	(*stack_a) = tmp_1;
}

void	rev_ab_b(t_stack **stack_b)
{
	t_stack	*tmp_1;
	t_stack	*tmp_2;

	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	tmp_1 = (*stack_b);
	tmp_2 = (*stack_b);
	while (tmp_1->next)
		tmp_1 = tmp_1->next;
	while (tmp_2->next != tmp_1)
		tmp_2 = tmp_2 -> next;
	tmp_2->next = NULL;
	tmp_1->next = (*stack_b);
	(*stack_b) = tmp_1;
}

void	rev_rotate_ab(t_stack **stack_a, t_stack **stack_b)
{
	rev_ab_a(stack_a);
	rev_ab_b(stack_b);
	up_putendl_fd("rrr", 1);
}
