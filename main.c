/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:51:16 by peli              #+#    #+#             */
/*   Updated: 2025/01/15 16:24:07 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libra.h"

// void	thinking(t_philo *philo)
// {
		// printf(" timestamp_in_ms %d is thinking", philo->id);
	
// }

void	eating(t_philo *philo)
{
	printf(" timestamp_in_ms %d is eating", philo->id);
	usleep(philo->table->t_eat);
}

void	sleeping(t_philo *philo)
{
	printf(" timestamp_in_ms %d is sleeping", philo->id);
	usleep(philo->table->t_dodo);
}

void	lifestyle(void *arg)
{
	t_philo *philo;

	philo = arg;
	while(1)
	{
		// thinking(philo);
		eating(philo);
		sleeping(philo);
	}
}

void	initial_philo(t_table *tab, t_philo *philosopher)
{
	int	i;

	i = 1;
	while (i <= tab->nbr_philo)
	{
		philosopher->id = i;
		philosopher->ate_meal = 0;
		i++;
	}
	return ;
}

void	create_philo(t_table *tab)
{
	t_philo			*philosopher;
	int				i;

	philosopher = tab->philo;
	philosopher = malloc(sizeof(t_philo) * (tab->nbr_philo));
	if (!philosopher)
		return (1);
	initial_philo(tab, philosopher);
	while (i <= tab->nbr_philo)
	{
		pthread_create(&philosopher[i].thread, NULL, lifestyle, &philosopher[i]);
		i++;
	}
	i = 0;
	//supervisor(tab);
	while (i < tab->nbr_philo)
	{
		pthread_join(philosopher[i].thread, NULL);
		i++;
	}
	free_philo(tab, philosopher);
	return ;
}

int	main(int argc, char **argv)
{
	t_table *tab;
	
	tab = malloc(sizeof(size_t) * 1);
	if (!tab)
	{
		printf("malloc failed\n");
		return (1);
	}
	if (check_arg(argc, argv) == -1)
		return (1);
	if (initial(argv, tab) != 0)
		return(1);
	creat_philo(tab);
	printf_arg(tab);
	free(tab);
	return (0);
}

// int	main(int argc, char **argv)
// {
// 	if (check_arg(argc, argv) == -1)
// 		return (1);
	
// 	pthread_t thread1;
// 	pthread_t thread2;
	
// 	long value1 = 1;

// 	pthread_create(&thread1, NULL, computation, (void *)&value1);
// 	pthread_create(&thread2, NULL, computation, (void *)&value1);
// 	pthread_join(thread1, NULL);
// 	return (0);
// }
// void	*computation(void *add)
// {
// 	long	*add_num = (long *)add;
// 	*add_num = 3;
// 	printf ("add : %ld\n", add_num);
// 	return (NULL);
// }