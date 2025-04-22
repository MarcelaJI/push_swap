
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

void    ft_pb(t_state *state)
{

    t_stack     *node_to_move; //variable temporal

    if (!state->stack_a)
        return ;
    node_to_move = state->stack_a; // guardo el nodo al mover
    state->stack_a = node_to_move->next; // actualizo A al siguiente
    if (state->stack_a)
        state->stack_a->prev = NULL;
    node_to_move->next = state->stack_b; // conecto con B
    if (state->stack_b)
        state->stack_b->prev = node_to_move;
    state->stack_b = node_to_move; // B apunta al nuevo nodo
    node_to_move->prev = NULL;
    state->size_a--;
    state->size_b++;
    ft_printf("pb\n");
}

void    ft_ra(t_state *state)
{
    t_stack *temp;
    t_stack *last_node;

    if (!state->stack_a || !state->stack_a->next)
        return ;
    temp = state->stack_a;
    state->stack_a = state->stack_a->next;
    state->stack_a->prev = NULL;
    last_node = state->stack_a;
    while (last_node->next)
        last_node = last_node->next;
    last_node->next = temp;
    temp->prev = last_node;
    temp->next = NULL;
    ft_printf("ra\n");
}

void     ft_rra(t_state *state)
{
    t_stack *last;
    t_stack *second_last;

    if (!state->stack_a || !state->stack_a->next)
        return ;
    last = state->stack_a;
    while (last->next)
    {
        second_last = last;
        last = last->next;
    }
    second_last->next = NULL;
    last->next = state->stack_a;
    state->stack_a->prev = last;
    state->stack_a = last;
    last->prev = NULL;
    ft_printf("rra\n");
}

void    ft_pa(t_state *state)
{
    t_stack *node_to_move;

    if (!state->stack_b)
        return ;
    
    node_to_move = state->stack_b;
    state->stack_b = node_to_move->next;
    if (state->stack_b)
        state->stack_b->prev = NULL;
    node_to_move->next = state->stack_a;
    if (state->stack_a)
        state->stack_a->prev = node_to_move;
    state->stack_a = node_to_move;
    node_to_move->prev = NULL;
    state->size_a++;
    state->size_b--;
    ft_printf("pa\n");
}