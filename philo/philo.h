/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachehbo <yachehbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 17:05:57 by yachehbo          #+#    #+#             */
/*   Updated: 2022/03/27 14:42:25 by yachehbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct data
{
	int				nb_phl;
	int				tm_die;
	int				tm_eat;
	int				tm_slp;
	int				nb_eat;
	int				all_eat;
	size_t			time;
	pthread_mutex_t	fork[200];
	pthread_mutex_t	print;
}	t_data;

typedef struct philo
{
	int				philo_id;
	int				fork;
	int				next_fork;
	int				eat_count;
	size_t			last_eat;
	t_data			*data;
	pthread_t		thread;
}	t_philo;

////////////////Fill//////////////////
int		check_arg(char **av);
int		fill_data(int ac, char **av, t_data *data);

/////////////philo-utils//////////////
int		ft_isnumber(char *str);
int		ft_atoi(const char *str);
size_t	get_current_time(void);
void	print_status(t_data *data, int id, char *message);

////////////////Init/////////////////
int		init_philo(t_data *data, t_philo *philo);
int		init_mutex(t_data *data);

////////////////observer/////////////////
void	observer(t_data *data, t_philo *philo);
int		check_dead(t_data *data, t_philo *philo);

////////////////routine/////////////////
int		philo_run(t_data *data, t_philo *philo);
void	*routine(void *arg);
void	philo_eat(t_data *data, t_philo *philo);
void	philo_do(int time);

#endif
