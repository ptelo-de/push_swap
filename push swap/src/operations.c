/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptelo-de <ptelo-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 23:44:39 by ptelo-de          #+#    #+#             */
/*   Updated: 2024/06/23 00:54:35 by ptelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// - sa (swap a): Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.
// - sb (swap b): Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one or no elements.

//decided to not protect when stack has only one node
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
//Push top stack a to top stack b
//tested for last node printing with next and  with prev
//does not seg fault when called with stack a null
void	ft_pb(t_store *s)
{
	if(s->head_b  && s->head_a)
	{
		s->head_b->prev = s->head_a;
		s->head_a = s->head_a->next;
		if(s->head_a)
			s->head_a->prev = NULL;
		else
			s->tail_a = NULL;
		s->head_b->prev->next = s->head_b;
		s->head_b = s->head_b->prev;

	}
	else if (s->head_a)
	{
		s->head_b = s->head_a;
		s->head_a = s->head_a->next,
		s->head_a->prev = NULL;
		s->head_b->next = NULL;
		s->tail_b = s->head_b;
	}

}
//tested for last node
void	ft_pa(t_store *s)
{
	t_stack *node;

	node = ft_newnode(s->head_b->value);
	node->next = s->head_a;
	s->head_a = node;
	if(s->head_b->next)
	{
		s->head_b = s->head_b->next;
		free(s->head_b->prev);
		s->head_b->prev = NULL;
	}
	else
	{
		free(s->head_b);
		s->head_b = NULL;
	}

}
void ft_ra(t_store *s)
{
	//s->head_a->prev = s->tail_a;
	s->tail_a->next = s->head_a;
	s->head_a = s->head_a->next;
	//s->head_a->prev = NULL;
	s->tail_a = s->tail_a->next;
	s->tail_a->next = NULL;
}
void ft_rb(t_store *s)
{
	//s->head_b->prev = s->tail_b;
	s->tail_b->next = s->head_b;
	s->head_b = s->head_b->next;
	//s->head_b->prev = NULL;
	s->tail_b = s->tail_b->next;
	s->tail_b->next = NULL;
}
void ft_rrotate(t_store *s, char a, char b)
{
	
	s->head_a->prev = s->tail_a;
	s->tail_a->next = s->head_a;
	s->head_a = s->head_a->prev; 
	s->tail_a = s->tail_a->prev;
	s->tail_a->next = NULL;
	s->head_a->prev = NULL;
	(void)a;(void)b;
}
