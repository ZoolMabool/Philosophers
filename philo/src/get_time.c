/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 09:48:03 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/11/14 11:15:02 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	get_time(void)
{
	struct timeval	time;
	long			milliseconds;

	gettimeofday(&time, NULL);
	milliseconds = time.tv_sec * 1000;
	milliseconds += time.tv_usec / 1000;
	return (milliseconds);
}
