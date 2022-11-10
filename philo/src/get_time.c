/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 09:48:03 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/11/08 10:59:24 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	get_time(void)
{
	struct timeval	start;
	struct timeval	end;
	long			seconds;
	long			milli;
	long			micros;

	gettimeofday(&start, NULL);
	sleep(5);
	gettimeofday(&end, NULL);
	seconds = (end.tv_sec - start.tv_sec);
	micros = (end.tv_usec - start.tv_usec);
	milli = (seconds * 1000) + (micros / 1000);
	printf("The elapsed time is %ld seconds and %ld milli\n", seconds, milli);
	return (0);
}
