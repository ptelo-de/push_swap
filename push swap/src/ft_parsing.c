/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptelo-de <ptelo-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:42:40 by ptelo-de          #+#    #+#             */
/*   Updated: 2024/06/18 19:33:51 by ptelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// void	ft_check_lenght(char **av)
// {
// 	int	i;
// 	int len;

// 	i = 1;
// 	while(av[i])
// 	{
// 		len = ft_strlen(av[i]);
// 		if (!(len < 10
// 		|| (len == 10 && ft_strncmp(av[i], "2147483647", 10) <= 0)
// 		|| (len == 11 && ft_strncmp(av[i], "-2147483648", 11) <= 0)))
// 			ft_error();
// 		i++;
// 	}
// }
void ft_parsing(char **av)
{
	int	i;
	int	j;
	int	tmp;

	i = 1;
	//ft_check_lenght(av);
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