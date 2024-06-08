/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptelo-de <ptelo-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:42:40 by ptelo-de          #+#    #+#             */
/*   Updated: 2024/06/08 20:16:08 by ptelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void ft_parsing(char **av)
{
	int	i;
	int	j;
	int	tmp;

	i = 1;
	while (av[i])
	{
		j = i + 1;
		tmp = ft_atoi2(av[i]);
		while(av[j])
		{
			if (tmp == ft_atoi2(av[j]))
				ft_error();
			j++;
		}
		i++;
	}
}