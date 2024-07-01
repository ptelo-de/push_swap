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
//index start at 1 for add cost func
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
    t_stack *tmpb;
    long long num;
    long long diff;

    tmpb = s->head_b;
    while (tmpb)
    {
        tmpa = s->head_a;
        num = tmpb->value;
        diff =  (long long)tmpa->value - num;
        printf("dif: %lld\n", diff);
        tmpb->bff_index = tmpa->index;
        tmpa->bff_index = tmpb->index;//atention : it gets always the last index od stack b 
        if (tmpa->next)
            tmpa = tmpa->next;
        else
        {
            printf("lalalalallal\n");
            return;
        }
        
        while (tmpa)
        {
            if (diff > (long long)tmpa->value - num)
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
    ft_setbf(s);
    ft_setcost(s);
    ft_sort_top(s);
}

//tested
void ft_setcost(t_store *s)
{
    t_stack *tmpb;
    int a_size;
    int b_size;

    tmpb = s->head_b;
    a_size = ft_stacksize(s->head_a);
    b_size = ft_stacksize(s->head_b);
    while (tmpb)
    {
        if (a_size - tmpb->bff_index < tmpb->bff_index)
            tmpb->cost += a_size - tmpb->bff_index; 
        else
            tmpb->cost += tmpb->bff_index;
        if (b_size - tmpb->index < tmpb->index)
           tmpb->cost += b_size - tmpb->index;
        else
            tmpb->cost += tmpb->index;
        tmpb = tmpb->next;
    }
}
 // this function chooses the index of stack b with lowest cost
 int ft_choosebest(t_store *s)
 {
    t_stack *tmpb;
    int bestcost;
    int i;

    tmpb = s->head_b;
    bestcost = tmpb->cost;

    while(tmpb)
    {
        if ( bestcost > tmpb->cost )
        {
            bestcost = tmpb->cost;
            i = tmpb->index;
        }
        tmpb = tmpb->next;
    }
    return(i);
 }