/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 09:55:50 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/11/21 09:57:33 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	nb_meal(t_philo_data *philo_data)
{
	philo_data->number_of_meal = philo_data->number_of_meal + 1;
	pthread_mutex_lock(&philo_data->mutexes->number_of_meal);
	if (philo_data->number_of_meal == philo_data->max_eat)
	{
		pthread_mutex_lock(&philo_data->mutexes->eat_enough);
		philo_data->eat_enough = 1;
		pthread_mutex_unlock(&philo_data->mutexes->eat_enough);
	}
	pthread_mutex_unlock(&philo_data->mutexes->number_of_meal);
}

int	ft_eat(t_philo_data *philo_data)
{
	pthread_mutex_lock(&philo_data->mutexes->fork[philo_data->philo_id - 1]);
	print_messages(philo_data, "has taken a fork 🍴", 1);
	if (philo_data->philo_number == 1)
	{
		pthread_mutex_unlock(&philo_data->mutexes->fork[
			philo_data->philo_id - 1]);
		return (1);
	}
	pthread_mutex_lock(&philo_data->mutexes->fork[
		philo_data->philo_id % philo_data->philo_number]);
	print_messages(philo_data, "has taken a fork 🍴", 1);
	print_messages(philo_data, "is eating 🍝", 2);
	pthread_mutex_lock(&philo_data->mutexes->philo_eat);
	philo_data->last_eat = get_time();
	pthread_mutex_unlock(&philo_data->mutexes->philo_eat);
	nb_meal(philo_data);
	usleep(philo_data->eat_time * 1000);
	pthread_mutex_unlock(&philo_data->mutexes->fork[
		philo_data->philo_id % philo_data->philo_number]);
	pthread_mutex_unlock(&philo_data->mutexes->fork[philo_data->philo_id - 1]);
	return (0);
}

static void	*eat_enough(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_philo)
	{
		pthread_mutex_lock(&data->mutexes->philo_die);
		if (data->philo_data[i].philo_die == TRUE)
		{
			pthread_mutex_unlock(&data->mutexes->philo_die);
			return (NULL);
		}
		pthread_mutex_unlock(&data->mutexes->philo_die);
		pthread_mutex_lock(&data->philo_data->mutexes->eat_enough);
		if (data->philo_data[i].eat_enough)
		{
			pthread_mutex_lock(&data->mutexes->all_eat);
			data->all_eat++;
			data->philo_data[i].eat_enough = 0;
			pthread_mutex_unlock(&data->mutexes->all_eat);
		}
		pthread_mutex_unlock(&data->philo_data->mutexes->eat_enough);
		i++;
	}
	return (NULL);
}

void	*check_meal(void *arg)
{
	int		i;
	t_data	*data;

	data = arg;
	while (data->all_eat < data->number_philo)
		eat_enough(data);
	i = 0;
	while (i < data->number_philo)
	{
		pthread_mutex_lock(&data->mutexes->philo_die);
		data->philo_data[i].philo_die = TRUE;
		pthread_mutex_unlock(&data->mutexes->philo_die);
		i++;
	}
	return (NULL);
}
