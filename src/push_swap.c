#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack *stack_a;
	t_state state;

	if (argc < 2)
		return (0);

	stack_a = parse_data(argv);
	if (!stack_a)
		return (EXIT_FAILURE);

	set_index(stack_a);
	state.stack_a = stack_a;
	state.stack_b = NULL;
	state.size_a = argc - 1;
	state.size_b = 0;

	ft_printf("Antes de pb:\n");
	print_stack(state.stack_a);
	ft_pb(&state);
	ft_printf("Después de pb:\n");
	ft_printf("Stack A:\n");
	print_stack(state.stack_a);
	ft_printf("Stack B:\n");
	print_stack(state.stack_b);

	free_stack(&state.stack_a);
	free_stack(&state.stack_b);
	return (EXIT_SUCCESS);
}

