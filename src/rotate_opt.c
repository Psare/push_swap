/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_opt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damarry <damarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 21:01:01 by damarry           #+#    #+#             */
/*   Updated: 2022/03/04 21:01:02 by damarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/push_swap.h"

int	rr_ra_opt(t_stack *tmp, int len_a)
{
	int	cost;
	int	score_a;
	int	score_b;

	cost = 0;
	score_a = tmp->score_a;
	score_b = tmp->score_b;
	while (score_b)
	{
		cost += 1;
		if (score_a < 1)
			score_a = len_a - 1;
		score_a -= 1;
		score_b -= 1;
	}
	if (score_a > 0)
		cost += score_a;
	return (cost);
}

int	rr_rb_opt(t_stack *tmp, int len_b)
{
	int	cost;
	int	score_a;
	int	score_b;

	cost = 0;
	score_a = tmp->score_a;
	score_b = tmp->score_b;
	while (score_a)
	{
		cost += 1;
		if (score_b < 1)
			score_b = len_b - 1;
		score_a -= 1;
		score_b -= 1;
	}
	if (score_b > 0)
		cost += score_b;
	return (cost);
}

int	rrr_rrb_opt(t_stack *tmp, int len_b)
{
	int	cost;
	int	score_ra;
	int	score_rb;

	cost = 0;
	score_ra = tmp->score_ra;
	score_rb = tmp->score_rb;
	while (score_ra)
	{
		cost += 1;
		if (score_rb == 0)
			score_rb = len_b;
		score_ra -= 1;
		score_rb -= 1;
	}
	cost += score_rb;
	return (cost);
}

int	rrr_rra_opt(t_stack *tmp, int len_a)
{
	int	cost;
	int	score_ra;
	int	score_rb;

	cost = 0;
	score_ra = tmp->score_ra;
	score_rb = tmp->score_rb;
	while (score_rb)
	{
		cost += 1;
		if (score_ra == 0)
			score_ra = len_a;
		score_ra -= 1;
		score_rb -= 1;
	}
	cost += score_ra;
	return (cost);
}

int	rra_rb_opt(t_stack *tmp)
{
	int	cost;

	cost = tmp->score_ra + tmp->score_b;
	return (cost);
}
