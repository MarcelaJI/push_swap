
#include "../include/push_swap.h"

void    ft_sa(t_state *state)
{
    t_stack *stack_a;
    t_stack *first;
    t_stack *second;
    int temp;

    stack_a = state->stack_a;
    if (!stack_a || !stack_a->next)
        return ;
    first = stack_a;
    second = stack_a->next;
    temp = first->content;
    first->content = second->content;
    second->content = temp;
    temp = first->index;
    first->index = second->index;
    second->index = temp;
    ft_printf("sa\n");
}

