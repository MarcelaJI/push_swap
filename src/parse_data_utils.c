#include "../include/push_swap.h"

int     ft_is_valid_number(char *str)
{
    int  i;

    i = 0;
    if (str == NULL)
        return (0);
    if (str[i] == '-' || str[i] == '+')
    {
        i++;
        if (str[i] == '\0')
            return (0);
    }
    while (str[i])
    {
        if(!ft_isdigit(str[i]))
            return (0);
        i++;
    }
    return (1);
}

int validate_input(char **argv)
{
    int i;
    int result;

    i = 1;
    while (argv[i])
    {
        result = ft_is_valid_number(argv[i]);
        if (result == 0)
            return (EXIT_FAILURE);
        i++;
    }
    return (EXIT_SUCCESS);
}
t_stack *parse_data(int argc, char **argv)
{
    t_stack *stack;

    stack = NULL;
    (void)argc;
    int result;

    result = validate_input(argv);
    if (result == EXIT_SUCCESS)
        ft_printf("everything's fine\n");
    else
        ft_printf("Hubo un error en la validación\n");
    return (stack);
}