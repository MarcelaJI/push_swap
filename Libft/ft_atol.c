
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 17:50:15 by ingjimen          #+#    #+#             */
/*   Updated: 2025/04/13 17:50:38 by ingjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *nptr)
{
	char	*nptr_cpy;
	long	result;
	long	parity;

	nptr_cpy = (char *)nptr;
	while ((*nptr_cpy >= 9 && *nptr_cpy <= 13) || *nptr_cpy == ' ')
		nptr_cpy++;
	parity = 1;
	if (*nptr_cpy == '-' || *nptr_cpy == '+')
	{
		if (*nptr_cpy == '-')
			parity *= -1;
		nptr_cpy++;
	}
	result = 0;
	while (*nptr_cpy && (*nptr_cpy >= '0' && *nptr_cpy <= '9'))
	{
		result *= 10;
		result += (*nptr_cpy - 48);
		nptr_cpy++;
	}
	return (result * parity);
}