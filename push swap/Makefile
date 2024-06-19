# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ptelo-de <ptelo-de@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/07 12:00:07 by ptelo-de          #+#    #+#              #
#    Updated: 2024/06/19 15:54:17 by ptelo-de         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap

SRC = src/main.c src/ft_error.c src/atoi2.c src/ft_parsing.c src/simple/init_stack.c src/lst_utils.c \
	src/operations.c
OBJ = $(SRC:.c=.o)

CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

 all: $(NAME)

.c.o:
	${CC} -Wall -Wextra -Werror -c $< -o ${<:.c=.o}

# %.o: %.c
#	$(CC) $(CFLAGS) -c $< -o $@
 
$(NAME): $(OBJ)
	make bonus -C libft/
	${CC} ${FLAGS} ${OBJ} -o ${NAME} -L ./libft -lft
 
clean:
	$(RM) $(OBJ)
	cd libft/ && $(MAKE) clean
 
fclean: clean
	$(RM) $(NAME)
	cd libft/ && $(MAKE) fclean

re: fclean all

.PHONY: all clean fclean re