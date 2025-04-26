/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:39:00 by ingjimen          #+#    #+#             */
/*   Updated: 2025/04/26 19:10:27 by ingjimen         ###   ########.fr       */
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

t_stack	*parse_data(char **argv)
{
	t_stack	*stack;
	int		*arr;
	int		size;

	stack = NULL;
	arr = NULL;
	size = 0;
	if (validate_and_convert(argv) == EXIT_FAILURE)
		return (NULL);
	arr = init_array_from_args(argv, &size);
	if (arr == NULL || fill_array_from_args(argv, arr) == EXIT_FAILURE
		|| has_duplicates(arr, size))
	{
		free(arr);
		ft_puterror();
		return (NULL);
	}
	stack = array_to_stack(arr, size);
	free(arr);
	if (!stack)
		ft_puterror();
	return (stack);
}
