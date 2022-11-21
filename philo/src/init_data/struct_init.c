/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:37:52 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/11/21 10:49:20 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	init_struct(t_data *data, char **argv, t_mutexes *mutexes)
{
	int	error;

	error = 0;
	data->number_philo = ft_atoi(argv[1], &error);
	data->time_to_die = ft_atoi(argv[2], &error);
	data->time_to_eat = ft_atoi(argv[3], &error);
	data->time_to_sleep = ft_atoi(argv[4], &error);
	data->number_philo_must_eat = -1;
	data->all_eat = 0;
	data->mutexes = mutexes;
	if (data->number_philo <= 0 || data->time_to_die <= 0
		|| data->time_to_sleep <= 0 || data->time_to_eat <= 0)
		error++;
	if (argv[5])
		data->number_philo_must_eat = ft_atoi(argv[5], &error);
	if (error)
	{
		print_error();
		return (1);
	}
	return (0);
}

int	init_mutex(t_mutexes *mutexes, int number_philo)
{
	int	i;

	i = 0;
	mutexes->fork = malloc(sizeof(pthread_mutex_t) * number_philo);
	if (!mutexes->fork)
	{
		print_error();
		return (1);
	}
	pthread_mutex_init(&mutexes->philo_die, NULL);
	pthread_mutex_init(&mutexes->philo_eat, NULL);
	pthread_mutex_init(&mutexes->print_lock, NULL);
	pthread_mutex_init(&mutexes->number_of_meal, NULL);
	pthread_mutex_init(&mutexes->eat_enough, NULL);
	pthread_mutex_init(&mutexes->all_eat, NULL);
	while (i < number_philo)
	{
		pthread_mutex_init(&mutexes->fork[i], NULL);
		i++;
	}
	return (0);
}

static int	init_malloc(t_data *data)
{
	data->philo_data = malloc(sizeof(t_philo_data) * data->number_philo);
	if (!data->philo_data)
	{
		print_error();
		return (1);
	}
	data->philo = malloc(sizeof(pthread_t) * data->number_philo);
	if (!data->philo)
	{
		print_error();
		return (1);
	}
	return (0);
}

int	init_philo(t_data *data, t_mutexes *mutexes)
{
	int	i;

	i = 0;
	if (init_malloc(data))
		return (1);
	data->time_start = get_time();
	while (i < data->number_philo)
	{
		data->philo_data[i].philo_id = i + 1;
		data->philo_data[i].death_time = data->time_to_die;
		data->philo_data[i].eat_time = data->time_to_eat;
		data->philo_data[i].last_eat = data->time_start;
		data->philo_data[i].sleep_time = data->time_to_sleep;
		data->philo_data[i].start_time = data->time_start;
		data->philo_data[i].philo_number = data->number_philo;
		data->philo_data[i].number_of_meal = 0;
		data->philo_data[i].max_eat = data->number_philo_must_eat;
		data->philo_data[i].eat_enough = 0;
		data->philo_data[i].philo_die = FALSE;
		data->philo_data[i].mutexes = mutexes;
		pthread_create(&data->philo[i], NULL, &routine, &data->philo_data[i]);
		usleep(50);
		i++;
	}
	return (0);
}

void	init_death(t_data *data)
{
	if (data->number_philo_must_eat != -1)
		pthread_create(&data->fat, NULL, &check_meal, data);
	pthread_create(&data->death, NULL, &check_death, data);
	if (data->number_philo_must_eat != -1)
		pthread_join(data->fat, NULL);
	pthread_join(data->death, NULL);
}
