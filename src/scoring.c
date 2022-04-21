/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scoring.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damarry <damarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 21:01:12 by damarry           #+#    #+#             */
/*   Updated: 2022/03/04 21:01:14 by damarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/push_swap.h"

t_stack	*elem_to_push(t_stack *stack_b)
{
	t_stack	*tmp;
	t_stack	*tmp_ret;
	int		num;

	tmp = stack_b;
	tmp_ret = stack_b;
	num = tmp->cheapest;
	while (tmp)
	{
		if (tmp->cheapest < num)
		{
			num = tmp->cheapest;
			tmp_ret = tmp;
		}
		tmp = tmp->next;
	}
	return (tmp_ret);
}

void	lines_sawer(t_stack *stack, int cheap, int opt)
{
	stack->cheapest = cheap;
	stack->rotate_option = opt;
}

void	choose_opt(t_stack *tmp, int len_a, int len_b)
{
	int	cost_tmp;

	tmp->cheapest = rr_ra_opt(tmp, len_a);
	tmp->rotate_option = RR_RA;
	cost_tmp = rr_rb_opt(tmp, len_b);
	if (cost_tmp < tmp->cheapest)
		lines_sawer(tmp, cost_tmp, RR_RB);
	cost_tmp = rrr_rrb_opt(tmp, len_b);
	if (cost_tmp < tmp->cheapest)
		lines_sawer(tmp, cost_tmp, RRR_RRB);
	cost_tmp = rrr_rra_opt(tmp, len_a);
	if (cost_tmp < tmp->cheapest)
		lines_sawer(tmp, cost_tmp, RRR_RRA);
	cost_tmp = rra_rb_opt(tmp);
	if (cost_tmp < tmp->cheapest)
		lines_sawer(tmp, cost_tmp, RRA_RB);
	cost_tmp = rrb_ra_opt(tmp);
	if (cost_tmp < tmp->cheapest)
		lines_sawer(tmp, cost_tmp, RRB_RA);
}

int	scoring_a(t_stack *stack_a, int num)
{
	t_stack	*tmp;
	t_stack	*tmp_next;
	int		a_score;

	tmp = stack_a;
	tmp_next = tmp->next;
	a_score = 1;
	while (tmp_next)
	{
		if (tmp->num < num && tmp->next->num > num)
			return (a_score);
		tmp = tmp->next;
		tmp_next = tmp_next->next;
		a_score += 1;
	}
	return (0);
}

void	scoring(t_data *data)
{
	t_stack	*tmp;
	int		score_b;

	score_b = 0;
	tmp = data->stack_b;
	while (tmp)
	{
		tmp->score_b = score_b;
		tmp->score_rb = (data->len_b - score_b) * (score_b > 0);
		tmp->score_a = scoring_a(data->stack_a, tmp->num);
		tmp->score_ra = data->len_a - tmp->score_a * (tmp->score_a > 0);
		choose_opt(tmp, data->len_a, data->len_b);
		score_b += 1;
		tmp = tmp->next;
	}
}
