/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lifestyle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 19:02:15 by peli              #+#    #+#             */
/*   Updated: 2025/01/23 12:10:43 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libra.h"

void	philo_printf(t_philo *philo, char *message)
{
	pthread_mutex_lock(&philo->table->printf);
	pthread_mutex_lock(&philo->status);
	if (philo->stop == -1)
	{
		pthread_mutex_unlock(&philo->table->printf);
		pthread_mutex_unlock(&philo->status);
		return ;
	}
	pthread_mutex_unlock(&philo->status);
	printf("%ld %d %s\n", get_time() - philo->start, philo->id, message);
	pthread_mutex_unlock(&philo->table->printf);
}

void	eatind_2(t_philo *philo)
{
	pthread_mutex_lock(&philo->status);
	philo->lastimeate = get_time();
	pthread_mutex_unlock(&philo->status);
	philo_printf(philo, "is eating");
	usleep(philo->t_eat * 1000);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_lock(&philo->status);
	philo->ate_meal++;
	pthread_mutex_unlock(&philo->status);
	usleep(5000);
}

void	eating(t_philo *philo)
{
	if (philo->table->nbr_philo == 1)
	{
		philo_printf(philo, "has taken a fork");
		usleep(philo->table->t_die * 1000);
		return ;
	}
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		philo_printf(philo, "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		philo_printf(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		philo_printf(philo, "has taken a fork");
		pthread_mutex_lock(philo->left_fork);
		philo_printf(philo, "has taken a fork");
	}
	eatind_2(philo);
}

void	sleeping(t_philo *philo)
{
	philo_printf(philo, "is sleeping");
	usleep(philo->t_dodo * 1000);
}

void	*lifestyle(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(200);
	while (1)
	{
		if (stop_sim(philo) == 1)
			break ;
		eating(philo);
		if (stop_sim(philo) == 1)
			break ;
		sleeping(philo);
		if (stop_sim(philo) == 1)
			break ;
		philo_printf(philo, "is thinking");
	}
	return (NULL);
}
