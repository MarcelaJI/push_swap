/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:52:33 by ingjimen          #+#    #+#             */
/*   Updated: 2025/04/28 10:53:27 by ingjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"


int	validate_and_convert(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!argv[i][0])
			return (EXIT_FAILURE);
		if (!ft_is_valid_number(argv[i]) || validate_limits(argv[i]) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}


int	ft_is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	if (str[i] == '-' || str[i] == '+')
	{
		i++;
		if (str[i] == '\0')
			return (0);
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	validate_limits(char *str)
{
	long	min;
	long	max;
	long	result;

	min = INT_MIN;
	max = INT_MAX;
	result = ft_atol(str);
	if (result < min || result > max)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
