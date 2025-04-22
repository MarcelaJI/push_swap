#include "../include/push_swap.h"

int		main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_state state;

	if (argc < 2)
		return (0);
	stack_a = parse_data(argv);
	if (!stack_a)
	{
		ft_printf("Error en el stack_a\n");
		return (EXIT_FAILURE);
	}
	// if (ft_is_sorted(stack_a))
	// {
	// 	free_stack(&stack_a);
	// 	return (EXIT_SUCCESS);
	// }
	set_index(stack_a);
	state.stack_a = stack_a;
	state.stack_b = NULL;
	state.size_a = argc - 1;
	state.size_b = 0;

	ft_printf("Antest de sa:\n");
	print_stack(state.stack_a);
	ft_sa(&state);
	ft_printf("Después de sa\n");
	print_stack(state.stack_a);
	free_stack(&stack_a);
	return (EXIT_SUCCESS);
}
