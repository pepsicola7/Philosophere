/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:23:28 by peli              #+#    #+#             */
/*   Updated: 2025/01/15 15:37:34 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libra.h"

void	free_philo(t_table *tab, t_philo *philosopher)
{
	int	i;

	i = 0;
	while (i <= tab->nbr_philo)
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

int	*initial(char **argv, t_table *tab)
{
	int	i;

	i = 1;
	tab->nbr_philo = ft_atoi(argv[i]);
	i++;
	tab->t_die = ft_atoi(argv[i]);
	i++;
	tab->t_eat = ft_atoi(argv[i]);
	i++;
	tab->t_dodo = ft_atoi(argv[i]);
	i++;
	if (argv[i])
		tab->num_meal = ft_atoi(argv[i]);
	return (0);
}
