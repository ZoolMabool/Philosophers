/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:44:34 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/11/15 16:25:41 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_data		*data;
	t_mutexes	*mutexes;

	data = malloc(sizeof (t_data));
	mutexes = malloc (sizeof (t_mutexes));
	if (argc != 5 && argc != 6)
	{
		printf("Wrong amount of arguments\n");
		return (1);
	}
	if (check_num(argv))
	{
		print_error();
		return (1);
	}
	struct_init(data, argv, mutexes);
	philo_init(data, mutexes);
	int i = 0;
	while (i < data->number_philo)
	{
		pthread_join(data->philo[i], NULL);
		i++;
	}
}
