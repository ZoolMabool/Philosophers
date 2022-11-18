/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_number_of_arg.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:19:59 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/11/18 11:08:43 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	verif_number_arg(int argc)
{
	if (argc != 5 && argc != 6)
	{
		printf("Wrong amount of arguments\n");
		return (1);
	}
	return (0);
}

static int	verif_digit(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
			{	
				print_error_digit();
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	verif_arg(int argc, char **argv)
{
	if (verif_number_arg(argc))
		return (1);
	if (verif_digit(argv))
		return (1);
	return (0);
}
