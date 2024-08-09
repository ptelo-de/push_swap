# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ptelo-de <ptelo-de@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/07 12:00:07 by ptelo-de          #+#    #+#              #
#    Updated: 2024/08/09 16:47:03 by ptelo-de         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap

SRC = src/main.c src/ft_error.c src/atoi2.c src/ft_parsing.c src/init_stack.c src/lst_utils.c \
src/operations.c  src/simple/sort_3.c src/simple/bff.c src/simple/big_sort.c src/simple/setcost.c
OBJ = $(SRC:.c=.o)

CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

 all: $(NAME)

.c.o:
	${CC} -Wall -Wextra -Werror -c -g $< -o ${<:.c=.o}

# %.o: %.c
#	$(CC) $(CFLAGS) -c $< -o $@
 
$(NAME): $(OBJ)
	make bonus -C libft/
	${CC} ${CFLAGS} ${OBJ} -o ${NAME} -L ./libft -lft
 
clean:
	$(RM) $(OBJ)
	cd libft/ && $(MAKE) clean
 
fclean: clean
	$(RM) $(NAME)
	cd libft/ && $(MAKE) fclean

re: fclean all

.PHONY: all clean fclean re