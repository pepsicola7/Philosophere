/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:51:16 by peli              #+#    #+#             */
/*   Updated: 2025/01/14 18:20:34 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libra.h"

void	creat_philo(t_table *tab)
{
	int	nbr_philo;

	nbr_philo = tab->nbr_philo;
	while (nbr_philo > 0)
	{
		
		nbr_philo--;
	}
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