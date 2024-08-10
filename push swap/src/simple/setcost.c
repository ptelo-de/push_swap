/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setcost.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptelo-de <ptelo-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 16:45:50 by ptelo-de          #+#    #+#             */
/*   Updated: 2024/08/10 16:40:10 by ptelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

// set cost for only stack b. tested
void	ft_setcost(t_store *s)
{
	t_stack	*tmpb;
	int		a_size;
	int		b_size;

	tmpb = s->head_b;
	a_size = ft_stacksize(s->head_a);
	b_size = ft_stacksize(s->head_b);
	while (tmpb)
	{
		if (a_size - tmpb->bff_index < tmpb->bff_index)
			tmpb->cost += a_size - tmpb->bff_index - 1;
		else
			tmpb->cost += tmpb->bff_index;
		if (b_size - tmpb->index < tmpb->index)
			tmpb->cost += b_size - tmpb->index - 1;
		else
			tmpb->cost += tmpb->index;
		tmpb = tmpb->next;
	}
}
// this function chooses the index of stack b with lowest cost
// is failing when bff is the same but the cost of the chosen is btter,
//	is not qualifying swap move correctly

int	ft_choosebest(t_store *s)
{
	t_stack	*tmpb;
	int		bestcost;
	int		i;

	tmpb = s->head_b;
	i = tmpb->index;
	bestcost = tmpb->cost;
	while (tmpb)
	{
		if (bestcost > tmpb->cost)
		{
			bestcost = tmpb->cost;
			i = tmpb->index;
		}
		tmpb = tmpb->next;
	}
	return (i);
}

void	ft_cleancost(t_store *s)
{
	t_stack	*tmpb;

	tmpb = s->head_b;
	while (tmpb)
	{
		tmpb->cost = 0;
		tmpb = tmpb->next;
	}
}
