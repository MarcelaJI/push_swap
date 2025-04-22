
#include "../include/push_swap.h"

void    ft_sb(t_state *state)
{
    t_stack *first;
    t_stack *second;
    int     temp;

    if (!state->stack_b || !state->stack_b->next)
        return ;
    
    first = state->stack_b;
    second = state->stack_b->next;
    temp = first->content;
    first->content = second->content;
    second->content = temp;
    temp = first->index;
    first->index = second->index;
    second->index = temp;
    ft_printf("sb\n");
}