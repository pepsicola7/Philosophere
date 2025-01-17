/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lifestyle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 19:02:15 by peli              #+#    #+#             */
/*   Updated: 2025/01/17 22:18:00 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libra.h"

void	thinking(t_philo *philo)
{
	pthread_mutex_lock(philo->table->printf);
	printf("%ld %d is thinking\n", get_time() - philo->table->start, philo->id);
	pthread_mutex_unlock(philo->table->printf);
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(philo->table->printf);
	printf("%ld %d is eating\n", get_time() - philo->table->start, philo->id);
	pthread_mutex_unlock(philo->table->printf);
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
	philo->lastimeate = get_time();
}

void	sleeping(t_philo *philo)
{
	pthread_mutex_lock(philo->table->printf);
	printf("%ld %d is sleeping\n", get_time() - philo->table->start, philo->id);
	pthread_mutex_unlock(philo->table->printf);
	usleep(philo->table->t_dodo);
}

void	*lifestyle(void *arg)
{
	t_philo *philo;

	philo = (t_philo*)arg;
	while(1)
	{
		thinking(philo);
		eating(philo);
		if (philo->table->num_meal && philo->ate_meal == philo->table->num_meal)
			break;
		sleeping(philo);
		pthread_mutex_lock(philo->table->status);
		if (philo->table->stop == -1)
		{
			pthread_mutex_unlock(philo->table->status);
			break;
		}
		pthread_mutex_unlock(philo->table->status);
	}
	return (NULL);
}
