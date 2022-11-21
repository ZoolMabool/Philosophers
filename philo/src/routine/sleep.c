/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:12:37 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/11/21 10:13:18 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_sleep(t_philo_data *philo_data)
{
	print_messages(philo_data, "is sleeping 💤", 3);
	usleep(philo_data->sleep_time * 1000);
}
