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