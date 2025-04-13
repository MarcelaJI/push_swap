#include "../include/push_swap.h"

int		main(int argc, char **argv)
{
	int result;

	result = validate_and_convert(argv);
// // 	//t_stack		*stack_a;

// // 	//stack_a = NULL;
	
// // 	//(void)stack_a;
	if (argc < 2)
		return (0);
	if (result == EXIT_FAILURE)
		return(EXIT_FAILURE);
	ft_printf("Todo salió bien:)\n");
	//parse_data(argc, argv);
	
// // 	// if (!parse_data(argc, &argv))
// // 	// {
// // 	// 	ft_putstr_fd(RED, 2);
// // 	// 	ft_putstr_fd("Error\n", 2);
// // 	// 	ft_putstr_fd(RESET, 2);
// // 	// 	return (-1);
// // 	// }
// // 	// if (ft_is_sorted(stack_a))
// // 	// {
// // 	// 	free_stack(stack_a);
// // 	// 	return (0);
// // 	// }
// // 	// ft_sorted(stack_a);
// // 	// free_stack(stack_a);
	return (EXIT_SUCCESS);
}
