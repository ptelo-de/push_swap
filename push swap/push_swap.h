/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptelo-de <ptelo-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 14:51:47 by ptelo-de          #+#    #+#             */
/*   Updated: 2024/06/09 16:31:55 by ptelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
// circular double linked list
typedef struct s_stack
{
	int			content;
	int			index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

#endif
void	ft_error(void);
int	ft_atoi2(const char *nptr);
void ft_parsing(char **av);
t_stack	*ft_init_stack(int stack_len, char **av);