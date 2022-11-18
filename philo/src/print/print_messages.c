/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_messages.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 10:04:33 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/11/18 12:20:08 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_messages(t_philo_data *philo_data, char *message, int flag)
{
	pthread_mutex_lock(&philo_data->mutexes->philo_die);
	if (philo_data->philo_die == FALSE)
	{
		pthread_mutex_lock(&philo_data->mutexes->print_lock);
		if (flag == 1)
			printf("\033[32;01m%ld Philo %d %s \033[00m\n", current_time(philo_data->start_time), philo_data->philo_id, message);
		if (flag == 2)
			printf("\033[35;01m%ld Philo %d %s \033[00m\n", current_time(philo_data->start_time), philo_data->philo_id, message);
		if (flag == 3)
			printf("\033[34;01m%ld Philo %d %s \033[00m\n", current_time(philo_data->start_time), philo_data->philo_id, message);
		if (flag == 4)
			printf("\033[33;01m%ld Philo %d %s \033[00m\n", current_time(philo_data->start_time), philo_data->philo_id, message);
		if (flag == 5)
			printf("\033[31;01m%ld Philo %d %s \033[00m\n", current_time(philo_data->start_time), philo_data->philo_id, message);
		pthread_mutex_unlock(&philo_data->mutexes->print_lock);
	}
	pthread_mutex_unlock(&philo_data->mutexes->philo_die);
}
