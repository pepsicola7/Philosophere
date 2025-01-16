/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libra.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:51:06 by peli              #+#    #+#             */
/*   Updated: 2025/01/16 19:04:07 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SRC_H
#define SRC_H

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

typedef struct s_table t_table;

typedef struct s_philo
{
	int			id;
	int			ate_meal;
	int			lastimeiate;
	pthread_t	thread;
	t_table		*table;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
} t_philo;

typedef struct s_table
{
	int				nbr_philo;
	int				t_die;
	int				t_eat;
	int				t_dodo;
	int				num_meal;
	long			timestamp; // ?? dans quelle struc?
	t_philo			*philo;
	pthread_mutex_t	*fork;
	// int				stop;
} t_table;

int		check_arg(int argc, char **argv);
int		is_argv_valide(char *str);
int		ft_atoi(char *str);
void	printf_arg(t_table *tab);
int		initial_tab(char **argv, t_table *tab);
void	free_philo(t_table *tab, t_philo *philosopher);
int		create_philo(t_table *tab);
void	initial_philo(t_table *tab, t_philo *philosopher);
void	*lifestyle(void *arg);
void	sleeping(t_philo *philo);
void	eating(t_philo *philo);

#endif