/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_program.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:39:28 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/11/18 17:05:59 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	clean_program(t_mutexes *mutexes, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_philo)
	{
		pthread_join(data->philo[i], NULL);
		i++;
	}
	i = 0;
	while (i < data->number_philo)
	{
		pthread_mutex_destroy(&mutexes->fork[i]);
		i++;
	}
	pthread_mutex_destroy(&mutexes->philo_die);
	pthread_mutex_destroy(&mutexes->philo_eat);
	pthread_mutex_destroy(&mutexes->print_lock);
	pthread_mutex_destroy(&mutexes->number_of_meal);
	pthread_mutex_destroy(&mutexes->eat_enough);
	free(data->philo);
	free(data->philo_data);
	free(mutexes->fork);
}
