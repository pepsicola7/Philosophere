/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libra.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:51:06 by peli              #+#    #+#             */
/*   Updated: 2025/01/23 12:18:31 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBRA_H
# define LIBRA_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <sys/time.h>
# include <sys/types.h>
# include <time.h>

typedef struct s_table	t_table;

typedef struct s_philo
{
	int				id;
	int				ate_meal;
	long			lastimeate;
	int				t_die;
	int				t_eat;
	int				t_dodo;
	int				num_meal;
	long			start;
	int				stop;
	pthread_t		thread;
	t_table			*table;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	status;
}	t_philo;

typedef struct s_table
{
	int				nbr_philo;
	int				t_die;
	int				t_eat;
	int				t_dodo;
	int				num_meal;
	long			start;
	t_philo			*philo;
	pthread_mutex_t	*fork;
	pthread_mutex_t	printf;
	pthread_mutex_t	status;
	int				stop;
}	t_table;

int		check_arg(int argc, char **argv);
int		is_argv_valide(char *str);
int		ft_atoi(char *str);
void	printf_arg(t_table *tab);
int		initial_tab(char **argv, t_table *tab);
int		create_philo(t_table *tab);
void	initial_philo(t_table *tab, t_philo *philosopher);
void	*lifestyle(void *arg);
void	supervisor(t_table *tab, t_philo *philo);
void	sleeping(t_philo *pthreadhilo);
void	eating(t_philo *philo);
long	get_time(void);
void	philo_printf(t_philo *philo, char *message);
void	join_philo(t_table *tab, t_philo *philosopher);
void	stop_all_philos(t_table *tab, t_philo *philo);
void	destroy_philo(t_table *tab, t_philo *philo);
int		stop_sim(t_philo *philo);
void	supervisor_2(t_table *tab, t_philo *philo, int i);
#endif