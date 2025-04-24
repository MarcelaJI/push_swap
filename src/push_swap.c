#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_state	state;

	if (argc < 2)
		return (0);

	stack_a = parse_data(argv);
	if (!stack_a)
		return (EXIT_FAILURE);

	state.stack_a = stack_a;
	state.stack_b = NULL;
	state.size_a = argc - 1;
	state.size_b = 0;

	set_index(state.stack_a);
	set_above_median(state.stack_a, state.size_a);
	ft_printf("=== STACK A ===\n");
	print_stack(state.stack_a);
	free_stack(&state.stack_a);
	return (EXIT_SUCCESS);
}






