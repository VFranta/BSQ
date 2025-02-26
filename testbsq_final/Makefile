SRC_DIR = ./srcs/

HEAD_DIR = ./includes/

SCRS	= $(wildcard $(SRC_DIR)*.c)

HEAD = $(HEAD_DIR)ft.h

OBJS	= $(SCRS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror -I$(HEAD_DIR)

NAME	= bsq

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

$(SRC_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

.PHONY:		all clean fclean
