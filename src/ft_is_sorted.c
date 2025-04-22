
#include "../include/push_swap.h"

int     ft_is_sorted(t_stack *stack)
{
    while (stack && stack->next)
    {
        if (stack->content > stack->next->content)
            return (0);
        stack = stack->next;
    }
    return (1);
}