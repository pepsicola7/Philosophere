/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:23:28 by peli              #+#    #+#             */
/*   Updated: 2025/01/19 22:01:22 by peli             ###   ########.fr       */
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

// void	ft_usleep(useconds_t time_in_ms)
// {
// 	unsigned long	start_time;
// 	unsigned long	current_time;

// 	start_time = get_time(); // Capture du temps de départ
// 	while (1)
// 	{
// 		current_time = get_time();
// 		if ((current_time - start_time) >= time_in_ms) // Vérifiez si le temps a expiré
// 			break;
// 		usleep(500); // Pause courte pour éviter de surcharger le processeur
// 	}
// }


