/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptelo-de <ptelo-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:13:57 by ptelo-de          #+#    #+#             */
/*   Updated: 2024/08/10 21:24:47 by ptelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"
#include <limits.h>

// tested
int	ft_average(t_stack *stack)
{
	t_stack	*cpy;
	int		sum;
	int		l;

	cpy = stack;
	sum = 0;
	l = ft_stacksize(cpy);
	while (cpy)
	{
		sum += cpy->value;
		cpy = cpy->next;
	}
	return (sum / l);
}
// index start at 1 for add cost func

void	ft_setindex(t_store *s)
{
	t_stack	*tmpa;
	t_stack	*tmpb;
	int		i;

	tmpa = s->head_a;
	tmpb = s->head_b;
	i = 0;
	while (tmpa)
	{
		tmpa->index = i++;
		tmpa = tmpa->next;
	}
	i = 0;
	while (tmpb)
	{
		tmpb->index = i++;
		tmpb->cost = 0;
		tmpb = tmpb->next;
	}
}

void	ft_setbf(t_store *s)
{
	t_stack		*tmpa;
	t_stack		*tmpb;
	long long	num;
	long long	diff;

	tmpb = s->head_b;
	while (tmpb)
	{
		tmpa = s->head_a;
		num = tmpb->value;
		diff = LLONG_MAX;
		tmpb->bff_index = tmpa->index;
		tmpa->bff_index = tmpb->index;
		while (tmpa)
		{
			if ((diff > ((long long)tmpa->value - num)) && tmpa->value > num)
			{
				diff = (long long)tmpa->value - num;
				tmpb->bff_index = tmpa->index;
				tmpa->bff_index = tmpb->index;
			}
			tmpa = tmpa->next;
		}
		tmpb = tmpb->next;
	}
}

void	ft_algorithm(t_store *s)
{
	while (ft_stacksize(s->head_a) > 5)
	{
		if (s->head_a->value < ft_average(s->head_a))
		{
			ft_pb(s);
			if (s->head_b->value < ft_average(s->head_b))
				ft_rb(s);
		}
		else
			ft_ra(s);
	}
	ft_sort_5(s, s->head_a->next->value, s->head_a->next->next->value);
	while (s->head_b)
	{
		ft_setindex(s);
		ft_setbf(s);
		ft_setcost(s);
		ft_sort_top(s);
		ft_cleancost(s);
	}
	final_rot(s);
}
