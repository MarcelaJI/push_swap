#include "../include/push_swap.h"

int		main(int argc, char **argv)
{
	t_stack	*stack_a;

	if (argc < 2)
		return (0);
	stack_a = parse_data(argv);
	if (!stack_a)
	{
		ft_printf("Error en el stack_a\n");
		return (EXIT_FAILURE);
	}
	if (ft_is_sorted(stack_a))
	{
		free_stack(&stack_a);
		return (EXIT_SUCCESS);
	}
	set_index(stack_a);
	print_stack(stack_a);
	free_stack(&stack_a);
	return (EXIT_SUCCESS);
}
