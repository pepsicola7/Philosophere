/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:51:16 by peli              #+#    #+#             */
/*   Updated: 2025/01/19 22:23:46 by peli             ###   ########.fr       */
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
	int j;

	j = 0;
	while (j < tab->nbr_philo)
	{
		pthread_mutex_lock(&philo[j].status);
		philo[j].stop = -1;
		pthread_mutex_unlock(&philo[j].status);
		++j;
	}
}

int	all_philo_eat_num_meal( t_philo *philo)
{
	int i;
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

void	supervisor(t_table *tab, t_philo *philo)
{
	int	i;

	while (1)
	{
		i = 0;
		if (!all_philo_eat_num_meal(philo))
		{
			stop_all_philos(tab, philo);
			return ;
		}
		while (i < tab->nbr_philo)
		{
			pthread_mutex_lock(&philo[i].status);
			if ((get_time() - tab->philo[i].lastimeate) >= tab->t_die)
			{
				pthread_mutex_unlock(&philo[i].status);
				pthread_mutex_lock(&tab->printf);
				printf("%ld %d died\n", get_time() - tab->start, philo[i].id);
				pthread_mutex_unlock(&tab->printf);
				stop_all_philos(tab, philo);
				return ;
			}
			else
				pthread_mutex_unlock(&philo[i].status);
			i++;
		}
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

int	create_philo(t_table *tab)
{
	t_philo		*philosopher;
	int			i;

	tab->philo = malloc(sizeof(t_philo) * (tab->nbr_philo));
	if (!tab->philo)
		return (0);
	get_time_start(tab);
	philosopher = tab->philo;
	initial_philo(tab, philosopher);
	i = 0;
	while (i < tab->nbr_philo)
	{
		pthread_create(&philosopher[i].thread, NULL, lifestyle, &philosopher[i]);
		i++;
	}
	supervisor(tab, philosopher);
	join_philo(tab, philosopher);
	destroy_philo(tab, philosopher);
	free(tab->fork);
	free(philosopher);
	return (1);
}

int	main(int argc, char **argv)
{
	t_table tab;
	
	if (!check_arg(argc, argv))
		return (1);
	if (!initial_tab(argv, &tab))
		return(1);
	if (!create_philo(&tab))
		return(1);
	// printf_arg(&tab);
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

// For initialize
// int pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *mutexattr);

// For lock and unlock
// int pthread_mutex_lock(pthread_mutex_t *mutex);
// int pthread_mutex_unlock(pthread_mutex_t *mutex);
// Both of these functions return 0 for success and an error code otherwise.

// For destroy
// int pthread_mutex_destroy(pthread_mutex_t *mutex);
// This function destroys an unlocked mutex;