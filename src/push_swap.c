#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	if (argc < 2)
		return (0);
	if (validate_and_convert(argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	stack_a = parse_data(argv);
	if (!stack_a)
		return (EXIT_FAILURE);
	if (!ft_is_sorted(stack_a))
		sort(stack_a);
	free_stack(&stack_a);
	return (0);
}














