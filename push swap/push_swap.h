/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptelo-de <ptelo-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 14:51:47 by ptelo-de          #+#    #+#             */
/*   Updated: 2024/06/22 23:48:09 by ptelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				bff_index;
	int				cost;
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stack;

// structure with two stacks, head and tail
typedef struct s_store
{
	t_stack	*head_a;
	t_stack	*head_b;
	t_stack	*tail_a;
	t_stack	*tail_b;
}				t_store;

#endif
// parsing
void	ft_error(void);
void	ft_check_lenght(char **av);
int	ft_atoi2(const char *nptr);
void ft_parsing(char **av);

//init stack
t_stack	*ft_init_stack_a(int stack_len, char **av);
void	ft_lstparsing(t_stack *node);
void	ft_del(int value);

//list utils
t_stack	*ft_newnode(int value);
void	ft_add_back_node(t_stack **lst, t_stack *new);
t_stack	*ft_lastnode(t_stack *lst);
//void	ft_add_front_node(t_stack *lst, t_stack *new);
int	ft_stacksize(t_stack *lst);
void	ft_free_stack(t_stack *lst);

//t_store utils
t_store	*ft_init_store(int ac, char **av);

//operations
void	ft_pb(t_store *s);
void	ft_pa(t_store *s);
void	ft_swap(t_store *s, char a, char b);
void ft_ra(t_store *s);
void ft_rb(t_store *s);
void ft_rra(t_store *s);
void ft_rrb(t_store *s);
//sort 3
void ft_sort_3(t_store *s, char a, char b);

//sort_4
void ft_sort_4(t_store *s);
void ft_sort_5(t_store *s);

//bff
int ft_average(t_store *s);
void    ft_setindex(t_store *s);
void    ft_algorithm(t_store *s);
void    ft_setbf(t_store *s);
void ft_setcost(t_store *s);
int ft_choosebest(t_store *s);

//big_sort
void	ft_rot_a(t_store *s, int bff_index);
void	ft_rot_b(t_store *s, int index);
void	ft_sort_top(t_store *s);
t_stack *ft_nodebyindex(int i, t_stack *tmpa);
void ft_cleancost(t_store *s);

//extra 
void ft_print_(t_store *store);
int	order_check_a(t_store *data);
int	order_check_b(t_store *data);
//not mine
void	final_rot(t_store *s);
void	rot_last(t_store *s, int index);