/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptelo-de <ptelo-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 20:41:20 by ptelo-de          #+#    #+#             */
/*   Updated: 2024/06/17 01:34:10 by ptelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

//creates a new stack a with 
//all the numbers interpreted from the argumenets
void	ft_lstparsing(t_stack *node)
{
	if(!node)
	{
		ft_free_stack(&node);
		ft_error();	
	}
	return;
}
void	ft_del(int value)
{
	free(value);
}
t_stack	*ft_init_stack(int stack_len, char **av)
{
	t_stack	*a;
	t_stack	*last_node;
	t_stack *tmp;
	int content;
	int	i;

	content = ft_atoi2(av[1]);
	a = ft_lstnew(content);
	tmp = a;
	//index atribute assemble
	i = 2;
	while (i< stack_len)
	{
		content = ft_atoi2(av[i]);
		last_node = ft_newnode(content);
		ft_lstparsing(last_node);	
		ft_add_back_node(&tmp, last_node);//falta tratar de leaks
		ft_lstparsing(ft_lstlast(tmp));
		tmp = last_node;
	//printf("%d\n",tmp->value);
		i++;
	}
	return(a);
}
