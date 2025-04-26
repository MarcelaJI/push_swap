#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack;

	if (argc < 2)
		return (0);
	stack = parse_data(argv);
	if (!stack)
		return (EXIT_FAILURE);
	if (!ft_is_sorted(stack))
		sort(stack);
	free_stack(&stack);
	return (0);
}













