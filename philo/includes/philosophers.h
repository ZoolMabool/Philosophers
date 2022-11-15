/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:17:23 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/11/15 16:14:43 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdlib.h>

typedef struct s_mutexes
{
	pthread_mutex_t	print_lock;
}	t_mutexes;

typedef struct s_philo_data
{
	int				number_of_meal;
	int				philo_id;
	int				last_eat;
	int				death_time;
	int				eat_time;
	int				sleep_time;
	t_mutexes		*mutexes;
}	t_philo_data;

typedef struct s_data
{
	int					number_philo;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					number_philo_must_eat;
	long int			time_start;
	pthread_t			*philo;
	t_philo_data		*philo_data;
	t_mutexes			*mutexes;
}	t_data;

int		ft_atoi(const char *nptr);
int		ft_isdigit(int character);
void	print_error(void);
int		check_num(char **argv);
int		verif_arg(char **argv);
int		get_time(void);
void	*routine(void *data);
int		struct_init(t_data *data, char **argv, t_mutexes *mutexes);
int		philo_init(t_data *data, t_mutexes *mutexes);

#endif
