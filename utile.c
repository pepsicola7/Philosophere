/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:23:28 by peli              #+#    #+#             */
/*   Updated: 2025/01/23 12:04:37 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libra.h"

void	printf_arg(t_table *tab)
{
	printf("nbr_philo : %d\n", tab->nbr_philo);
	printf("t_die : %d\n", tab->t_die);
	printf("t_eat : %d\n", tab->t_eat);
	printf("t_dodo : %d\n", tab->t_dodo);
	if (tab->num_meal)
		printf("num_meal : %d\n", tab->num_meal);
	return ;
}

long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000L + tv.tv_usec / 1000L);
}

int	stop_sim(t_philo *philo)
{
	pthread_mutex_lock(&philo->status);
	if (philo->stop == -1)
	{
		pthread_mutex_unlock(&philo->status);
		return (1);
	}
	pthread_mutex_unlock(&philo->status);
	return (0);
}
