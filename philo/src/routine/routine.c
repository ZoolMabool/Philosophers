/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:17:45 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/11/18 17:05:28 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	ft_eat(t_philo_data *philo_data)
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
	usleep(philo_data->eat_time * 1000);
	philo_data->number_of_meal = philo_data->number_of_meal + 1;
	pthread_mutex_lock(&philo_data->mutexes->number_of_meal);
	if (philo_data->number_of_meal == philo_data->max_eat)
	{
		pthread_mutex_lock(&philo_data->mutexes->eat_enough);
		philo_data->eat_enough = 1;
		pthread_mutex_unlock(&philo_data->mutexes->eat_enough);
	}
	pthread_mutex_unlock(&philo_data->mutexes->number_of_meal);
	pthread_mutex_unlock(&philo_data->mutexes->fork[
		philo_data->philo_id % philo_data->philo_number]);
	pthread_mutex_unlock(&philo_data->mutexes->fork[philo_data->philo_id - 1]);
	return (0);
}

static void	ft_sleep(t_philo_data *philo_data)
{
	print_messages(philo_data, "is sleeping 💤", 3);
	usleep(philo_data->sleep_time * 1000);
}

static void	ft_think(t_philo_data *philo_data)
{
	print_messages(philo_data, "is thinking 💡", 4);
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
		pthread_mutex_unlock(&data->mutexes->philo_die);
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

void	*check_death(void *arg)
{
	int		i;
	t_data	*data;

	data = arg;
	i = 0;
	while (1)
	{
		pthread_mutex_lock(&data->mutexes->all_eat);
		if (data->all_eat == data->number_philo)
		{
			pthread_mutex_unlock(&data->mutexes->all_eat);
			return (NULL);
		}
		pthread_mutex_unlock(&data->mutexes->all_eat);
		pthread_mutex_lock(&data->mutexes->philo_eat);
		if (data->philo_data[i].death_time
			< get_time() - data->philo_data[i].last_eat)
		{
			print_messages(&data->philo_data[i], "died 💀", 5);
			pthread_mutex_unlock(&data->mutexes->philo_eat);
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
		pthread_mutex_unlock(&data->mutexes->philo_eat);
		i++;
		if (i == data->number_philo)
			i = 0;
	}
	return (NULL);
}

int	is_one_philo_dead(t_philo_data *philo_data)
{
	int	res;

	pthread_mutex_lock(&philo_data->mutexes->philo_die);
	res = philo_data->philo_die;
	pthread_mutex_unlock(&philo_data->mutexes->philo_die);
	return (res);
}

void	*routine(void *arg)
{
	t_philo_data	*philo_data;

	philo_data = arg;
	while (!is_one_philo_dead(philo_data))
	{
		if (ft_eat(philo_data))
		{
			return (NULL);
		}
		ft_sleep(philo_data);
		ft_think(philo_data);
	}
	return (0);
}
