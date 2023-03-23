# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mshchuts <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/23 16:42:09 by mshchuts          #+#    #+#              #
#    Updated: 2023/03/23 16:42:13 by mshchuts         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

SRC = get_next_line.c get_next_line_utils.c 

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -c -Wall -Wextra -Werror

ARSR = ar -sr

REMOVE = rm -f

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) $(SRC)
		$(ARSR) $(NAME) $(OBJ)

clean: 
	$(REMOVE) $(OBJ)

fclean: 
	$(REMOVE) $(OBJ) $(NAME)
re: fclean all

.PHONY: clean fclean all re
