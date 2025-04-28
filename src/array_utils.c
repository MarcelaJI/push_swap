/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:21:57 by ingjimen          #+#    #+#             */
/*   Updated: 2025/04/28 11:32:27 by ingjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	count_numbers(char **argv)
{
	int		count;
	int		i;
	int		j;
	char	**split;

	count = 0;
	i = 1;
	while (argv[i])
	{
		split = ft_split(argv[i], ' ');
		if (!split)
			return (-1);
		j = 0;
		while (split[j])
		{
			count++;
			j++;
		}
		ft_free_strs_arr(&split);
		i++;
	}
	return (count);
}

int	*init_array_from_args(char **argv, int *size)
{
	int	*array;
	int	total;

	total = count_numbers(argv);
	if (total <= 0)
		return (NULL);
	array = malloc(sizeof(int) * total);
	if (!array)
		return (NULL);
	*size = total;
	return (array);
}

int	fill_array_from_args(char **argv, int *arr)
{
	int		i;
	int		j;
	int		index;
	char	**split;

	i = 1;
	index = 0;
	while (argv[i])
	{
		split = ft_split(argv[i], ' ');
		if (!split)
			return (EXIT_FAILURE);
		j = 0;
		while (split[j])
		{
			arr[index++] = ft_atoi(split[j]);
			j++;
		}
		ft_free_strs_arr(&split);
		i++;
	}
	return (EXIT_SUCCESS);
}
