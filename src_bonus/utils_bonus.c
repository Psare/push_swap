/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damarry <damarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 21:02:46 by damarry           #+#    #+#             */
/*   Updated: 2022/03/04 21:02:47 by damarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/push_swap_bonus.h"

int	up_putendl_fd(char *s, int fd)
{
	if (!s)
		return (0);
	while (*s)
	{
		write(fd, s, 1);
		s += 1;
	}
	write(fd, "\n", 1);
	return (1);
}

long	up_atoi(const char *str)
{
	long	res;
	int		negative;

	negative = 1;
	res = 0;
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t'
			|| *str == '\v' || *str == '\f' || *str == '\r'))
		++str;
	if (*str == '-')
		negative = -1;
	if (*str == '-' || *str == '+')
		++str;
	while (*str && *str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - 48);
		++str;
	}
	return (res * negative);
}

int	arr_len(char **arr)
{
	int	l;

	l = 0;
	while (arr[l])
		l += 1;
	return (l);
}

int	find_min(t_data *data)
{
	int	i;
	int	min;

	i = 0;
	min = data->num_arr[i];
	while (++i < data->len)
	{
		if (data->num_arr[i] < min)
			min = data->num_arr[i];
	}
	return (min);
}

int	up_strcmp(const char *str1, const char *str2)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i += 1;
	return (s1[i] - s2[i]);
}
