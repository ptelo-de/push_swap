/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptelo-de <ptelo-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 23:44:39 by ptelo-de          #+#    #+#             */
/*   Updated: 2024/06/19 20:44:20 by ptelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
// - sa (swap a): Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.
// - sb (swap b): Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one or no elements.
t_stack *ft_swap(t_store *s, char a, char b)
{
	t_stack	*new_head;

	new_head = s->head_a->next;
	//new_head->prev = NULL;
	s->head_a->prev = new_head;
	printf("new head %d == head_a.prev %d\n", new_head->value, s->head_a->prev->value);
	s->head_a = new_head;
	printf("lalalal\n");
	printf("new head %d == head_a.prev %d\n", new_head->value, s->head_a->value);
	// a->next = a_next->next;
	// a_next->next = a;
	// a_next->prev = NULL;
	(void)a;(void)b;
	
	return(NULL);
}
void	ft_pb(t_store *s)
{
	t_stack *node;
	t_stack *head;

	node = ft_newnode(s->head_a->value);
	node->next = s->head_b;
	s->head_b = node;
	head = s->head_a->next;
	free(s->head_a);
	s->head_a = head;
	s->head_a->prev = NULL;

}
