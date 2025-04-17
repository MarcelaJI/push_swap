#include "../include/push_swap.h"

int		main(int argc, char **argv)
{
	t_stack	*stack_a;

	if (argc < 2)
		return (0);
	stack_a = parse_data(argv);
	if (!stack_a)
		return (EXIT_FAILURE);
	//print_stack(stack_a);
	//print_test_node(stack_a);
	print_stack_reverse(stack_a);
	free_stack(&stack_a);
	return (EXIT_SUCCESS);
}
