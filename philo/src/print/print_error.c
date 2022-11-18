/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:41:16 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/11/18 11:07:21 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_error(void)
{
	printf("[");
	printf("\033[31;01mError\033[00m");
	printf("]\n");
}

void	print_error_digit(void)
{
	printf("[");
	printf("\033[31;01mParams must be only digits\033[00m");
	printf("]\n");
}
