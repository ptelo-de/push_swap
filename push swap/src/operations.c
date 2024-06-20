/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptelo-de <ptelo-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 23:44:39 by ptelo-de          #+#    #+#             */
/*   Updated: 2024/06/19 23:02:00 by ptelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// - sa (swap a): Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.
// - sb (swap b): Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one or no elements.
void ft_swap(t_store *s, char a, char b)
{
	t_stack	*old_head;
	if(a == 'a')
	{
		old_head = s->head_a;
		old_head->prev = s->head_a->next;
		old_head->next = s->head_a->next->next;
		s->head_a = old_head->prev;
		s->head_a->prev = NULL;
		s->head_a->next = old_head;
	}
	if(b == 'b')
	{
		old_head = s->head_b;
		old_head->prev = s->head_b->next;
		old_head->next = s->head_b->next->next;
		s->head_b = old_head->prev;
		s->head_b->prev = NULL;
		s->head_b->next = old_head;
	}
	
	return ;
}

void	ft_pb(t_store *s)
{
	t_stack *node;

	node = ft_newnode(s->head_a->value);
	node->next = s->head_b;
	s->head_b = node;
	s->head_a = s->head_a->next;
	free(s->head_a->prev);
	s->head_a->prev = NULL;
}
