/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:39:00 by ingjimen          #+#    #+#             */
/*   Updated: 2025/04/29 09:20:20 by ingjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	has_duplicates(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	check_errors(char **argv, int **array, int *size)
{
	if (validate_and_convert(argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	*array = init_array_from_args(argv, size);
	if (!*array)
		return (EXIT_FAILURE);
	if (fill_array_from_args(argv, *array) == EXIT_FAILURE
		|| has_duplicates(*array, *size))
	{
		free(*array);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

t_stack	*parse_data(int argc, char **argv)
{
	int		*array;
	t_stack	*stack;
	int		size;

	array = NULL;
	stack = NULL;
	size = 0;
	if (argc < 2)
		return (NULL);
	if (check_errors(argv, &array, &size) == EXIT_FAILURE)
	{
		ft_puterror();
		return (NULL);
	}
	stack = array_to_stack(array, size);
	free(array);
	if (!stack)
		ft_puterror();
	return (stack);
}
