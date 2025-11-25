CC		:= cc
CFLAGS		:= -Wall -Wextra -Werror

NAME		:= push_swap

SRC		:= main.c \
		   log_push_ops.c \
		   log_rotate_ops.c \
		   log_rrotate_ops.c \
		   push_swap.c \
		   tinysort.c \
		   lst_ops.c \
		   swap_ops.c \
		   push_ops.c \
		   rot_ops.c

LIBFT_DIR	:= libft
LIBFT		:= $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME):
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(SRC) $(LIBFT)
