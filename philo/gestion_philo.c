/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:55:20 by peli              #+#    #+#             */
/*   Updated: 2025/01/23 11:56:29 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libra.h"

void	join_philo(t_table *tab, t_philo *philosopher)
{
	int	i;

	i = 0;
	while (i < tab->nbr_philo)
	{
		pthread_join(philosopher[i].thread, NULL);
		i++;
	}
}

void	stop_all_philos(t_table *tab, t_philo *philo)
{
	int	j;

	j = 0;
	while (j < tab->nbr_philo)
	{
		pthread_mutex_lock(&philo[j].status);
		philo[j].stop = -1;
		pthread_mutex_unlock(&philo[j].status);
		++j;
	}
}

void	destroy_philo(t_table *tab, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < tab->nbr_philo)
	{
		pthread_mutex_destroy(&philo[i].status);
		pthread_mutex_destroy(&tab->fork[i]);
		i++;
	}
	pthread_mutex_destroy(&tab->printf);
	pthread_mutex_destroy(&tab->status);
}
