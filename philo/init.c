/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachehbo <yachehbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 17:29:41 by yachehbo          #+#    #+#             */
/*   Updated: 2022/03/27 14:52:25 by yachehbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

int	init_mutex(t_data *data)
{
	int	i;

	if (pthread_mutex_init(&(data->print), NULL))
	{
		printf("Error\nmutex init failed\n");
		return (1);
	}
	i = 1;
	while (i <= data->nb_phl)
	{
		if (pthread_mutex_init(&(data->fork[i]), NULL))
		{
			printf("Error\nmutex init failed\n");
			return (1);
		}
		i++;
	}	
	return (0);
}

int	init_philo(t_data *data, t_philo *philo)
{
	int	i;

	data->time = get_current_time();
	i = 1;
	while (i <= data->nb_phl)
	{
		philo[i].philo_id = i;
		philo[i].fork = i;
		if (i == data->nb_phl)
			philo[i].next_fork = 1;
		else
			philo[i].next_fork = i + 1;
		philo[i].eat_count = 0;
		philo[i].data = data;
		philo[i].last_eat = data->time;
		i++;
	}
	return (0);
}
