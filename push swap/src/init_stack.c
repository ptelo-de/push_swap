/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptelo-de <ptelo-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 20:41:20 by ptelo-de          #+#    #+#             */
/*   Updated: 2024/08/09 16:25:33 by ptelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// creates a new stack a with
// all the numbers interpreted from the argumenets
void	ft_lstparsing(t_stack *node)
{
	if (!node)
	{
		ft_free_stack(node);
		ft_error();
	}
	return ;
}

t_stack	*ft_init_stack_a(int stack_len, char **av)
{
	t_stack	*a;
	t_stack	*last_node;
	t_stack	*tmp;
	int		content;
	int		i;

	content = ft_atoi2(av[1], 0, 1);
	a = ft_newnode(content);
	tmp = a;
	i = 2;
	while (i < stack_len)
	{
		content = ft_atoi2(av[i], 0, 1);
		last_node = ft_newnode(content);
		ft_lstparsing(last_node);
		ft_add_back_node(&tmp, last_node);
		ft_lstparsing(ft_lastnode(tmp));
		tmp = last_node;
		i++;
	}
	return (a);
}

t_store	*ft_init_store(int ac, char **av)
{
	t_store	*s;

	s = ft_calloc(1, sizeof(t_store));
	if (!s)
		return (NULL);
	s->head_a = ft_init_stack_a(ac, av);
	s->head_b = NULL;
	s->tail_a = ft_lastnode(s->head_a);
	s->tail_b = NULL;
	return (s);
}
