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
		s->head_a->prev = s->head_a->next;
		s->head_a->prev->next = s->head_a;
		s->head_a->next = s->head_a->next->next;
		s->head_a->next->prev = s->head_a;
		ft_printf("sa\n");
		ft_print_newa(s);
		ft_print_reva(s);
		ft_print_newb(s);
		ft_print_revb(s);
		exit(0);
/*
		old_head = s->head_a;
		old_head->prev = s->head_a->next;
		old_head->next = s->head_a->next->next;
		s->head_a = old_head->prev;
		s->head_a->prev = NULL;
		s->head_a->next = old_head;
*/
	}
	if(b == 'b')
	{
		old_head = s->head_b;
		old_head->prev = s->head_b->next;
		old_head->next = s->head_b->next->next;
		s->head_b = old_head->prev;
		s->head_b->prev = NULL;
		s->head_b->next = old_head;
		ft_printf("sb\n");
	ft_print_newa(s);
	ft_print_reva(s);
	ft_print_newb(s);
	ft_print_revb(s);
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
	ft_printf("pb\n");
	ft_print_newa(s);
	ft_print_reva(s);
	ft_print_newb(s);
	ft_print_revb(s);

}
void ft_paux(t_store *s)
{
	ft_printf("estou no pa\n");
	s->head_a->prev = s->head_b;
	s->head_b  = s->head_b->next;
	ft_printf("heada %d headb NULL%d \n", s->head_a->value, s->head_b);
	ft_printf("heada.prev %d\n", s->head_a->prev->value);
	s->head_a->prev->next = s->head_a;
	s->head_a = s->head_a->prev;
	ft_printf("pa\n");

}
//tested for last node
void	ft_pa(t_store *s)
{
	if(!s->head_b->next)
	{
		ft_paux(s);
		return;
	}
	s->head_a->prev = s->head_b;
	s->head_b = s->head_b->next;
	ft_printf("heada %d headb %d \n", s->head_a->value, s->head_b->value);
	ft_printf("heada.prev %d headb.prev NULL%d \n", s->head_a->prev->value, s->head_b->prev);
	s->head_a->prev->next = s->head_a;
	ft_printf("heada %d headb %d \n", s->head_a->value, s->head_b->value);
	ft_printf("heada.prev %d headb.prev NULL%d \n", s->head_a->prev->value, s->head_b->prev);
	s->head_a = s->head_a->prev;
	ft_printf("heada %d headb %d \n", s->head_a->value, s->head_b->value);
	ft_printf("heada.prev NULL%d headb.prev NULL%d \n", s->head_a->prev, s->head_b->prev);
	s->head_b->prev = NULL;
ft_printf("heada %d headb %d \n", s->head_a->value, s->head_b->value);
	ft_printf("heada.prev NULL%d headb.prev NULL%d \n", s->head_a->prev, s->head_b->prev);
ft_printf("heada.next %d headbnext NULL%d \n", s->head_a->next->value, s->head_b->next);
	// s->head_a->prev = s->head_b;
	// s->head_a = s->head_a->prev;
	// ft_printf("estou no pa\n");
	// s->head_a->prev->next = s->head_a; //segfault 
	// ft_printf("estou no pa\n");
	// s->head_b =s->head_b->next;
	// s->head_b->prev = NULL;
	//exit(0);
	ft_printf("pa\n");
	ft_print_newa(s);
	ft_print_reva(s);
	ft_print_newb(s);
	ft_print_revb(s);
}
void ft_ra(t_store *s)
{
	s->head_a->prev = s->tail_a;
	s->tail_a->next = s->head_a;
	s->head_a = s->head_a->next;
	s->head_a->prev = NULL;
	s->tail_a = s->tail_a->next;
	s->tail_a->next = NULL;
	ft_printf("ra\n");
	ft_print_newa(s);
	ft_print_reva(s);
	ft_print_newb(s);
	ft_print_revb(s);
}
void ft_rb(t_store *s)
{
	//s->head_b->prev = s->tail_b;
	s->tail_b->next = s->head_b;
	s->head_b = s->head_b->next;
	s->head_b->prev = NULL;
	s->tail_b = s->tail_b->next;
	s->tail_b->next = NULL;
	ft_printf("rb\n");
	ft_print_newa(s);
	ft_print_reva(s);
	ft_print_newb(s);
	ft_print_revb(s);
}
void ft_rra(t_store *s)
{
	ft_printf("tail value: %d\n", s->tail_a->value);
	ft_printf("tail prev value: %d\n", s->tail_a->prev->value);
	s->head_a->prev = s->tail_a;
	s->head_a->prev->next = s->head_a;
	//s->tail_a->next = s->head_a;
	s->head_a = s->head_a->prev; 
	s->tail_a = s->tail_a->prev;
	s->tail_a->next = NULL; ///segfault
	ft_printf("estou no rra\n");
	s->head_a->prev = NULL;
	ft_printf("rra\n");
	ft_print_newa(s);
	ft_print_reva(s);
	ft_print_newb(s);
	ft_print_revb(s);
}
void ft_rrb(t_store *s)
{
	
	s->head_b->prev = s->tail_b;
	s->tail_b->next = s->head_b;
	s->head_b = s->head_b->prev; 
	s->tail_b = s->tail_b->prev;
	s->tail_b->next = NULL;
	s->head_b->prev = NULL;
	ft_printf("rrb\n");
	ft_print_newa(s);
	ft_print_reva(s);
	ft_print_newb(s);
	ft_print_revb(s);
}
