#include "../include/push_swap.h"

int		main(int argc, char **argv)
{
	t_stack		*stack_a;

	stack_a = NULL;
	if (argc < 2)
		return (0);
	if (!parse_data(argc, &argv))
	{
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}
	if (ft_is_sorted(stack_a))
	{
		free_stack(stack_a);
		return (0);
	}
	ft_sorted(stack_a);
	free_stack(stack_a);
	return (0);
}
