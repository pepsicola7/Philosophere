/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lifestyle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 19:02:15 by peli              #+#    #+#             */
/*   Updated: 2025/01/16 19:03:03 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libra.h"

void	thinking(t_philo *philo)
{
		printf("%ld %d is thinking\n", philo->table->timestamp, philo->id);
}

void	eating(t_philo *philo)
{
	printf("%ld %d is eating\n", philo->table->timestamp, philo->id);
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->right_fork);
		pthread_mutex_lock(philo->left_fork);
	}
	if (philo->id % 2 != 0)
	{
		pthread_mutex_lock(philo->left_fork);
		pthread_mutex_lock(philo->right_fork);
	}
	usleep(philo->table->t_eat);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	philo->ate_meal++;
	philo->lastimeiate += philo->table->t_eat;
	philo->table->timestamp += philo->table->t_eat;
}

void	sleeping(t_philo *philo)
{
	printf("%ld %d is sleeping\n", philo->table->timestamp, philo->id);
	usleep(philo->table->t_dodo);
	philo->table->timestamp += philo->table->t_dodo;
}

void	*lifestyle(void *arg)
{
	t_philo *philo;

	philo = (t_philo*)arg;
	while(1)
	{
		thinking(philo);
		eating(philo);
		sleeping(philo);
	}
	return (NULL);
}
