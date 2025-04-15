#include "../include/push_swap.h"

int		main(int argc, char **argv)
{
	int *arr;
	int size;
	t_stack	*stack_a;

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
	stack_a = array_to_stack(arr, size);
	if (!stack_a)
	{
		ft_printf("Error al llenar el stack_a\n");
		return (0);
	}
	print_stack(stack_a);
	
	return (EXIT_SUCCESS);
}
