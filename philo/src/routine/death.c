/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:02:26 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/11/21 10:38:31 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
		if (print_death(data, i) == TRUE)
			return (NULL);
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
