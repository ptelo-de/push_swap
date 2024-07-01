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

void ft_print_rev(t_store *s)
{
	while (s->tail_a)
	{
		printf("stackarev: %d\n", s->tail_a->value);
		s->tail_a = s->tail_a->prev;
	}
		while (s->tail_b)
	{
		printf("stackbrev: %d\n", s->tail_b->value);
		s->tail_b = s->tail_b->prev;
	}
}
// void ft_print_(t_store *store)
// {
// 	while (store->head_a)
// 	{
// 		printf("stack a:value : %d\n", store->head_a->value);
// 		store->head_a = store->head_a->next;
// 	}
// 		while (store->head_b)
// 	{
// 		printf("stack b:value : %d\n",store->head_b->value);
// 		store->head_b = store->head_b->next;
// 	}
// }
void ft_print_(t_store *store)
{
	while (store->head_a)
	{
		printf("stack a: index: %d bff: %d value : %d\n",store->head_a->index, store->head_a->bff_index, store->head_a->value);
		store->head_a = store->head_a->next;
	}
		while (store->head_b)
	{
		printf("stack b: index : %d bff: %d cost: %d value : %d\n",store->head_b->index, store->head_b->bff_index,store->head_b->cost, store->head_b->value);
		store->head_b = store->head_b->next;
	}
}
int	main(int ac, char **av)
{
	t_stack *free_a;
	t_stack *free_b;
	t_store	*store;
	//t_store *paux;

	if (ac == 1)
		exit(1);
	if (ac == 2 && !av[1][0]) // protects only for ""
		ft_error();
	ft_parsing(av);
	store = ft_init_store(ac, av);
	ft_algorithm(store);
	free_a = store->head_a;
	free_b = store->head_b;
	ft_print_(store);
	
	ft_free_stack(free_a);
	ft_free_stack(free_b);
	free(store);
}
//  ./push_swap "1 2 3 4" "2 3 45" , invalid 
//  ./push_swap 1 2 3 4, valid, list of integers? 
// no because sizeof(av[1]) == 8 bytes, it is an array of strings
// ARG="1 2 3 4", valid and counting 4 , echo $ARG
// arguments to the stack passed as bash variable
