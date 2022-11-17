/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:17:23 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/11/17 17:15:46 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdlib.h>

# define FALSE 0
# define TRUE 1

typedef struct s_mutexes
{
	pthread_mutex_t	print_lock;
	pthread_mutex_t	*fork;
	pthread_mutex_t	philo_die;
	pthread_mutex_t	philo_eat;
}	t_mutexes;

typedef struct s_philo_data
{
	int				number_of_meal;
	int				philo_id;
	long int		last_eat;
	long int		death_time;
	long int		eat_time;
	long int		sleep_time;
	int				philo_die;
	long int		start_time;
	int				philo_number;
	t_mutexes		*mutexes;
}	t_philo_data;

typedef struct s_data
{
	int					number_philo;
	long int			time_to_die;
	long int			time_to_eat;
	long int			time_to_sleep;
	long int			number_philo_must_eat;
	long int			time_start;
	pthread_t			*philo;
	pthread_t			death;
	t_philo_data		*philo_data;
	t_mutexes			*mutexes;
}	t_data;

int			ft_atoi(const char *nptr);
int			ft_isdigit(int character);
void		print_error(void);
int			check_num(char **argv);
int			verif_arg(char **argv);
long int	get_time(void);
long int	current_time(long int time_start);
void		*routine(void *data);
void		print_messages(t_philo_data *philo_data, char *message, int flag);
int			struct_init(t_data *data, char **argv, t_mutexes *mutexes);
int			philo_init(t_data *data, t_mutexes *mutexes);
int			init_mutex(t_mutexes *mutexes, int number_philo);
void		*check_death(void *arg);
void		init_death(t_data *data);
void		clean_program(t_mutexes *mutexes, t_data *data);
void		ft_free(t_data *data, t_mutexes *mutexes);

#endif
