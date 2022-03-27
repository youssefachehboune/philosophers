/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachehbo <yachehbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 17:05:49 by yachehbo          #+#    #+#             */
/*   Updated: 2022/03/27 15:02:33 by yachehbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	data;
	t_philo	philo[200];
	int		i;

	if (fill_data(ac, av, &data))
		return (1);
	if (init_philo(&data, philo) || init_mutex(&data))
		return (1);
	if (philo_run(&data, philo))
		return (1);
	observer(&data, philo);
	i = 1;
	while (i <= data.nb_phl)
	{
		pthread_mutex_destroy(&data.fork[i]);
		i++;
	}
	pthread_mutex_destroy(&data.print);
	return (0);
}
