# _*_ Makefile _*_

NAME_C = client
NAME_S = server

CC = cc
CFLAGS = -Werror -Wall -Wextra -g3
LIBFT = ./libft/libft.a

M_SRC = $(addprefix mandatory_src/, client.c server.c)
B_SRC = $(addprefix bonus_src/, client_bonus.c server_bonus.c)
M_OBJ = $(M_SRC:.c=.o)
B_OBJ = $(B_SRC:.c=.o)
M_INC = -I mandatory_src/minitalk.h

all: $(LIBFT) $(NAME_C) $(NAME_S)

$(NAME_C): $(M_OBJ)
	$(CC) $(CFLAGS) mandatory_src/client.o $(M_INC) $(LIBFT) -o $(NAME_C)

$(NAME_S): $(M_OBJ)
	$(CC) $(CFLAGS) mandatory_src/server.o $(M_INC) $(LIBFT) -o $(NAME_S)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: all

$(LIBFT):
	make -C ./libft

clean:
	make clean -C ./libft
	rm -f $(M_OBJ) $(B_OBJ)

fclean: clean
	rm -f $(LIBFT)
	rm -f $(NAME_C) $(NAME_S)

re: fclean all

.PHONY: all bonus clean fclean re