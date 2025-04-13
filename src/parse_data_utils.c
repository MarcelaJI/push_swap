#include "../include/push_swap.h"

int     ft_isdigit(int c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}

int     ft_is_valid_number(char *str)
{
    int  i;

    i = 0;
    if (str == NULL)
    {
        ft_printf("The string is empty");
        return (0);
    }
    if (str[i] == '-' || str[i] == '+')
    {
        i++;
        if (str[i] == '\0')
            return (0);
    }
    if (!ft_isdigit(str[i]))
        return (0);
    while (str[i])
    {
        if(!ft_isdigit(str[i]))
            return (0);
        i++;
    }
    return (1);
}

int     ft_is_duplicate(t_stack *stack, int value)
{
    t_stack *temp; // utilizo un puntero temporal para recorrer sin modificar el original, y así no pierdo referencia al primer nodo.

    if (!stack)
        return (0);
    temp = stack;
    while (temp)
    {
        if (temp->content == value) // comparo el nodo actual con el número que me pasan, si son iguales hay un duplicado
            return (1);
        temp = temp->next;
    }
    return (0);
}