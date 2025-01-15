/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libra.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:51:06 by peli              #+#    #+#             */
/*   Updated: 2025/01/15 17:06:45 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SRC_H
#define SRC_H

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

typedef struct s_philo
{
	int			id;
	int			ate_meal;
	int			lastimeiate;
	pthread_t	thread;
	t_table		*table;
} t_philo;


typedef struct s_table
{
	int				nbr_philo;
	int				t_die;
	int				t_eat;
	int				t_dodo;
	int				num_meal;
	t_philo			*philo;
	pthread_mutex_t	*fork;
	int				stop;
} t_table;

int		check_arg(int argc, char **argv);
int		is_argv_valide(char *str);
int		ft_atoi(char *str);
void	printf_arg(t_table *tab);
int		*initial(char **argv, t_table *tab);
void	free_philo(t_table *tab, t_philo *philosopher);

#endif