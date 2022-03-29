/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachehbo <yachehbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 17:54:17 by yachehbo          #+#    #+#             */
/*   Updated: 2022/03/27 17:30:29 by yachehbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

void	philo_do(int time)
{
	size_t	do_before;

	do_before = get_current_time() + time;
	while (get_current_time() < do_before)
	{
		usleep(60);
	}
		
}

void	philo_eat(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&data->fork[philo->fork]);
	print_status(data, philo->philo_id, "has taken a fork");
	pthread_mutex_lock(&data->fork[philo->next_fork]);
	print_status(data, philo->philo_id, "has taken a fork");
	print_status(data, philo->philo_id, "is eating");
	philo->eat_count++;
	philo->last_eat = get_current_time();
	if (philo->eat_count == data->nb_eat)
		data->all_eat++;
	philo_do(data->tm_eat);
	pthread_mutex_unlock(&data->fork[philo->fork]);
	pthread_mutex_unlock(&data->fork[philo->next_fork]);
}

void	*routine(void *arg)
{
	t_data	*data;
	t_philo	*philo;

	philo = (t_philo *)arg;
	data = philo->data;
	if (philo->philo_id % 2 == 0)
		usleep(100);
	while (1)
	{
		philo_eat(data, philo);
		print_status(data, philo->philo_id, "is sleeping");
		philo_do(data->tm_slp);
		print_status(data, philo->philo_id, "is thinking");
		if (philo->eat_count == data->nb_eat)
			break ;
	}
	return (NULL);
}

int	philo_run(t_data *data, t_philo *philo)
{
	int	i;

	i = 1;
	while (i <= data->nb_phl)
	{
		if (pthread_create(&philo[i].thread, NULL, routine, (&philo[i])))
		{
			printf("Error\pthread create failed\n");
			return (1);
		}
		if (pthread_detach(philo[i].thread))
		{
			printf("Error\ndetach failed\n");
			return (1);
		}
		i++;
	}
	return (0);
}
