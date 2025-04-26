/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:21:57 by ingjimen          #+#    #+#             */
/*   Updated: 2025/04/26 18:04:28 by ingjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	*init_array_from_args(char **argv, int *size)
{
	int	i;
	int	count;
	int	*arr;

	i = 1;
	count = 0;
	while (argv[i])
	{
		count++;
		i++;
	}
	*size = count;
	arr = malloc(count * sizeof(int) + 1);
	if (!arr)
	{
		ft_puterror();
		return (NULL);
	}
	return (arr);
}

int	fill_array_from_args(char **argv, int *arr)
{
	int	i;
	int	index;
	int	number;

	i = 1;
	index = 0;
	while (argv[i])
	{
		number = ft_atol(argv[i]);
		if (number < INT_MIN || number > INT_MAX)
		{
			ft_puterror();
			return (EXIT_FAILURE);
		}
		arr[index++] = (int)number;
		i++;
	}
	return (EXIT_SUCCESS);
}
