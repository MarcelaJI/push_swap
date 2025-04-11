
#include "../include/push_swap.h"

int     ft_is_sorted(t_stack *stack)
{
    t_stack     *current;

    if (stack == NULL || stack->next == NULL)
    {
        return (1); // // Retorno 1 ya que considero que una lista vacía o con un solo nodo está ordenada
    }
    current = stack;
    while (current && current->next)
    {
        if (current->content > current->next->content)
            return (0); // Si los elementos no están ordenados retorno 0
        current = current->next;
    }
    return (1);
}