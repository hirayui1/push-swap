CC		:= cc
CFLAGS		:= -Wall -Wextra -Werror

NAME		:= push_swap

SRC		:= main.c \
		   log_push_ops.c \
		   log_rotate_ops.c \
		   log_rrotate_ops.c \
		   log_swap_ops.c \
		   assign_ops.c \
		   push_swap.c \
		   tinysort.c \
		   lst_ops.c \
		   lst_ops2.c \
		   swap_ops.c \
		   push_ops.c \
		   rot_ops.c \
		   valid_ops.c

LIBFT_DIR	:= libft
LIBFT		:= $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(SRC)
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(SRC) $(LIBFT) -o $(NAME)
