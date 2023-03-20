NAME = get_next_line.a

SRC = get_next_line.c get_next_line_stuff.c 

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -c -Wall -Wextra -Werror -D BUFFER_SIZE=n

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