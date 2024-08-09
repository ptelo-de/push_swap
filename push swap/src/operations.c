/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptelo-de <ptelo-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 23:44:39 by ptelo-de          #+#    #+#             */
/*   Updated: 2024/08/09 16:33:23 by ptelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// ft_print_newa(s);
// ft_print_reva(s);
// ft_print_newb(s);
// ft_print_revb(s);
// - sa (swap a): Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.
// - sb (swap b): Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one or no elements.
// decided to not protect when stack has only one node
void	ft_swap(t_store *s)
{
	t_stack	*old_head;

	old_head = s->head_a;
	s->head_a = s->head_a->next;
	old_head->next = s->head_a->next;
	s->head_a->next = old_head;
	if (s->head_a->next->next)
	{
		s->head_a->next->next->prev = s->head_a->next;
		s->head_a->next->prev = s->head_a;
	}
	else
	{
		s->head_a->next->prev = s->head_a;
		s->tail_a = s->head_a->next;
	}
	s->head_a->prev = NULL;
	ft_printf("sa\n");
}
// Push top stack a to top stack b
// tested for last node printing with next and  with prev

void	ft_pb(t_store *s)
{
	if (s->head_b && s->head_a)
	{
		s->head_b->prev = s->head_a;
		s->head_a = s->head_a->next;
		if (s->head_a)
			s->head_a->prev = NULL;
		else
			s->tail_a = NULL;
		s->head_b->prev->next = s->head_b;
		s->head_b = s->head_b->prev;
	}
	else if (s->head_a)
	{
		s->head_b = s->head_a;
		s->head_a = s->head_a->next;
		s->head_a->prev = NULL;
		s->head_b->next = NULL;
		s->tail_b = s->head_b;
	}
	ft_printf("pb\n");
}

void	ft_paux(t_store *s)
{
	s->head_a->prev = s->head_b;
	s->head_b = s->head_b->next;
	s->head_a->prev->next = s->head_a;
	s->head_a = s->head_a->prev;
	s->tail_b = NULL;
	ft_printf("pa\n");
}
// tested for last node

void	ft_pa(t_store *s)
{
	if (!s->head_b->next)
	{
		ft_paux(s);
		return ;
	}
	s->head_a->prev = s->head_b;
	s->head_b = s->head_b->next;
	s->head_a->prev->next = s->head_a;
	s->head_a = s->head_a->prev;
	s->head_b->prev = NULL;
	ft_printf("pa\n");
}
