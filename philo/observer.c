/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachehbo <yachehbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 18:48:27 by yachehbo          #+#    #+#             */
/*   Updated: 2022/03/27 15:43:20 by yachehbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

int	check_dead(t_data *data, t_philo *philo)
{
	if (get_current_time() - philo->last_eat >= (size_t)data->tm_die + 1)
	{
		print_status(data, philo->philo_id, "died");
		pthread_mutex_lock(&data->print);
		return (1);
	}
	return (0);
}

void	observer(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (1)
	{
		if (i == data->nb_phl)
			i = 0;
		if (check_dead(data, &philo[i + 1]))
			break ;
		if (data->all_eat == data->nb_phl)
		{
			pthread_mutex_lock(&data->print);
			break ;
		}
		i++;
	}
}
