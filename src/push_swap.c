#include "../include/push_swap.h"

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack *stack_a;
	t_state state;

	if (argc < 2)
		return (0);

	// Parsear argumentos y construir stack_a
	stack_a = parse_data(argv);
	if (!stack_a)
		return (EXIT_FAILURE);

	// Setear índices
	set_index(stack_a);

	// Inicializar estado
	state.stack_a = stack_a;
	state.stack_b = NULL;
	state.size_a = argc - 1;
	state.size_b = 0;

	// Hacer dos pb para llenar stack_b
	ft_pb(&state);
	ft_pb(&state);

	ft_printf("Antes de rb:\n");
	print_stack(state.stack_b);

	// Ejecutar rb
	ft_rb(&state);

	ft_printf("Después de rb:\n");
	print_stack(state.stack_b);

	// Liberar memoria
	free_stack(&state.stack_a);
	free_stack(&state.stack_b);
	return (EXIT_SUCCESS);
}


