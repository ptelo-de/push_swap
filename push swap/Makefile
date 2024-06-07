# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ptelo-de <ptelo-de@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/07 12:00:07 by ptelo-de          #+#    #+#              #
#    Updated: 2024/06/07 16:28:56 by ptelo-de         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap

SRC = src/main.c src/ft_error.c
OBJ = $(SRC:.c=.o)

CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

 all: $(NAME)

.c.o:
	${CC} -c $< -o ${<:.c=.o}

# %.o: %.c
#	$(CC) $(CFLAGS) -c $< -o $@
 
$(NAME): $(OBJ)
	${CC} ${FLAGS} ${OBJ} -o ${NAME} ${INCLUDE}
 
clean:
	$(RM) $(OBJ)
 
fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re