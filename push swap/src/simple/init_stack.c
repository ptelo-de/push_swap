/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptelo-de <ptelo-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 20:41:20 by ptelo-de          #+#    #+#             */
/*   Updated: 2024/06/09 16:42:59 by ptelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

//creates a new stack a with 
//all the numbers interpreted from the argumenets

t_stack	*ft_init_stack(int stack_len, char **av)
{
	t_stack	*a;
	t_stack	*last_node;
	t_stack *tmp;
	int *content;
	int	i;

	a = ft_calloc(1, sizeof(t_stack));
	if(!a)
		return (NULL);
	
	// 	int			nbr;
	// int			index;
	// struct s_stack	*next;
	// struct s_stack	*prev;
	content = ft_atoi2(av[1]);
	a = ft_lstnew(content);
	tmp = a;
	//index atribute assemble
	i = 2;
	while (i< stack_len)
	{
		content = ft_atoi2(av[i]);
		last_node = ft_lstnew(content);
		ft_lstadd_back(&tmp, last_node);//falta tratar de leaks
		tmp = last_node;
		i++;
	}
	return(a);
}