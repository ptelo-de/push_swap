/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bff.c                                               :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: ptelo-de <ptelo-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:13:57 by ptelo-de          #+#    #+#             */
/*   Updated: 2024/06/26 21:03:36 by ptelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

//tested
int ft_average(t_store *s)
{
    t_stack  *cpy;
    int sum;
    int l;

    cpy = s->head_a;
    sum = 0;
    l = ft_stacksize(cpy);
    while(cpy)
    {
        sum += cpy->value;
        cpy = cpy->next;
    }
    return (sum / l);
}
void    ft_setindex(t_store *s)
{
    t_stack *tmpa;
    t_stack *tmpb;
    int i;

    tmpa = s->head_a;
    tmpb = s->head_b;
    i = 0;

    while(tmpa)
    {
        tmpa->index = i++;
        tmpa = tmpa->next;
    }
    i = 0;
    while(tmpb)
    {
        tmpb->index = i++;
        tmpb = tmpb->next;
    }
}
void    ft_setbf(t_store *s)
{
    t_stack *tmpa;
    long long num;
    long long diff;

    tmpa = s->head_a;
    num = s->head_b->value;
    diff =  (long long)tmpa->value - num;
    s->head_b->bff_index = tmpa->index;
    tmpa->bff_index = s->head_b->index;
    if (tmpa->next)
        tmpa = tmpa->next;
    else
        return;
    while (tmpa)
    {
        if (diff > (long long)tmpa->value - num)
        {
            diff = (long long)tmpa->value - num;
            s->head_b->bff_index = tmpa->index;
            tmpa->bff_index = s->head_b->index;
        }
        tmpa = tmpa->next;
    }
}
void    ft_algorithm(t_store *s)
{
    while(ft_stacksize(s->head_a) > 5)
    {
        if(s->head_a->value < ft_average(s))
            ft_pb(s);
        else
            ft_ra(s);
    }
    ft_setindex(s);
    while(s->head_b)
    {
        ft_setbf(s);
        printf("bffheadb%d\n", s->head_b->bff_index);
        s->head_b = s->head_b->next;

    }

}