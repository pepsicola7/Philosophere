/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lifestyle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 19:02:15 by peli              #+#    #+#             */
/*   Updated: 2025/01/17 21:04:46 by peli             ###   ########.fr       */
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

// int	died(t_philo *philo)
// {
// 	int	i;

// 	pthread_mutex_lock(philo->table->printf);
// 	i = philo->table->timestamp - philo->lastimeate;
// 	pthread_mutex_unlock(philo->table->printf);
// 	if (i >= 1000)
// 	{
// 		pthread_mutex_lock(philo->table->printf);
// 		printf("%ld %d died\n", philo->table->timestamp, philo->id);
// 		pthread_mutex_unlock(philo->table->printf);
// 		pthread_mutex_lock(philo->table->printf);
// 		philo->table->stop = -1;
// 		pthread_mutex_unlock(philo->table->printf);
// 		return(0);
// 	}
// 	return (1);
// }

void	*lifestyle(void *arg)
{
	t_philo *philo;

	philo = (t_philo*)arg;
	while(philo->table->stop != -1)
	{
		thinking(philo);
		// if ((!died(philo)) || philo->table->stop == -1)
		// 	break;
		eating(philo);
		if (philo->table->num_meal && philo->ate_meal == philo->table->num_meal)
			break;
		// if ((!died(philo)) || philo->table->stop == -1)
		// 	break;
		sleeping(philo);
		// if ((!died(philo)) || philo->table->stop == -1)
		// 	break;
	}
	return (NULL);
}
