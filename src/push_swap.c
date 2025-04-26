#include "../include/push_swap.h"

int main(int argc, char **argv)
{
    t_stack *stack_a;

    stack_a = NULL;
    if (argc > 1)
    {
        stack_a = parse_data(argv);
        if (!stack_a)
            return (-1);
        if (!ft_is_sorted(stack_a))
            sort(stack_a);
        free_stack(&stack_a);
    }
    return (0);
}















