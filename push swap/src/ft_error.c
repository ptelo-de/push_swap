/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptelo-de <ptelo-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:15:57 by ptelo-de          #+#    #+#             */
/*   Updated: 2024/06/07 16:26:05 by ptelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// prints error message and terminates 
// the program with a status code of 1, 
// indicating error.
void	ft_error(void)
{
	write (2, "Error\n", 6);
	exit(1);
}