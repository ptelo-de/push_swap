/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptelo-de <ptelo-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:42:40 by ptelo-de          #+#    #+#             */
/*   Updated: 2024/06/22 22:52:55 by ptelo-de         ###   ########.fr       */
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
int	ft_stacksize(t_stack *lst)
{
	t_stack	*temp;
	int		counter;

	if (!lst)
		return (0);
	counter = 1;
	temp = lst->next;
	while (temp)
	{
		counter++;
		temp = temp->next;
	}
	return(counter);
}

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
