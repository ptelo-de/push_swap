/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                            :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: ptelo-de <ptelo-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:13:57 by ptelo-de          #+#    #+#             */
/*   Updated: 2024/06/24 21:03:36 by ptelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

//goes throuh an auxiiar head_a and returns 1 if stack is not sorted
int	order_check_a(t_store *data)
{
	int		i;
	t_stack *current;

	i = 0;
	current = data->head_a;
	while (current->next)
	{
		if (current->value >= current->next->value)
			return (1);
		current = current->next;
		i++;
	}
	return (0);
}
int	order_check_b(t_store *data)
{
	int		i;
	t_stack *current;

	i = 0;
	current = data->head_b;
	while (current->next)
	{
		if (current->value <= current->next->value)
			return (1);
		current = current->next;
		i++;
	}
	return (0);
}
//tested: sorting stack a in ascending order and descending order (b)
//not protected for seg fault
void ft_sort_3(t_store *s, char a, char b)
{

    if (a == 'a')
    {
        if (s->head_a->value > s->head_a->next->value && s->head_a->value > s->tail_a->value)
		    ft_ra(s);
        if (s->head_a->next->value > s->tail_a->value)
            ft_rra(s);
        if (s->head_a->value > s->head_a->next->value)
            ft_swap(s, a, 0);

    }
    if (b == 'b')
    {
        if (s->head_b->value < s->head_b->next->value && s->head_b->value < s->tail_a->value)
		    ft_rb(s);
        if (s->head_b->next->value < s->tail_b->value)
            ft_rrb(s);
        if (s->head_b->value < s->head_b->next->value)
            ft_swap(s, 0, b);
    }
}
// void	sort_3(t_list **a)
// {
// 	if ((*a)->nbr > (*a)->next->nbr && (*a)->nbr > (*a)->next->next->nbr)
// 		ra(a);
// 	if ((*a)->next->nbr > (*a)->next->next->nbr)
// 		rra(a);
// 	if ((*a)->nbr > (*a)->next->nbr)
// 		sa(a);
// }
// void ft_sort_5(t_store *s, char a, char b)
// {

// }