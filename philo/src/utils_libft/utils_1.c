/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:18:16 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/11/10 11:41:21 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_atoi(const char *nptr)
{
	char	*tab;
	int		i;
	int		nbr;
	int		minus;

	minus = 1;
	i = 0;
	nbr = 0;
	tab = (char *) nptr;
	while ((tab[i] == ' ') || (tab[i] >= '\t' && tab[i] <= '\r'))
		i++;
	if (tab[i] == '-')
	{
		minus = minus * (-1);
		i++;
	}
	else if (tab[i] == '+')
		i++;
	while ((tab[i] != '\0') && (tab[i] >= '0') && (tab[i] <= '9'))
	{
		nbr = nbr * 10 + (tab[i] - '0');
		i++;
	}
	return (nbr * minus);
}

int	check_num(char **argv)
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
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_isdigit(int character)
{
	if (character >= '0' && character <= '9')
		return (1);
	return (0);
}
