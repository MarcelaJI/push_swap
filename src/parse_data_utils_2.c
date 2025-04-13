#include "../include/push_swap.h"

int     validate_limits(char *str)
{
    long    min;
    long    max;
    long    result;

    min = INT_MIN;
    max = INT_MAX;
    result = ft_atol(str);
    if (result < min || result > max)
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}

int     validate_and_convert(char **argv)
{
    int i;

    i = 1;
    while(argv[i])
    {
        ft_printf("Analizando: %s\n", argv[i]);

        if(!ft_is_valid_number(argv[i]))
        {
            ft_puterror();
            return (EXIT_FAILURE);
        }
        if(validate_limits(argv[i]) == EXIT_FAILURE)
        {
            ft_puterror();
            return (EXIT_FAILURE);
        }
        i++;
    }
    return (EXIT_SUCCESS);
}