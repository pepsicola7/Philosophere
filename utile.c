/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:23:28 by peli              #+#    #+#             */
/*   Updated: 2025/01/17 19:19:44 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libra.h"

void	free_philo(t_table *tab, t_philo *philosopher)
{
	int	i;

	i = 0;
	while (i < tab->nbr_philo)
	{
		free(philosopher);
		i++;
	}
	return ;
}

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

void	get_time_start(t_table *tab)
{
	struct timeval tv;
	
	gettimeofday(&tv, NULL);
	tab->start = tv.tv_sec * 1000L + tv.tv_usec / 1000L;
}

long	get_time(void)
{
	struct timeval tv;
	
	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000L + tv.tv_usec / 1000L);
}

