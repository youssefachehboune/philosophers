/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachehbo <yachehbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 17:12:32 by yachehbo          #+#    #+#             */
/*   Updated: 2022/03/27 14:43:14 by yachehbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

int	print_error(void)
{
	printf("Error\nWrong arguments\n");
	return (1);
}

int	check_arg(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (ft_isnumber(av[i]))
			return (1);
		i++;
	}
	return (0);
}

int	fill_data(int ac, char **av, t_data *data)
{
	if ((ac != 5 && ac != 6) || check_arg(av))
		return (print_error());
	data->nb_phl = ft_atoi(av[1]);
	data->tm_die = ft_atoi(av[2]);
	data->tm_eat = ft_atoi(av[3]);
	data->tm_slp = ft_atoi(av[4]);
	if (ac == 6)
	{
		data->nb_eat = ft_atoi(av[5]);
		if (data->nb_eat <= 0)
			return (print_error());
	}
	else
		data->nb_eat = 0;
	if (data->nb_phl <= 0 || data->nb_phl > 200 || data->tm_die <= 0
		|| data->tm_eat <= 0 || data->tm_slp <= 0)
		return (print_error());
	data->all_eat = 0;
	return (0);
}
