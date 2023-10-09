# _*_ Makefile _*_

NAME_C = client
NAME_S = server

CFLAGS = -Werror -Wall -Wextra -g3
LIBFT = ./libft/libft.a

C_SRC = client.c
S_SRC = server.c
C_OBJ = $(C_SRC:.c=.o)
S_OBJ = $(S_SRC:.c=.o)

all: $(NAME_C) $(NAME_S)

$(NAME_C): $(C_OBJ)
	cc $(CFLAGS) $(C_OBJ) -I minitalk.h $(LIBFT) -o $(NAME_C)

$(NAME_S): $(S_OBJ)
	cc $(CFLAGS) $(S_OBJ) -I minitalk.h $(LIBFT) -o $(NAME_S)

%.o: %.c
	cc $(CFLAGS) -c $< -o $@