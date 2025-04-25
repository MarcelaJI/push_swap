#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack *stack_a;
	int lowest_pos;

	if (argc < 2)
		return (0);
	stack_a = parse_data(argv);
	if (!stack_a)
	{
		ft_putstr_fd("Error en el parseo\n", 2);
		return (1);
	}
	set_index(stack_a);
	ft_printf("=== STACK A ===\n");
	print_stack(stack_a);
	lowest_pos = find_lowest_index_position(stack_a);
	ft_printf("\nPosición del índice más bajo: %d\n", lowest_pos);
	free_stack(&stack_a);
	return (0);
}













