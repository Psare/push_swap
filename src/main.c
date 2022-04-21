/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damarry <damarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 20:58:17 by damarry           #+#    #+#             */
/*   Updated: 2022/03/04 20:58:18 by damarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 1)
		return (0);
	reader(&data, ac, av);
	srt_arr(&data);
	fill_a(&data);
	return (0);
}
