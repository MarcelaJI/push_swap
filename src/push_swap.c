#include "../include/push_swap.h"

int		main(int argc, char **argv)
{
	int *arr;
	int size;

	if (argc < 2)
		return (0);
	arr = init_array_from_args(argv, &size);
	if (!arr)
		return (EXIT_FAILURE);
	if (fill_array_from_args(argv, arr) == EXIT_FAILURE)
	{
		free(arr);
		return (EXIT_FAILURE);
	}
	

	return (EXIT_SUCCESS);
}
