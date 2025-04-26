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
	int		size;
	int		*arr;
	t_stack	*stack;

	size = 0;
	if (validate_and_convert(argv) == EXIT_FAILURE)
		return (NULL);
	arr = init_array_from_args(argv, &size);
	if (!arr)
		return (NULL);
	if (fill_array_from_args(argv, arr) == EXIT_FAILURE)
	{
		free(arr);
		return (NULL);
	}
	if (has_duplicates(arr, size))
	{
		free(arr);
		ft_puterror();
		return (NULL);
	}
	stack = array_to_stack(arr, size);
	free(arr);
	return (stack);
}

