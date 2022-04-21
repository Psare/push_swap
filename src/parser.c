/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damarry <damarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 21:00:33 by damarry           #+#    #+#             */
/*   Updated: 2022/03/04 21:00:34 by damarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	int_checker(t_data *data, long num, int last, char **arr)
{
	int	i;

	if ((num > MAX_INT || num < MIN_INT))
		stop_2(arr, data, ARG_ERR);
	i = -1;
	while (++i < last)
	{
		if (num == data->num_arr[i])
			stop_2(arr, data, ARG_ERR);
	}
}

void	to_int(t_data *data, char **arr)
{
	int	i;

	data->num_arr = (int *)malloc(data->len * sizeof(int));
	if (!data->num_arr)
		stop_1(arr, MAL_ERR);
	i = -1;
	while (arr[++i])
	{
		int_checker(data, up_atoi(arr[i]), i, arr);
		data->num_arr[i] = up_atoi(arr[i]);
	}
	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}

void	char_checker(char **arr)
{
	int	i;
	int	j;

	i = -1;
	while (arr[++i])
	{
		if (arr[i][0] == '0' && arr[i][1] != '\0')
			stop_1(arr, ARG_ERR);
		j = -1;
		while (arr[i][++j])
		{
			if ((arr[i][j] < '0' || arr[i][j] > '9') && arr[i][j] != '-')
				stop_1(arr, ARG_ERR);
		}
	}
}

char	**divided_args(int ac, char **av)
{
	int		i;
	char	**arr;

	arr = (char **)calloc(ac, sizeof(char *));
	if (!arr && up_putendl_fd("malloc_err", 2))
		exit(1);
	i = 0;
	while (av[++i])
	{
		arr[i - 1] = (char *)calloc(ft_strlen(av[i]) + 1, sizeof(char));
		if (!arr[i - 1])
			stop_1(arr, MAL_ERR);
		ft_memmove(arr[i - 1], av[i], ft_strlen(av[i]));
	}
	return (arr);
}

void	reader(t_data *data, int ac, char **av)
{
	char	**arr;

	if (ac == 2)
	{
		arr = ft_split(av[1], ' ');
		if (!arr && up_putendl_fd("malloc_err", 2))
			exit(1);
		data->len = arr_len(arr);
	}
	else
	{
		data->len = ac - 1;
		arr = divided_args(ac, av);
	}
	char_checker(arr);
	to_int(data, arr);
}
