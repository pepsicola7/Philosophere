/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:51:16 by peli              #+#    #+#             */
/*   Updated: 2025/01/14 15:48:34 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src.h"


int ft_isdigit(char c)
{
	if (c < '0' || c > '9')
		return 0;
	else
		return 1;
}

int	ft_atoi(char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	if (str[i] == '-')
		return (-1);
	if (str[i] == '+')
		i++;
	if (!ft_isdigit(*str))
	{
		return (-1);
	}
	while (ft_isdigit(*str))
	{
		result = result * 10 + (*str - '0');
		str++;
		if (result > INT_MAX)
			return (-1);
	}
	if (*str != '\0')
		return (-1);
	return (result);
}

int	is_argv_valide(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	if (ft_atoi(str) == -1)
		return (-1);
	return (0);
}

int	check_arg(int argc, char **argv)
{
	int	i;
	int	result;

	i = 1;
	result = 0;
	if (argc > 6 || argc < 5 )
	{
		printf ("erreurs of the num of argument\n");
		return (-1);
	}
	while (argv[i])
	{
		if (is_argv_valide(argv[i]) == -1)
		{
			printf("The argv is not valide\n");
			return (-1);
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (check_arg(argc, argv) == -1)
		return (1);
	// pthread_t thread1;
	// pthread_t thread2;
	
	// long value1 = 1;

	// pthread_create(&thread1, NULL, computation, (void *)&value1);
	// pthread_create(&thread2, NULL, computation, (void *)&value1);
	// pthread_join(thread1, NULL);
	return (0);
}
// void	*computation(void *add)
// {
// 	long	*add_num = (long *)add;
// 	*add_num = 3;
// 	printf ("add : %ld\n", add_num);
// 	return (NULL);
// }