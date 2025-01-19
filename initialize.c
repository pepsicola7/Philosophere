/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:57:52 by peli              #+#    #+#             */
/*   Updated: 2025/01/19 18:53:13 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libra.h"

void	initial_philo(t_table *tab, t_philo *philosopher)
{
	int	i;

	i = 0;
	while (i < tab->nbr_philo)
	{
		philosopher->t_die = tab->t_die;
		philosopher->t_dodo = tab->t_dodo;
		philosopher->t_eat = tab->t_eat;
		philosopher->num_meal = tab->num_meal;
		philosopher->start = tab->start;
		philosopher->id = i;
		philosopher->ate_meal = 0;
		philosopher->lastimeate = tab->start;
		philosopher->table = tab;
		philosopher->right_fork = &(tab->fork[i]);
		if (i != tab->nbr_philo - 1)
			philosopher->left_fork = &(tab->fork[i + 1]);
		else
			philosopher->left_fork = &(tab->fork[0]);
		i++;
		philosopher++;
		pthread_mutex_init(&philosopher->status, NULL);
	}
	return ;
}

int	initial_tab(char **argv, t_table *tab)
{
	int	i;

	i = 1;
	tab->nbr_philo = ft_atoi(argv[i]);
	i++;
	tab->t_die = ft_atoi(argv[i]);
	i++;
	tab->t_eat = ft_atoi(argv[i]);
	i++;
	tab->t_dodo = ft_atoi(argv[i]);
	i++;
	if (argv[i])
		tab->num_meal = ft_atoi(argv[i]);
	tab->fork = malloc(sizeof(pthread_mutex_t) * (tab->nbr_philo));
	if(!tab->fork)
		return (0);
	i = 0;
	while (i < tab->nbr_philo)
	{
		pthread_mutex_init(&tab->fork[i], NULL);
		i++;
	}
	pthread_mutex_init(&tab->printf, NULL);
	pthread_mutex_init(&tab->status, NULL);
	tab->stop = 1;
	return (1);
}
