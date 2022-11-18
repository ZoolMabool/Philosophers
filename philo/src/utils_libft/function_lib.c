/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_lib.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:18:16 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/11/18 10:58:41 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_atoi(const char *nptr, int *error)
{
	int		i;
	long	nbr;

	i = 0;
	nbr = 0;
	while ((nptr[i] == ' ') || (nptr[i] >= '\t' && nptr[i] <= '\r'))
		i++;
	while ((nptr[i] != '\0') && (nptr[i] >= '0') && (nptr[i] <= '9'))
	{
		nbr = nbr * 10 + (nptr[i] - '0');
		if (nbr > 2147483647)
			*error += 1;
		i++;
	}
	return (nbr);
}

int	ft_isdigit(int character)
{
	if (character >= '0' && character <= '9')
		return (1);
	return (0);
}
