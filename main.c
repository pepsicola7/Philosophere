/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:51:16 by peli              #+#    #+#             */
/*   Updated: 2025/01/23 12:18:16 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libra.h"

int	all_philo_eat_num_meal(t_philo *philo)
{
	int	i;
	int	compteur;

	i = 0;
	compteur = 0;
	while (i < philo->table->nbr_philo)
	{
		pthread_mutex_lock(&philo[i].status);
		if (philo[i].ate_meal == philo[i].num_meal)
			compteur++;
		pthread_mutex_unlock(&philo[i].status);
		i++;
	}
	if (compteur == philo->table->nbr_philo)
		return (0);
	return (1);
}

void	supervisor_2(t_table *tab, t_philo *philo, int i)
{
	pthread_mutex_unlock(&philo[i].status);
	pthread_mutex_lock(&tab->printf);
	printf("%ld %d died\n", get_time() - tab->start, philo[i].id);
	pthread_mutex_unlock(&tab->printf);
	stop_all_philos(tab, philo);
}

void	supervisor(t_table *tab, t_philo *philo)
{
	int	i;

	while (1)
	{
		i = 0;
		if (!all_philo_eat_num_meal(philo) && tab->nbr_philo != 0)
		{
			printf("all have eaten\n");
			stop_all_philos(tab, philo);
			return ;
		}
		while (i < tab->nbr_philo)
		{
			pthread_mutex_lock(&philo[i].status);
			if ((get_time() - tab->philo[i].lastimeate) >= tab->t_die)
			{
				supervisor_2(tab, philo, i);
				return ;
			}
			else
				pthread_mutex_unlock(&philo[i].status);
			i++;
		}
		usleep(1000);
	}
}

int	create_philo(t_table *tab)
{
	t_philo		*philo;
	int			i;

	tab->philo = malloc(sizeof(t_philo) * (tab->nbr_philo));
	if (!tab->philo)
		return (0);
	philo = tab->philo;
	initial_philo(tab, philo);
	i = 0;
	while (i < tab->nbr_philo)
	{
		pthread_create(&philo[i].thread, NULL, lifestyle, &philo[i]);
		i++;
	}
	supervisor(tab, philo);
	join_philo(tab, philo);
	destroy_philo(tab, philo);
	free(tab->fork);
	free(philo);
	return (1);
}

int	main(int argc, char **argv)
{
	t_table	tab;

	if (!check_arg(argc, argv))
		return (1);
	if (!initial_tab(argv, &tab))
		return (1);
	if (!create_philo(&tab))
		return (1);
	return (0);
}
