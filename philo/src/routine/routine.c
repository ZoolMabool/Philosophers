/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:17:45 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/11/16 10:43:14 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_eat(t_philo_data *philo_data)
{
	pthread_mutex_lock(&philo_data->mutexes->fork[philo_data->philo_id - 1]);
	print_messages(philo_data, "has taken a fork 🍴", 1);
	if (philo_data->philo_number == 1)
	{
		pthread_mutex_unlock(&philo_data->mutexes->fork[philo_data->philo_id - 1]);
		exit (1);
	}
	pthread_mutex_lock(&philo_data->mutexes->fork[philo_data->philo_id % philo_data->philo_number]);
	print_messages(philo_data, "has taken a fork 🍴", 1);
	print_messages(philo_data, "is eating 🍝", 2);
	usleep(philo_data->eat_time * 1000);
	pthread_mutex_unlock(&philo_data->mutexes->fork[philo_data->philo_id % philo_data->philo_number]);
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

void	*routine(void *philo_data)
{
	int				i;

	i = 0;
	while (i < 1)
	{
		ft_eat(philo_data);
		ft_sleep(philo_data);
		ft_think(philo_data);
		i++;
	}
	return (0);
}
