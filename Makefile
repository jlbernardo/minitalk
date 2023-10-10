# _*_ Makefile _*_

NAME_C = client
NAME_S = server

CC = cc
CFLAGS = -Werror -Wall -Wextra -g3
LIBFT = ./libft/libft.a

M_SRC = client.c server.c
B_SRC = client_bonus.c server_bonus.c
M_OBJ = $(M_SRC:.c=.o)
B_OBJ = $(B_SRC:.c=.o)
M_INC = -I minitalk.h
B_INC = -I minitalk_bonus.h

all: $(LIBFT) $(MANDATORY)

$(MANDATORY): $(M_OBJ)
	$(CC) $(CFLAGS) client.o $(M_INC) $(LIBFT) -o $(NAME_C)
	$(CC) $(CFLAGS) server.o $(M_INC) $(LIBFT) -o $(NAME_S)

$(BONUS): $(B_OBJ)
	$(CC) $(CFLAGS) client_bonus.o $(B_INC) $(LIBFT) -o $(NAME_C)
	$(CC) $(CFLAGS) server_bonus.o $(B_INC) $(LIBFT) -o $(NAME_S)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(LIBFT) $(BONUS)

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