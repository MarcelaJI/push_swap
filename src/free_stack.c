#include "../include/push_swap.h"

void    free_stack(t_stack *stack)
{
    t_stack *temp;

    temp = stack;
    while (temp)
    {
        stack = stack->next; // Avanzo el puntero principal para no perderlo porque temp apunta al 1 
        free(temp); //libero el primer nodo
        temp = stack;
    }
}