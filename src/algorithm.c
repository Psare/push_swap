/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damarry <damarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 20:57:37 by damarry           #+#    #+#             */
/*   Updated: 2022/03/04 20:57:39 by damarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/push_swap.h"

void	five_sort(t_data *data)
{
	while (data->len_a > 3)
	{
		if (data->stack_a->num == data->min || data->stack_a->num < data->med)
			push_b(&data->stack_a, &data->stack_b, &data->len_a, &data->len);
		else
			rotate_a(&data->stack_a);
	}
	if (!if_sorted(data->stack_a) && data->stack_b->num == data->min)
		swap_ab(&data->stack_a, &data->stack_b);
	if (!if_sorted(data->stack_a))
		triple_sort(data);
	if (data->stack_b->num == data->min)
		swap_b(&data->stack_b);
	while (data->stack_a->num != data->med)
		rotate_a(&data->stack_a);
	push_a(&data->stack_a, &data->stack_b, &data->len_a, &data->len);
	push_a(&data->stack_a, &data->stack_b, &data->len_a, &data->len);
	stop_5(data);
}

void	distributor(t_stack *stack, t_data *data)
{
	if (stack->rotate_option == RR_RA)
		rr_ra_move(stack, data);
	else if (stack->rotate_option == RR_RB)
		rr_rb_move(stack, data);
	else if (stack->rotate_option == RRR_RRA)
		rrr_rra_move(stack, data);
	else if (stack->rotate_option == RRR_RRB)
		rrr_rrb_move(stack, data);
	else if (stack->rotate_option == RRA_RB)
		rra_rb_move(stack, data);
	else if (stack->rotate_option == RRB_RA)
		rrb_ra_move(stack, data);
}

void	main_alg(t_data *data)
{
	t_stack	*to_move;

	fill_b(data);
	if (!if_sorted(data->stack_a))
		triple_sort(data);
	while (data->len_b)
	{
		scoring(data);
		to_move = elem_to_push(data->stack_b);
		distributor(to_move, data);
	}
	final_sort(data);
	stop_5(data);
}

void	fill_b(t_data *data)
{
	while (data->len_a > 3 && !if_sorted(data->stack_a))
	{
		if (data->stack_a->num == data->max || data->stack_a->num == data->min
			|| data->stack_a->num == data->med)
			rotate_a(&data->stack_a);
		else
			push_b(&data->stack_a, &data->stack_b, &data->len_a, &data->len_b);
	}
}

void	fill_a(t_data *data)
{
	int	i;

	data->stack_a = NULL;
	data->stack_b = NULL;
	i = -1;
	while (++i < data->len)
		up_lstadd_back(&data->stack_a, upt_lstnew(data, i));
	free(data->num_arr);
	data->num_arr = NULL;
	data->len_a = data->len;
	data->len_b = 0;
	if (data->len == 1)
		stop_5(data);
	else if (data->len_a == 5)
		five_sort(data);
	else
		main_alg(data);
}
