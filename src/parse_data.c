#include "../include/push_swap.h"

t_stack     *parse_data(int argc, char **argv)
{
    char    **arr;
    t_stack     *stack;

    arr = NULL;
    stack = NULL;
    if (argc < 2)
    {   
        ft_printf("Insufficient number of arguments");
        return (NULL);
    }
    arr = get_arr(argc, argv);
    if (!arr)
        return (NULL);
    stack = validate_arr(arr);
    free_str_arr(&arr);
    return (stack);
}