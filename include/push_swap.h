#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "../Libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include <stdarg.h>
# include <stdlib.h>
# include <stddef.h> 
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
	int		*content; // Valor del nodo
	int		index; // Índice del nodo
	int		is_above_median; // ¿Está por encima de la mediana?
	int		is_cheapest; // ¿Es el más barato de mover?
	int		operation_cost; // Coste de operación para moverlo
	struct s_stack	*target_node; // Dónde debería ir este nodo
	struct s_stack	*next; // Enlaces de lista doblemente enlazada
	struct s_stack	*prev; // Enlaces de lista doblemente enlazada
}	t_stack;

typedef struct s_state
{
	struct s_stack	*stack_a; // stack a
	struct s_stack	*stack_b; // stack b
	int				size_a; // size de stack a 
	int				size_b; // size de stack b
}	t_state;


// free

void    free_str_arr(char **arr);

#endif