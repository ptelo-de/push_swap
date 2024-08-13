/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptelo-de <ptelo-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:15:57 by ptelo-de          #+#    #+#             */
/*   Updated: 2024/08/13 12:32:38 by ptelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// prints error message and terminates
// the program with a status code of 1,
// indicating error.
void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
// does not lose tail or head

void	ft_ra(t_store *s)
{
	s->head_a->prev = s->tail_a;
	s->tail_a->next = s->head_a;
	s->head_a = s->head_a->next;
	s->head_a->prev = NULL;
	s->tail_a = s->tail_a->next;
	s->tail_a->next = NULL;
	ft_printf("ra\n");
}
// does not lose tail or head

void	ft_rb(t_store *s)
{
	s->head_b->prev = s->tail_b;
	s->tail_b->next = s->head_b;
	s->head_b = s->head_b->next;
	s->head_b->prev = NULL;
	s->tail_b = s->tail_b->next;
	s->tail_b->next = NULL;
	ft_printf("rb\n");
}
// does no lose tail or head

void	ft_rra(t_store *s)
{
	s->head_a->prev = s->tail_a;
	s->head_a->prev->next = s->head_a;
	s->head_a = s->head_a->prev;
	s->tail_a = s->tail_a->prev;
	s->tail_a->next = NULL;
	s->head_a->prev = NULL;
	ft_printf("rra\n");
}
// does not lose head or tail

void	ft_rrb(t_store *s)
{
	s->head_b->prev = s->tail_b;
	s->tail_b->next = s->head_b;
	s->head_b = s->head_b->prev;
	s->tail_b = s->tail_b->prev;
	s->tail_b->next = NULL;
	s->head_b->prev = NULL;
	ft_printf("rrb\n");
}
