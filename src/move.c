/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damarry <damarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 20:58:25 by damarry           #+#    #+#             */
/*   Updated: 2022/03/04 20:58:26 by damarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/push_swap.h"

void	rr_ra_move(t_stack *stack, t_data *data)
{
	while (stack->score_b)
	{
		if (stack->score_a < 1)
			stack->score_a = data->len_a - 1;
		rotate_ab(&data->stack_a, &data->stack_b);
		stack->score_a -= 1;
		stack->score_b -= 1;
	}
	while (stack->score_a > 0)
	{
		rotate_a(&data->stack_a);
		stack->score_a -= 1;
	}
	push_a(&data->stack_a, &data->stack_b, &data->len_a, &data->len_b);
}

void	rr_rb_move(t_stack *stack, t_data *data)
{
	while (stack->score_a)
	{
		if (stack->score_b < 1)
			stack->score_b = data->len_b - 1;
		rotate_ab(&data->stack_a, &data->stack_b);
		stack->score_a -= 1;
		stack->score_b -= 1;
	}
	while (stack->score_b > 0)
	{
		rotate_b(&data->stack_b);
		stack->score_b -= 1;
	}
	push_a(&data->stack_a, &data->stack_b, &data->len_a, &data->len_b);
}

void	rrr_rrb_move(t_stack *stack, t_data *data)
{
	while (stack->score_ra)
	{
		if (stack->score_rb == 0)
			stack->score_rb = data->len_b;
		rev_rotate_ab(&data->stack_a, &data->stack_b);
		stack->score_ra -= 1;
		stack->score_rb -= 1;
	}
	while (stack->score_rb)
	{
		rev_rotate_b(&data->stack_b);
		stack->score_rb -= 1;
	}
	push_a(&data->stack_a, &data->stack_b, &data->len_a, &data->len_b);
}

void	rrr_rra_move(t_stack *stack, t_data *data)
{
	while (stack->score_rb)
	{
		if (stack->score_ra == 0)
			stack->score_ra = data->len_a;
		rev_rotate_ab(&data->stack_a, &data->stack_b);
		stack->score_ra -= 1;
		stack->score_rb -= 1;
	}
	while (stack->score_ra)
	{
		rev_rotate_a(&data->stack_a);
		stack->score_ra -= 1;
	}
	push_a(&data->stack_a, &data->stack_b, &data->len_a, &data->len_b);
}

void	rra_rb_move(t_stack *stack, t_data *data)
{
	while (stack->score_ra)
	{
		rev_rotate_a(&data->stack_a);
		stack->score_ra -= 1;
	}
	while (stack->score_b)
	{
		rotate_b(&data->stack_b);
		stack->score_b -= 1;
	}
	push_a(&data->stack_a, &data->stack_b, &data->len_a, &data->len_b);
}
