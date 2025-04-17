#include "../include/push_swap.h"

t_stack     *parse_data(char **argv)
{
    int     size;
    int     *arr;
    t_stack     *stack;

    size = 0;
    arr = init_array_from_args(argv, &size);
    if (!arr)
        return (NULL);
    if (fill_array_from_args(argv, arr) == EXIT_FAILURE)
    {
        free(arr);
        return (NULL);
    }
    stack = array_to_stack(arr, size);
    if (!stack)
    {
        free(arr);
        return (NULL);
    }
    free(arr);
    return (stack);
}
