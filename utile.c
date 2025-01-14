/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:23:28 by peli              #+#    #+#             */
/*   Updated: 2025/01/14 17:54:57 by peli             ###   ########.fr       */
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
