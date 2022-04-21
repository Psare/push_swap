/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damarry <damarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 21:01:43 by damarry           #+#    #+#             */
/*   Updated: 2022/03/04 21:01:44 by damarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/push_swap_bonus.h"

//until we dont have int arr
void	stop_1(char **arr, int flag)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
	if (flag == MAL_ERR)
		up_putendl_fd("Malloc_err", 2);
	else if (flag == ARG_ERR)
		up_putendl_fd("Error", 2);
	exit (1);
}

//since we have int arr
void	stop_2(char **arr, t_data *data, int flag)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
	arr = NULL;
	free(data->num_arr);
	data->num_arr = NULL;
	if (flag == MAL_ERR)
		up_putendl_fd("Malloc_err", 2);
	else if (flag == ARG_ERR)
		up_putendl_fd("Error", 2);
	exit (1);
}

//SINCE WE HAVE ONLY INT ARR
void	stop_3(t_data *data)
{
	free(data->num_arr);
	data->num_arr = NULL;
	up_putendl_fd("Malloc_err", 2);
	exit (1);
}

//SINCE WE HAVE A_STACK
void	stop_4(t_data *data)
{
	t_stack	*tmp;

	free(data->num_arr);
	data->num_arr = NULL;
	while (data->stack_a)
	{
		tmp = data->stack_a;
		data->stack_a = data->stack_a->next;
		free(tmp);
		tmp = NULL;
	}
	data->stack_a = NULL;
	up_putendl_fd("Malloc_err", 2);
	exit (1);
}

void	stop_5(t_data *data, int flag, char *cmd)
{
	t_stack	*tmp;

	while (data->stack_a)
	{
		tmp = data->stack_a;
		data->stack_a = data->stack_a->next;
		free(tmp);
		tmp = NULL;
	}
	data->stack_a = NULL;
	while (data->stack_b)
	{
		tmp = data->stack_b;
		data->stack_b = data->stack_b->next;
		free(tmp);
		tmp = NULL;
	}
	data->stack_b = NULL;
	if (flag)
		up_putendl_fd("Error", 2);
	if (cmd)
		free(cmd);
	exit (0);
}
