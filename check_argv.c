/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:57:03 by peli              #+#    #+#             */
/*   Updated: 2025/01/16 15:35:02 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libra.h"

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
		return (0);
	if (ft_atoi(str) == -1)
		return (0);
	return (1);
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
		return (0);
	}
	while (argv[i])
	{
		if (!is_argv_valide(argv[i]))
		{
			printf("The argv is not valide\n");
			return (0);
		}
		i++;
	}
	return (1);
}
