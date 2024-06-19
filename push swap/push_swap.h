/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptelo-de <ptelo-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 14:51:47 by ptelo-de          #+#    #+#             */
/*   Updated: 2024/06/19 16:25:19 by ptelo-de         ###   ########.fr       */
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
//	int				flag;
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stack;

// structure with all the data
typedef struct s_store
{
	//int		count_a;
	//int		count_b;
	//int		chunk_size;
	//int		chunk_num;
	//int		biggest;
	//int		snd_biggest;
	//int		smallest;
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
void	ft_add_front_node(t_stack **lst, t_stack *new);
void	ft_free_stack(t_stack **lst);

//t_store utils
t_store	*ft_init_store(int ac, char **av);

//operations
void	ft_pb(t_store *s);