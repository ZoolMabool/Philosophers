/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:17:23 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/11/21 10:55:21 by ybaudoui         ###   ########.fr       */
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
	pthread_mutex_t	eat_enough;
	pthread_mutex_t	all_eat;
	pthread_mutex_t	philo_eat;
	pthread_mutex_t	number_of_meal;
}	t_mutexes;

typedef struct s_philo_data
{
	int			number_of_meal;
	int			philo_id;
	long int	last_eat;
	int			death_time;
	int			eat_time;
	int			sleep_time;
	int			philo_die;
	long int	start_time;
	int			philo_number;
	int			eat_enough;
	int			max_eat;
	t_mutexes	*mutexes;
}	t_philo_data;

typedef struct s_data
{
	int				number_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				all_eat;
	int				number_philo_must_eat;
	long int		time_start;
	pthread_t		*philo;
	pthread_t		death;
	pthread_t		fat;
	t_philo_data	*philo_data;
	t_mutexes		*mutexes;
}	t_data;

/*****liB*****/

int			ft_atoi(const char *nptr, int *error);
int			ft_isdigit(int character);

/*****error*****/

void		print_error(void);
void		print_error_digit(void);

/*****init*****/

int			init_struct(t_data *data, char **argv, t_mutexes *mutexes);
int			init_philo(t_data *data, t_mutexes *mutexes);
void		init_death(t_data *data);
int			init_mutex(t_mutexes *mutexes, int number_philo);

/*****timestamp*****/

long int	get_time(void);
long int	c_time(long int time_start);

/*****parsing*****/

int			verif_arg(int argc, char **argv);

/*****clean*****/

void		clean_program(t_mutexes *mutexes, t_data *data);
void		ft_free(t_data *data, t_mutexes *mutexes);

/*****print*****/

void		print_messages(t_philo_data *philo_data, char *message, int flag);
int			print_death(t_data *data, int i);

/*****death*****/

void		*check_death(void *arg);
int			is_one_philo_dead(t_philo_data *philo_data);

/*****sleep*****/

void		ft_sleep(t_philo_data *philo_data);

/*****eat*****/

int			ft_eat(t_philo_data *philo_data);
void		*check_meal(void *arg);

/*****think*****/

void		ft_think(t_philo_data *philo_data);

/*****routine*****/

void		*routine(void *data);

#endif
