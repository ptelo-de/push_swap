/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptelo-de <ptelo-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 23:44:39 by ptelo-de          #+#    #+#             */
/*   Updated: 2024/06/19 16:28:00 by ptelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
// - sa (swap a): Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.
// - sb (swap b): Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one or no elements.
t_stack *ft_swap(t_stack *a)
{
	t_stack	*a_next;

	a_next = a->next;
	a->prev = a_next;
	a->next = a_next->next;
	a->index = 1;
	a_next->index = 0;
	a_next->next = a;
	a_next->prev = NULL;
	
	return(a_next);
}
void	ft_pb(t_store *s)
{
	t_stack *tmp = s->head_a;
	//t_stack	*old_head_a;

	ft_add_front_node(&s->head_b, &tmp);
	//old_head_a = s->head_a;
	//s->head_a->next->prev = NULL;
	s->head_a = s->head_a->next;
	//free(old_head_a);
}