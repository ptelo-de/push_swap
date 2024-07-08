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

//goes through an auxiiar head_a and returns 0 if stack is not sorted
int	order_check_a(t_store *data)
{
	int		i;
	t_stack *current;

	i = 0;
	current = data->head_a;
	while (current->next)
	{
		if (current->value >= current->next->value)
			return (0);
		current = current->next;
		i++;
	}
	return (1);
}
//goes through an auxiiar head_b and returns 1 if stack is not sorted
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
//sorts head a in ascending order, 
//only woks for stack a with 4 elements
void ft_sort_4(t_store *s)
{
    int sec;
    int thi;
    int fou;

    sec = s->head_a->next->value;
    thi = s->tail_a->prev->value;
    fou = s->tail_a->value;
	if (sec < s->head_a->value && sec < thi && sec < fou)
		ft_ra(s);  
	else if (thi < s->head_a->value && thi < sec && thi< fou)
        {
		    ft_rra(s);
            ft_rra(s);
        }
	else if (fou < s->head_a->value && fou < sec && fou < thi)
		ft_rra(s);
	ft_pb(s);
	ft_sort_3(s, 'a', 0);
	ft_pa(s);
}

//sorts head a in ascending order, 
//only woks for stack a with 4 elements
void ft_sort_5(t_store *s)
{
    int	sec;
	int	thi;
	int	fou;
	int	fif;

	sec = s->head_a->next->value;
	thi = s->head_a->next->next->value;
	fou = s->tail_a->prev->value;
	fif = s->tail_a->value;
	if ((sec < s->head_a->value) && (sec < thi) && (sec < fou) && (sec < fif))
	{ft_ra(s);
	}//linha onde segfault
	else if ((thi < s->head_a->value) && (thi < sec) && (thi < fou) && (thi < fif))
	{
		ft_ra(s);
		ft_ra(s);
	}
	else if ((fou < s->head_a->value) && (fou < sec) && (fou < thi) && (fou < fif))
	{
        ft_rra(s);
        ft_rra(s);
    }
	else if ((fif < s->head_a->value) && (fif < sec) && (fif < thi) && (fif < fou))
		ft_rra(s);
	ft_pb(s);
	ft_sort_4(s);
	ft_pa(s);
}