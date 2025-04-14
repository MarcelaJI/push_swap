
#include "../include/push_swap.h"

t_stack *create_stack_node(int value)
{
    t_stack *node;

    node = malloc(sizeof(t_stack));
    if (!node)
        return (NULL);
    node->content = value;
    node->index = 0;
    node->is_cheapest = 0;
    node->is_above_median = 0;
    node->operation_cost = 0;
    node->target_node = NULL;
    node->next = NULL;
    node->prev= NULL;
    return (node);
}

void    append_stack_node(t_stack **stack, t_stack *new_node)
{
    t_stack *temp;

    if (*stack == NULL)
    {
        *stack = new_node;
        return ;
    }
    temp = *stack;
    while(temp->next)
    {
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->prev = temp;
}