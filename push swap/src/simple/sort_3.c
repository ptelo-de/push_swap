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

//tested: sorting stack a in ascending order
void ft_sort_3(t_store *s, char a, char b)
{
    if (a == 'a')
    {
        while (s->head_a->value > s->tail_a->value)
            ft_rrotate(s, 'a', 0);
        if (s->head_a->value > s->head_a->next->value)
            ft_swap(s, a, 0);
    }
    if (b == 'b')//231  321
    {
        while (s->head_b->value < s->tail_b->value)
            ft_rb(s);
        if (s->head_b->value < s->head_b->next->value)
            ft_swap(s, 0, b);
    }
    return;
}