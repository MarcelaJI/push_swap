#include "../include/push_swap.h"

// Cuento argumentos y reservo memoria para mi array
int     *init_array_from_args(char **argv, int *size)
{
    int     i;
    int     count;
    int    *arr;

    i = 1;
    count = 0;
    while (argv[i])
    {
        count++;
        i++;
    }
    *size = count;
    arr = malloc(count * sizeof(int)); // esto se interpreta como un array de enteros
    if (!arr)
    {
        ft_puterror();
        return (NULL);
    }
    return (arr);
}

// valido, convierto y lleno el array con los valores numéricos
int     fill_array_from_args(char **argv, int *arr)
{
    int     i;
    int     index;
    int     number;

    i = 1;
    index = 0;
    while (argv[i])
    {
        if (!ft_is_valid_number(argv[i]))
        {
            ft_puterror();
            return (EXIT_FAILURE);
        }
        number = ft_atol(argv[i]);
        if (number < INT_MIN || number > INT_MAX)
        {
            ft_puterror();
            return (EXIT_FAILURE);
        }
        arr[index] = (int)number;
        index++;
        i++;
    }
    return (EXIT_SUCCESS);
}