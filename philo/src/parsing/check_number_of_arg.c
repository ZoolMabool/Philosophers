/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_number_of_arg.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:19:59 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/11/07 16:25:42 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

//static int	check_number_of_arg(char **argv)
//{
//	int	i;
//
//	i = 1;
//	while (argv[i])
//		i++;
//	return (i);
//}

int	verif_arg(char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (argv[i][0] == '-' || argv[i][0] == '+')
		return (0);
	while (argv[i])
	{
		if (ft_isdigit(argv[i][j]) == 0)
			return (1);
		i++;
	}
	return (0);
}
