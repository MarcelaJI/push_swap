#include "../include/push_swap.h"

void    free_str_arr(char **arr)
{
    int     i;

    i = 0;
    if (!arr)
        return ;
    while (arr[i])
    {
        free(arr[i]);
        i++;
    }
    free(arr);
}