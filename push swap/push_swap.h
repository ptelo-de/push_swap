/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptelo-de <ptelo-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 14:51:47 by ptelo-de          #+#    #+#             */
/*   Updated: 2024/06/17 01:34:29 by ptelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
// circular double linked list
// typedef struct s_stack
// {
// 	int			content;
// 	int			index;
// 	struct s_stack	*next;
// 	struct s_stack	*prev;
// }	t_stack;

typedef struct s_stack
{
	int				value;
	int				index;
	int				flag;
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stack;

// structure with all the data
typedef struct s_store
{
	int		count_a;
	int		count_b;
	int		chunk_size;
	int		chunk_num;
	int		biggest;
	int		snd_biggest;
	int		smallest;
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*tail_a;
	t_stack	*tail_b;
}				t_store;

#endif
// parsing
void	ft_error(void);
int	ft_atoi2(const char *nptr);
void ft_parsing(char **av);

//init stack
t_stack	*ft_init_stack(int stack_len, char **av);
void	ft_lstparsing(t_stack *node);
void	ft_del(int value);

//list utils
t_stack	*ft_newnode(int value);
t_stack	*ft_lastnode(t_stack *lst);
void	ft_delonenode(t_stack *lst, void (*del)(void *));
void	ft_free_stack(t_stack **lst);
void	ft_add_back_node(t_stack **lst, t_stack *new);