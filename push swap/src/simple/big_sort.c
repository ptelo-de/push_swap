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

//puts bff of the chosen element of stack b on top of stack a
void	ft_rot_a(t_store *s, int bff_index)
{
	int	lsize;

	lsize = ft_stacksize(s->head_a);
	ft_printf("calculei o lsize no rota\n");
	if (s->head_a->index != bff_index)
	{
		if(bff_index <= lsize/2)
			ft_ra(s);
		else
			ft_rra(s);
	}
}
//makes so that the chosen element of atack b is on top of stack b
void	ft_rot_b(t_store *s, int index)
{
	int	lsize;

	lsize = ft_stacksize(s->head_b);

	if (s->head_b->index != index)
	{
		if(index <= lsize/2)
			ft_rb(s);
		else
			ft_rrb(s);
	}

}

void	ft_sort_top(t_store *s)
{
	t_stack	*tmp;

	tmp = ft_nodebyindex(ft_choosebest(s), s->head_b);
	ft_printf("temp form sort top: %d\n", tmp->value);
	ft_rot_a(s, tmp->bff_index);
	ft_printf("sai do rota\n");
	ft_rot_b(s, tmp->index);
	//ft_print_(s);
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
void ft_cleancost(t_store *s)
{
	t_stack *tmpb;

	tmpb = s->head_b;
	while(tmpb)
	{
		tmpb->cost = 0;
		tmpb = tmpb->next;
	}
}
//not mine
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
		if(tmp->value < min)
		{
			min = tmp->value;
			min_index = tmp->index;
		}
		tmp = tmp->next;
	}
	rot_last(s, min_index);
}
//not mine
void	rot_last(t_store *s, int index)
{
	int	lsize;
	int	i;
	int	j;

	lsize = ft_stacksize(s->head_a);
	i = lsize - index - 1;
	j = index;
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
		while (j > 0)
		{
			ft_ra(s);
			j--;
		}
	}
}