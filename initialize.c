/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:57:52 by peli              #+#    #+#             */
/*   Updated: 2025/01/23 12:27:01 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libra.h"

void	init_2(t_table *tab, t_philo *philosopher)
{
	philosopher->t_die = tab->t_die;
	philosopher->t_dodo = tab->t_dodo;
	philosopher->t_eat = tab->t_eat;
	philosopher->num_meal = tab->num_meal;
	philosopher->start = tab->start;
	philosopher->ate_meal = 0;
	philosopher->lastimeate = tab->start;
	philosopher->table = tab;
	philosopher->stop = 0;
}

void	initial_philo(t_table *tab, t_philo *philosopher)
{
	int	i;

	i = -1;
	while (++i < tab->nbr_philo)
	{
		init_2(tab, philosopher);
		philosopher->id = i + 1;
		pthread_mutex_init(&philosopher->status, NULL);
		if (i != tab->nbr_philo - 1)
		{
			philosopher->right_fork = &(tab->fork[i]);
			philosopher->left_fork = &(tab->fork[i + 1]);
		}
		else
		{
			philosopher->right_fork = &(tab->fork[0]);
			philosopher->left_fork = &(tab->fork[i]);
		}
		philosopher++;
	}
}

int	initial_tab(char **argv, t_table *tab)
{
	int	i;

	tab->nbr_philo = ft_atoi(argv[1]);
	if (tab->nbr_philo == 0)
		return (printf("There should have at least one philosopher\n"));
	tab->t_die = ft_atoi(argv[2]);
	tab->t_eat = ft_atoi(argv[3]);
	tab->t_dodo = ft_atoi(argv[4]);
	if (argv[5])
		tab->num_meal = ft_atoi(argv[5]);
	else
		tab->num_meal = -1;
	tab->fork = malloc(sizeof(pthread_mutex_t) * (tab->nbr_philo));
	if (!tab->fork)
		return (0);
	i = -1;
	while (++i < tab->nbr_philo)
		pthread_mutex_init(&tab->fork[i], NULL);
	pthread_mutex_init(&tab->printf, NULL);
	pthread_mutex_init(&tab->status, NULL);
	tab->stop = 1;
	tab->start = get_time();
	return (1);
}
