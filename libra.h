/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libra.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:51:06 by peli              #+#    #+#             */
/*   Updated: 2025/01/14 18:16:06 by peli             ###   ########.fr       */
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
	int	id;
	int	ate_meal;
	
} t_philo;


typedef struct s_table
{
	int	nbr_philo;
	int	t_die;
	int	t_eat;
	int	t_dodo;
	int	num_meal;
	t_philo philo;
	
} t_table;

int		check_arg(int argc, char **argv);
int		is_argv_valide(char *str);
int		ft_atoi(char *str);
void	printf_arg(t_table *tab);
int		*initial(char **argv, t_table *tab);

#endif