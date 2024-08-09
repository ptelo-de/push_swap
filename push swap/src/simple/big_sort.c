/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptelo-de <ptelo-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:13:57 by ptelo-de          #+#    #+#             */
/*   Updated: 2024/08/09 17:12:45 by ptelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

// puts bff of the chosen element of stack b on top of stack a
void	ft_rot_a(t_store *s, int bff_index)
{
	int	lsize;

	lsize = ft_stacksize(s->head_a);
	while (s->head_a->index != bff_index)
	{
		if (bff_index <= lsize / 2)
			ft_ra(s);
		else
			ft_rra(s);
	}
}
// makes so that the chosen element of atack b is on top of stack b

void	ft_rot_b(t_store *s, int index)
{
	int	lsize;

	lsize = ft_stacksize(s->head_b);
	while (s->head_b->index != index)
	{
		if (index <= lsize / 2)
			ft_rb(s);
		else
			ft_rrb(s);
	}
}
// calculates the cheapest value and cals rot funtions, to prepare stacks for pa

void	ft_sort_top(t_store *s)
{
	t_stack	*tmp;

	tmp = ft_nodebyindex(ft_choosebest(s), s->head_b);
	ft_rot_a(s, tmp->bff_index);
	ft_rot_b(s, tmp->index);
	ft_pa(s);
}

t_stack	*ft_nodebyindex(int i, t_stack *tmpa)
{
	t_stack	*tmp;

	tmp = tmpa;
	while (tmp)
	{
		if (tmp->index == i)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

// finds index of the element with smallets value and sends it to ft_rot_a
void	final_rot(t_store *s)
{
	t_stack	*tmp;
	int		min;
	int		min_index;

	min = INT_MAX;
	ft_setindex(s);
	tmp = s->head_a;
	while (tmp)
	{
		if (tmp->value < min)
		{
			min = tmp->value;
			min_index = tmp->index;
		}
		tmp = tmp->next;
	}
	ft_rot_a(s, min_index);
}
