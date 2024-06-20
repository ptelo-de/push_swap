/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptelo-de <ptelo-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:42:40 by ptelo-de          #+#    #+#             */
/*   Updated: 2024/06/19 22:12:31 by ptelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*ft_newnode(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	node->prev = NULL;
	node->index = 0;
	return (node);
}
void	ft_add_back_node(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = ft_lastnode(*lst);
	last->next = new;
	new->prev = last;
	new->index = last->index + 1;
}
t_stack	*ft_lastnode(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
// void	ft_add_front_node(t_stack *lst, t_stack *new)
// {
// 	if (!lst && !new)
// 		return ;
// 	if (!lst && new)
// 	{
// 		lst = new;
// 		return;
// 	}
// 	// new->next = lst;
// 	// lst = new;
// 	// lst->prev = new;
// 	// lst->index = 1;
	
// }

void	ft_free_stack(t_stack *lst)
{
	t_stack	*aux;

	while (lst)
	{
		aux = lst->next;
		free(lst);
		lst = aux;
	}
	lst = NULL;
}
