/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:37:52 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/11/16 11:33:18 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <pthread.h>

int	struct_init(t_data *data, char **argv, t_mutexes *mutexes)
{
	data->number_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->number_philo_must_eat = -1;
	data->mutexes = mutexes;
	if (argv[5])
		data->number_philo_must_eat = ft_atoi(argv[5]);
	return (0);
}

int	init_mutex(t_mutexes *mutexes, int number_philo)
{
	int	i;

	i = 0;
	mutexes->fork = malloc(sizeof (pthread_mutex_t) * number_philo);
	if (!mutexes->fork)
		return (1);
	pthread_mutex_init(&mutexes->print_lock, NULL);
	while (i < number_philo)
	{
		pthread_mutex_init(&mutexes->fork[i], NULL);
		i++;
	}
	return (0);
}

int	philo_init(t_data *data, t_mutexes *mutexes)
{
	int	i;

	i = 0;
	data->philo_data = malloc(sizeof (t_philo_data) * data->number_philo);
	if (!data->philo_data)
		return (1);
	data->philo = malloc(sizeof (pthread_t) * data->number_philo);
	if (!data->philo)
		return (1);
	data->time_start = get_time();
	while (i < data->number_philo)
	{
		data->philo_data[i].philo_id = i + 1;
		data->philo_data[i].death_time = data->time_to_die;
		data->philo_data[i].eat_time = data->time_to_eat;
		data->philo_data[i].sleep_time = data->time_to_sleep;
		data->philo_data[i].start_time = data->time_start;
		data->philo_data[i].philo_number = data->number_philo;
		data->philo_data[i].mutexes = mutexes;
		pthread_create(&data->philo[i], NULL, &routine, &data->philo_data[i]);
	//	if (i % 2)
			usleep(50);
		i++;
	}
	return (0);
}
