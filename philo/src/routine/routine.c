/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:17:45 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/11/17 16:36:39 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_eat(t_philo_data *philo_data)
{
	pthread_mutex_lock(&philo_data->mutexes->fork[philo_data->philo_id - 1]);
	print_messages(philo_data, "has taken a fork 🍴", 1);
	if (philo_data->philo_number == 1)
	{
		pthread_mutex_unlock(&philo_data->mutexes->fork[
			philo_data->philo_id - 1]);
		exit (1);
	}
	pthread_mutex_lock(&philo_data->mutexes->fork[
		philo_data->philo_id % philo_data->philo_number]);
	print_messages(philo_data, "has taken a fork 🍴", 1);
	print_messages(philo_data, "is eating 🍝", 2);
	pthread_mutex_lock(&philo_data->mutexes->philo_eat);
	philo_data->last_eat = get_time();
	pthread_mutex_unlock(&philo_data->mutexes->philo_eat);
	usleep(philo_data->eat_time * 1000);
	philo_data->number_of_meal = philo_data->number_of_meal + 1;
	pthread_mutex_unlock(&philo_data->mutexes->fork[
		philo_data->philo_id % philo_data->philo_number]);
	pthread_mutex_unlock(&philo_data->mutexes->fork[philo_data->philo_id - 1]);
}

void	ft_sleep(t_philo_data *philo_data)
{
	print_messages(philo_data, "is sleeping 💤", 3);
	usleep(philo_data->sleep_time * 1000);
}

void	ft_think(t_philo_data *philo_data)
{
	print_messages(philo_data, "is thinking 💡", 4);
}

void	*check_death(void *arg)
{
	int		i;
	t_data	*data;

	data = arg;
	i = 0;
	while (1)
	{
		pthread_mutex_lock(&data->mutexes->philo_eat);
		if (data->philo_data[i].death_time < get_time() - data->philo_data[i].last_eat)
		{
			pthread_mutex_unlock(&data->mutexes->philo_eat);
			print_messages(&data->philo_data[i], "died 💀", 5);
			i = 0;
			while (i < data->number_philo)
			{
				pthread_mutex_lock(&data->mutexes->philo_die);
				data->philo_data[i].philo_die = TRUE;
				pthread_mutex_unlock(&data->mutexes->philo_die);
				i++;
			}
			return (arg);
		}
		pthread_mutex_unlock(&data->mutexes->philo_eat);
		i++;
		if (i == data->number_philo)
			i = 0;
	}
}

void	*routine(void *arg)
{
	t_philo_data	*philo_data;

	philo_data = arg;
	pthread_mutex_lock(&philo_data->mutexes->philo_die);
	while (philo_data->philo_die == FALSE)
	{
		pthread_mutex_unlock(&philo_data->mutexes->philo_die);
		ft_eat(philo_data);
		ft_sleep(philo_data);
		ft_think(philo_data);
		pthread_mutex_lock(&philo_data->mutexes->philo_die);
	}
	pthread_mutex_unlock(&philo_data->mutexes->philo_die);
	return (0);
}
