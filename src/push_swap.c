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
	set_index(stack_a);
	state.stack_a = stack_a;
	state.stack_b = NULL;
	state.stack_b = create_stack_node(42);
	append_stack_node(&state.stack_b, create_stack_node(100));
	append_stack_node(&state.stack_b, create_stack_node(5));
	ft_printf("=== STACK A ===\n");
	print_stack(state.stack_a);
	ft_printf("=== STACK B ===\n");
	print_stack(state.stack_b);
	ft_printf("\n=== Target Nodes ===\n");
	set_target_node(&state);
	print_target_nodes(state.stack_a);
	free_stack(&state.stack_a);
	free_stack(&state.stack_b);
	return (0);
}





