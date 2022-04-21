/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damarry <damarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 21:01:37 by damarry           #+#    #+#             */
/*   Updated: 2022/03/04 21:01:37 by damarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc_bonus/push_swap_bonus.h"

void	cmd_checker(t_data *data, char *cmd)
{
	if (up_strcmp(cmd, "sa\n") == 0)
		swap_a(&data->stack_a);
	else if (up_strcmp(cmd, "sb\n") == 0)
		swap_b(&data->stack_b);
	else if (up_strcmp(cmd, "ss\n") == 0)
		swap_ab(&data->stack_a, &data->stack_b);
	else if (up_strcmp(cmd, "pa\n") == 0)
		push_a(&data->stack_a, &data->stack_b);
	else if (up_strcmp(cmd, "pb\n") == 0)
		push_b(&data->stack_a, &data->stack_b);
	else if (up_strcmp(cmd, "ra\n") == 0)
		rotate_a(&data->stack_a);
	else if (up_strcmp(cmd, "rb\n") == 0)
		rotate_b(&data->stack_b);
	else if (up_strcmp(cmd, "rr\n") == 0)
		rotate_ab(&data->stack_a, &data->stack_b);
	else if (up_strcmp(cmd, "rra\n") == 0)
		rev_rotate_a(&data->stack_a);
	else if (up_strcmp(cmd, "rrb\n") == 0)
		rev_rotate_b(&data->stack_b);
	else if (up_strcmp(cmd, "rrr\n") == 0)
		rev_rotate_ab(&data->stack_a, &data->stack_b);
	else
		stop_5(data, 1, cmd);
}

void	distributor(t_data *data)
{
	char	*cmd;

	cmd = get_next_line(STDIN_FILENO);
	while (cmd)
	{
		cmd_checker(data, cmd);
		free(cmd);
		cmd = get_next_line(0);
	}
	if (if_sorted(data->stack_a) && data->stack_a->num
		== data->min && data->stack_b == NULL)
		up_putendl_fd("OK", 1);
	else
		up_putendl_fd("KO", 1);
	stop_5(data, 0, NULL);
}

void	fill_a(t_data *data)
{
	int	i;

	data->stack_a = NULL;
	data->stack_b = NULL;
	data->min = find_min(data);
	i = -1;
	while (++i < data->len)
		up_lstadd_back(&data->stack_a, upt_lstnew(data, i));
	free(data->num_arr);
	data->num_arr = NULL;
	distributor(data);
}
