/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damarry <damarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 20:58:01 by damarry           #+#    #+#             */
/*   Updated: 2022/03/04 20:58:02 by damarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/push_swap.h"

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

int	rotate_dir(t_data *data)
{
	t_stack	*tmp;
	int		prev_num;
	int		i;

	tmp = data->stack_a;
	prev_num = MIN_INT;
	i = 0;
	while (tmp && prev_num < tmp->num)
	{
		i += 1;
		prev_num = tmp->num;
		tmp = tmp->next;
	}
	if (i > data->len_a / 2)
		return (BACKWARD);
	else
		return (FORWARD);
}

void	final_sort(t_data *data)
{
	if (rotate_dir(data) == FORWARD)
	{
		while (data->stack_a->num != data->min)
			rotate_a(&data->stack_a);
	}
	else
	{
		while (data->stack_a->num != data->min)
			rev_rotate_a(&data->stack_a);
	}
}

void	triple_sort(t_data *data)
{
	swap_a(&data->stack_a);
}
