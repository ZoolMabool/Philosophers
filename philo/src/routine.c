/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:17:45 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/11/15 16:36:26 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_eat(t_philo_data *philo_data)
{
	pthread_mutex_lock(&philo_data->mutexes->print_lock);	
	printf("\033[32;01mPhilo %d is eating 🍕\033[00m\n", philo_data->philo_id + 1);
	pthread_mutex_unlock(&philo_data->mutexes->print_lock);
	usleep(philo_data->eat_time * 1000);
}

void	ft_sleep(t_philo_data *philo_data)
{
	printf("\033[34;01mPhilo %d is sleeping 💤\033[00m\n", philo_data->philo_id + 1);
	usleep(philo_data->sleep_time * 1000);
}

void	ft_think(t_philo_data *philo_data)
{
	printf("\033[33;01mPhilo %d is thinking 💡\033[00m\n", philo_data->philo_id + 1);
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
