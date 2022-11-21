/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:06:48 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/11/21 10:34:55 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	print_death(t_data *data, int i)
{
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
		return (TRUE);
	}
	pthread_mutex_unlock(&data->mutexes->philo_eat);
	return (FALSE);
}
