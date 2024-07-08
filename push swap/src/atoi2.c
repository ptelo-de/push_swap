/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptelo-de <ptelo-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:13:57 by ptelo-de          #+#    #+#             */
/*   Updated: 2024/06/16 21:03:36 by ptelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//calculates the number an atribute can be translated
//does not allow buffer overflow or returning the number 
// if trash values follow the digit part.

int	ft_atoi2(const char *nptr)
{
	long long	nb;
	int	i;
	int	sign;

	nb = 0;
	i = 0;
	sign = 1;
	while (((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] <= '9' && nptr[i] >= '0')
	{
		if (nb*10 < nb)
			ft_error();
		nb = 10 * nb + (nptr[i] - 48);
		i++;
	}
	nb = nb * sign;
	if (nptr[i] || nb > 2147483647 || nb < -2147483648)
		ft_error();
	return (nb);
}