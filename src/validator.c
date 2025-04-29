/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:52:33 by ingjimen          #+#    #+#             */
/*   Updated: 2025/04/29 09:24:15 by ingjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	validate_split(char **split)
{
	int	j;

	j = 0;
	while (split[j])
	{
		if (!ft_is_valid_number(split[j])
			|| validate_limits(split[j]) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		j++;
	}
	return (EXIT_SUCCESS);
}

int	validate_and_convert(char **argv)
{
	int		i;
	char	**split;

	i = 1;
	while (argv[i])
	{
		split = ft_split(argv[i], ' ');
		if (!split || !split[0] || validate_split(split) == EXIT_FAILURE)
		{
			ft_free_strs_arr(&split);
			return (EXIT_FAILURE);
		}
		ft_free_strs_arr(&split);
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
	long	result;

	result = ft_atol(str);
	if (result < INT_MIN || result > INT_MAX)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
