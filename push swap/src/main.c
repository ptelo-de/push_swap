/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptelo-de <ptelo-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 14:30:06 by ptelo-de          #+#    #+#             */
/*   Updated: 2024/06/23 00:52:57 by ptelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "stdio.h"

void ft_print_reva(t_store *s)
{
	t_stack *tmpa = s->tail_a;
    ft_printf("LISTA A TAIL:");
	tmpa = s->tail_a;
    if (tmpa == NULL)
    {
        ft_printf("A lista A está vazia.\n");
        return;
    }
	if (tmpa->next == NULL)
		ft_printf("NULL0 ");
	while (tmpa)
	{
		ft_printf("%d ", tmpa->value);
		tmpa = tmpa->prev;
	}
	if (s->head_a && s->head_a->prev == NULL)
        ft_printf("NULL1\n");
	
}

void ft_print_revb(t_store *s)
{
	t_stack *tmpb = s->tail_b;
    ft_printf("LISTA B TAIL:");
	tmpb = s->tail_b;
    if (tmpb == NULL)
    {
        ft_printf("A lista B está vazia.\n");
        return;
    }
	if (tmpb->next == NULL)
		ft_printf("NULL0 ");
	while (tmpb)
	{
		ft_printf("%d ", tmpb->value);
		tmpb = tmpb->prev;
	}
	if (s->head_b && s->head_b->prev == NULL)
        ft_printf("NULL1\n");
	
}
void ft_print_newa(t_store *s)
{
	t_stack *tmpa = s->head_a;
    ft_printf("LISTA A HEAD:");
	tmpa = s->head_a;
    if (tmpa == NULL)
    {
        ft_printf("A lista A está vazia.\n");
        return;
    }
	if (tmpa->prev == NULL)
		ft_printf("NULL0 ");
	while (tmpa)
	{
		ft_printf("%d ", tmpa->value);
		tmpa = tmpa->next;
	}
	if (s->tail_a && s->tail_a->next == NULL)
        ft_printf("NULL1\n");
}
void ft_print_newb(t_store *s)
{
	t_stack *tmpb = s->head_b;
    ft_printf("LISTA B HEAD:");
	tmpb = s->head_b;
    if (tmpb == NULL)
    {
        ft_printf("A lista B está vazia.\n");
        return;
    }
	if (tmpb->prev == NULL)
		ft_printf("NULL0 ");
	while (tmpb)
	{
		ft_printf("%d ", tmpb->value);
		tmpb = tmpb->next;
	}
	if (s->tail_b && s->tail_b->next == NULL)
        ft_printf("NULL1\n");
}

void ft_print_(t_store *store)
{
	t_stack *tmpa;
	t_stack *tmpb;

	tmpa = store->head_a;
	tmpb = store->head_b;
	ft_printf("\n");	
	while (tmpa)
	{
		ft_printf("stack a: index: %d bff: %d value : %d\n",tmpa->index, tmpa->bff_index, tmpa->value);
		tmpa = tmpa->next;
	}
		while (tmpb)
	{
		ft_printf("stack b: index : %d bff: %d cost: %d value : %d\n",tmpb->index, tmpb->bff_index,tmpb->cost, tmpb->value);
		tmpb = tmpb->next;
	}
}
void ft_transfertosort(t_store *s)
{
	int stacksize;

	stacksize = ft_stacksize(s->head_a);
	if (stacksize == 1 || order_check_a(s))
		return;
	else if(stacksize == 2)
	{
		if (s->tail_a->value > s->head_a->value)
			return;
		else
			ft_swap(s, 'a', 0);
	}
	else if (stacksize == 3)
		ft_sort_3(s, 'a', 0);
	else if (stacksize == 4)
		ft_sort_4(s);
	else
		ft_algorithm(s);

}
int	main(int ac, char **av)
{
	t_stack *free_a;
	t_stack *free_b;
	t_store	*store;

	if (ac == 1)
		exit(1);
	if (ac == 2 && !av[1][0]) // protects only for ""
		ft_error();
	ft_parsing(av);
	store = ft_init_store(ac, av);
	ft_transfertosort(store);
	free_a = store->head_a;
	free_b = store->head_b;
	ft_print_(store);
	ft_free_stack(free_a);
	ft_free_stack(free_b);
	free(store);
}
// ./push_swap "1 2 3 4" "2 3 45" , invalid 
//  ./push_swap 1 2 3 4, valid, list of integers? 
// no because sizeof(av[1]) == 8 bytes, it is an array of strings
// ARG="1 2 3 4", valid and counting 4 , echo $ARG
// arguments to the stack passed as bash variable
// stack : 5 6 10 2 9 3 1 7 8 4
//stack d3333 : 6 52 10 3 2 7 5 4 21 1
//./push_swap 1 -222222 -444 -5 1222255 66 777