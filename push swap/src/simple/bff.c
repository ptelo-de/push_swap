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
#include <limits.h>

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
        diff = LLONG_MAX;
        tmpb->bff_index = tmpa->index;
        tmpa->bff_index = tmpb->index;//atention : it gets always the last index od stack b 
        while (tmpa)
        {
            if ((diff > ((long long)tmpa->value - num))  && tmpa->value > num)
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
    ft_sort_5(s);
     //1 is passing when it should not, need to sort stack b
    while(s->head_b)
    {
    ft_setindex(s);
    ft_setbf(s);
    ft_setcost(s);
    ft_sort_top(s);
    ft_cleancost(s);
    }
    final_rot(s);
}

//set cost for only stack b. tested
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
 // is failing when bff is the same but the cost of the chosen is btter, is not qualifying swap move correctly
 int ft_choosebest(t_store *s)
 {
    t_stack *tmpb;
    t_stack *node;
    int bestcost;
    int i;

    tmpb = s->head_b;
    i = tmpb->index;
    bestcost = tmpb->cost;

    while(tmpb)
    {
        if ( bestcost > tmpb->cost )
        {
            bestcost = tmpb->cost;
            i = tmpb->index;
        }
        //maybe put here condition to chose beter when bff is same

        tmpb = tmpb->next;
    }
    tmpb = s->head_b;
    while(tmpb)
    {
        node = ft_nodebyindex(i, s->head_b);
        if (tmpb->cost == bestcost &&  
        ft_nodebyindex(tmpb->bff_index, s->head_b)->value - tmpb->value < ft_nodebyindex(node->bff_index, s->head_b)->value - node->value)
        {
            i = tmpb->index;
        }
        tmpb = tmpb->next;
    }

    return(i);
 }