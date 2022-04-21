/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_funks_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damarry <damarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 21:01:48 by damarry           #+#    #+#             */
/*   Updated: 2022/03/04 21:01:49 by damarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/push_swap.h"

//from rotate_opt

int	rrb_ra_opt(t_stack *tmp)
{
	int	cost;

	cost = tmp->score_rb + tmp->score_a;
	return (cost);
}

//from move

void	rrb_ra_move(t_stack *stack, t_data *data)
{
	while (stack->score_rb)
	{
		rev_rotate_b(&data->stack_b);
		stack->score_rb -= 1;
	}
	while (stack->score_a)
	{
		rotate_a(&data->stack_a);
		stack->score_a -= 1;
	}
	push_a(&data->stack_a, &data->stack_b, &data->len_a, &data->len_b);
}
