#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_state	state;

	if (argc != 4)
		return (EXIT_FAILURE);
	stack_a = parse_data(argv);
	if (!stack_a)
		return (EXIT_FAILURE);

	set_index(stack_a);

	state.stack_a = stack_a;
	state.stack_b = NULL;
	state.size_a = 3;
	state.size_b = 0;

	ft_printf("Antes de sort_three:\n");
	print_stack(state.stack_a);

	sort_three(&state);

	ft_printf("Después de sort_three:\n");
	print_stack(state.stack_a);

	free_stack(&state.stack_a);
	return (EXIT_SUCCESS);
}












