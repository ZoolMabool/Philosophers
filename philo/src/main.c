/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:44:34 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/11/18 10:16:28 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_data		data;
	t_mutexes	mutexes;

	if (verif_arg(argc, argv))
		return (1);
	if (init_struct(&data, argv, &mutexes))
		return (1);
	if (init_mutex(&mutexes, data.number_philo))
		return (1);
	if (init_philo(&data, &mutexes))
		return (1);
	init_death(&data);
	clean_program(&mutexes, &data);
	return (0);
}
