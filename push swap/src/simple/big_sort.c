/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                          :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: ptelo-de <ptelo-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:13:57 by ptelo-de          #+#    #+#             */
/*   Updated: 2024/07/02 21:03:36 by ptelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ft_rot_a(t_store *s, int bff_index)
{
	int	lsize;
	int	i;
	int	j;

	lsize = ft_stacksize(s->head_a);
	i = lsize - bff_index;
	j = bff_index;
	if (i < j)
	{
		while (i > 0)
		{
			ft_rra(s);
			i--;
		}
	}
	else
	{
		while (j >= 0)
		{
			ft_ra(s);
			j--;
		}
	}
}

void	ft_rot_b(t_store *s, int index)
{
	int	lsize;
	int	i;
	int	j;

	lsize = ft_stacksize(s->head_a);
	i = lsize - index;
	j = index;
	if (i < j)
	{
		while (i > 0)
		{
			ft_rrb(s);
			i--;
		}
	}
	else
	{
		while (j >= 0)
		{
			ft_rb(s);
			j--;
		}
	}
}

void	ft_sort_top(t_store *s)
{
	t_stack	*tmp;

	tmp = ft_nodebyindex(ft_choosebest(s), s->head_b);

	ft_rot_a(s, tmp->bff_index);
	ft_rot_b(s, tmp->index);
	ft_pa(s);
}

t_stack *ft_nodebyindex(int i, t_stack *tmpa)
{
    t_stack *tmp;

    tmp = tmpa;
    while (tmp)
    {
        if (tmp->index == i)
            return (tmp);
        tmp = tmp->next;
    }
    return (NULL);
}