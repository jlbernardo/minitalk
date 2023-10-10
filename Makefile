# _*_ Makefile _*_

NAME_C = client
NAME_S = server

CC = cc
CFLAGS = -Werror -Wall -Wextra -g3
LIBFT = ./libft/libft.a

C_SRC = client.c
S_SRC = server.c
C_OBJ = $(C_SRC:.c=.o)
S_OBJ = $(S_SRC:.c=.o)
M_INC = -I minitalk.h

all: $(LIBFT) $(NAME_C) $(NAME_S)

$(NAME_C): $(C_OBJ)
	$(CC) $(CFLAGS) $(C_OBJ) $(M_INC) $(LIBFT) -o $(NAME_C)

$(NAME_S): $(S_OBJ)
	$(CC) $(CFLAGS) $(S_OBJ) $(M_INC) $(LIBFT) -o $(NAME_S)

$(LIBFT):
	make -C ./libft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: all

clean:
	make clean -C ./libft
	rm -f $(C_OBJ) $(B_OBJ)

fclean: clean
	rm -f $(LIBFT)
	rm -f $(NAME_C) $(NAME_S)

re: fclean all

.PHONY: all bonus clean fclean re