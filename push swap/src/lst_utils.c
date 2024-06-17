/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptelo-de <ptelo-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:42:40 by ptelo-de          #+#    #+#             */
/*   Updated: 2024/06/17 01:33:15 by ptelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
}
// void	ft_lstadd_front(t_stack **lst, t_stack *new)
// {
// 	if (!lst || !new)
// 		return ;
// 	new->next = *lst;
// 	*lst = new;
// }

void	ft_free_stack(t_stack **lst)
{
	t_stack	*aux;

	while (*lst)
	{
		aux = (*lst)->next;
		free(*lst);
		*lst = aux;
	}
	lst = NULL;
}
void	ft_delonenode(t_stack *lst, void (*del)(void *))
{
	del(lst->value);
	free(lst);
}
t_stack	*ft_lastnode(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
t_stack	*ft_newnode(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return (node);
}