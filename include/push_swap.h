#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include <limits.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define WHITE "\033[37m"
# define RESET "\033[0m"

typedef struct s_stack
{
	int content;                // Valor del nodo
	int index;                   // Índice del nodo
	int is_above_median;         // ¿Está por encima de la mediana?
	int is_cheapest;             // ¿Es el más barato de mover?
	int operation_cost;          // Coste de operación para moverlo
	struct s_stack *target_node; // Dónde debería ir este nodo
	struct s_stack *next;        // Enlaces de lista doblemente enlazada
	struct s_stack *prev;        // Enlaces de lista doblemente enlazada
}		t_stack;

typedef struct s_state
{
	struct s_stack *stack_a; // stack a
	struct s_stack *stack_b; // stack b
	int size_a;              // size de stack a
	int size_b;              // size de stack b
}		t_state;

// errores
void	ft_puterror(void);

void	print_stack(t_stack *stack);
void	free_stack(t_stack **stack);

// parseo
t_stack	*parse_data(char **argv);
int		ft_is_valid_number(char *str);
int		validate_and_convert(char **argv);
int		validate_limits(char *str);
int		*init_array_from_args(char **argv, int *size);
int		fill_array_from_args(char **argv, int *arr);
t_stack	*create_stack_node(int value);
void	append_stack_node(t_stack **stack, t_stack *new_node);
t_stack	*array_to_stack(int *arr, int size);
void	print_test_node(t_stack *stack_a);
void	print_stack_reverse(t_stack *stack);

#endif