#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h> 

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
	int				content;
	int				index;
	int				is_above_median;
	int				is_cheapest;
	int				operation_cost;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*prev;
}		t_stack;

typedef struct s_state
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		size_a;
	int		size_b;
}		t_state;

/* 📚 Utils */
void	ft_puterror(void);
void	free_stack(t_stack **stack);
void	print_stack(t_stack *stack);

/* 📚 Parsing */
t_stack	*parse_data(char **argv);
int		ft_is_valid_number(char *str);
int		validate_and_convert(char **argv);
int		validate_limits(char *str);
int		*init_array_from_args(char **argv, int *size);
int		fill_array_from_args(char **argv, int *arr);
t_stack	*array_to_stack(int *arr, int size);
t_stack	*create_stack_node(int value);
void	append_stack_node(t_stack **stack, t_stack *new_node);

/* 📚 Stack control */
void	set_index(t_stack *stack);
int		ft_is_sorted(t_stack *stack);

/* 📚 Stack moves */
void	ft_sa(t_state *state);
void	ft_sb(t_state *state);
void	ft_ss(t_state *state);
void	ft_pa(t_state *state);
void	ft_pb(t_state *state);
void	ft_ra(t_state *state);
void	ft_rb(t_state *state);
void	ft_rr(t_state *state);
void	ft_rra(t_state *state);
void	ft_rrb(t_state *state);
void	ft_rrr(t_state *state);

/* 📚 Sort helpers */
void	sort(t_stack *stack_a);
void	sort_three(t_state *state);
void	push_all_except_three(t_state *state);
void	sort_small_stack(t_state *state);

/* 📚 Move helpers */
void	set_target_nodes(t_state *state);
void	set_costs(t_state *state);
void	move_stack_a_to_top(t_state *state, t_stack *node);
void	move_stack_b_to_top(t_state *state, t_stack *node);
void	reinsert_from_b(t_state *state);

/* 📚 Calculation utilities */
int		find_lowest_index_position(t_stack *stack);
void	set_median(t_stack *stack, int size);
void	set_above_median(t_stack *stack, int size);
t_stack	*find_min_node(t_stack *stack);
t_stack	*find_cheapest_node(t_stack *stack_b);

#endif
