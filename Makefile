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

BSRC = get_next_line_bonus.c get_next_line_utils_bonus.c

OBJ = $(SRC:.c=.o)

BOBJ = $(BSRC:.c=.o)

CC = cc

CFLAGS = -c -Wall -Wextra -Werror

ARSR = ar -sr

REMOVE = rm -f

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) $(SRC)
		$(ARSR) $(NAME) $(OBJ)

bonus: $(BOBJ)
	$(ARSR) $(NAME) $?

clean: 
	$(REMOVE) $(OBJ) $(BOBJ)

fclean: 
	$(REMOVE) $(OBJ) $(BOBJ) $(NAME)

re: fclean all

.PHONY: clean fclean all re
