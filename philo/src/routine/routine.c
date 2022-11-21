/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:17:45 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/11/21 10:16:42 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
