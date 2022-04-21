/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damarry <damarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 21:02:15 by damarry           #+#    #+#             */
/*   Updated: 2022/03/04 21:02:16 by damarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/push_swap_bonus.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 1)
		return (0);
	reader(&data, ac, av);
	fill_a(&data);
	return (0);
}
